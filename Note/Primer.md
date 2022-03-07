## 类

#### 隐式的类类型转换

**如果构造函数只接受一个实参，则它实际上定义了转换为此类类型的隐式转换机制。**

- 只允许一步类类型转换；
- 将构造函数声明为 **`explicit`** 可以阻止隐式转换。

```cpp
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) { }
    explicit Sales_data(std::istream&);
    
    void combine(Sales_data s) {...}
}
// 只能在类内声明构造函数时使用 explicit，在类外定义时不应重复
Sales_data::Sales_data(istream& is){
    // ...
}

Sales_data item;
item.combine("9-999"); // 错误，需要两步转换。先将 const char* 转换为 string，
					   // 再把这个临时的 string 转换为 Sales_data
item.combine(string("9-999")); // 正确，显示地转换成 string，隐式地转换成 Sales_data
Sales_data item2 = string("9-999"); // 当执行拷贝形式初始化时也是隐式转换
```



## 拷贝控制

#### 行为像值的类和行为像指针的类

行为像值的类正如标准库对于 string 的实现：

- 拷贝构造函数，完成 string 的拷贝，而不是拷贝指针；

- 析构函数释放 string；

- 拷贝赋值运算符**释放对象当前的 string**，并**从右侧运算对象拷贝 string**。

  ```cpp
  inline
  String& String::operator=(const String& str){
    	if(this == &str) // 检测自我赋值
        	return *this;
    	
    	delete[] m_data; // 第一步 释放当前的 string
    	m_data = new char[ strlen(str.m_data) + 1 ]; // 第二步
    	strcpy(m_data, str.m_data); // 第三步 拷贝右侧的 string
    	return *this;
  }
  ```

行为像指针的类，不同的对象共用同一份数据：

- 使用一个引用计数，来记录有多少对象与正在创建的对象共享数据；
- 拷贝构造和拷贝赋值，拷贝指针成员，而不是它指向的 string；同时递增共享的计数器；
- 析构函数递减计数器，变为 0 时，则真正的“析构”；
- 拷贝赋值运算符递增右侧运算对象的计数器，递减左侧运算对象的计数器。

```cpp
class HasPtr {
public:
	// 构造函数分配新的 string 和新的计数器，并置为1
    // 共享计数器也保存在动态内存中，以使不同的对象共享
    HasPtr(const std::string &s = std::string()): 
	  ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	// 拷贝构造函数拷贝数据成员，并递增计数器
    HasPtr(const HasPtr &p): 
		ps(p.ps), i(p.i), use(p.use) { ++*use; }

	HasPtr& operator=(const HasPtr&){
        if (this != &rhs) {
            if (--*use == 0) {   // do the work of the destructor
                delete ps;
                delete use;
            }
            ps = rhs.ps;         // do the work of the move constructor
            i = rhs.i;
            use = rhs.use;
            ps = 0; use = 0;
        }
        return *this;
    }
    
    ~HasPtr(){
        if (--*use == 0) {   // if the reference count goes to 0
            delete ps;       // delete the string
            delete use;      // and the counter
        }
    }
private:
    std::string *ps;
    int    i;
	std::size_t *use;  // member to track how many objects share *ps
};
```

## 重载运算
#### 成员函数或非成员函数
- `=` , `[]`, `()`, `->` 必须是成员；
- 符合赋值运算符一般应该是成员，但并非必须；
- 改变对象状态或与给定类型密切相关的运算符，如递增、递减和解引用，通常应该是成员。
- **具有对称性的运算符可能转换任意一端的运算对象，如算数、相等性、关系和位运算符，通常应该是普通的非成员函数。**

```cpp
string s = "world";
string t = s + "!"; // 正确：我们能把一个 const char* 加到一个 string 对象中，执行了隐式的类类型转换。
string u = "hi" + s; // 如果 + 是 string 的成员函数，则产生错误
```
如果 `operator+` 是 string 类的成员，则上面第一个加法等价于 `s.operator+("!")`。 同样的，第二个加法等价于 `"hi".operator+(s)`，显然 "hi" 的类型是 const char* 是一种内置类型，根本没有成员函数。

如果 string 将 + 定义为非成员函数，则 `"hi"+s`等价于 `operator+("hi", s)`，和任何其他函数调用一样，每个实参都能被转换成形参类型，**唯一的要求是至少有一个运算对象是类类型。**