+ 课程讲义下载直达：[slide](slide/)
+ 源代码直达：[code](code/)

----

候捷老师 C++ 系列课程导航：

+ C++面向对象高级编程（上）-基于对象
+ [C++面向对象高级编程（下）-兼谈对象模型](../C++-OOPBase2-HouJie/)



---

## 課程簡介

這是侯捷老师的所有 C++技術課程中最基礎最根本的一門課。

C++可說是第一個高度普及的 Object-Oriented (面向對象) 編程語言。”第一個”
或 “最早的” 並非重點，重點是經過多年的淬煉和考驗 C++的影響深入各層面，
擁有眾多使用者和極其豐富的資源 (書籍、論文、期刊、視頻、第三方程序庫…)。

作為 Object-Oriented (面向對象) 技術的主流語言，C++ 其實還擁有另一支編程
主線：模板與泛型編程 (Templates and Generic Programming)。

本課程涵蓋上述兩條主線：Object-Oriented (面向對象) 和泛型編程 (Generic
Programming)。

由於視頻錄製時程的因素，本課程分為 Part I 和 Part II.
Part I 主要討論 OO (面向對象) 的基礎概念和編程手法。基礎最是重要，勿在浮
沙築高台，我著重的是大器與大氣。課程首先探討 Class without pointer members
和 Class with pointer members 兩大類型，而後晉昇至 OOP/OOD，包括 classes 之
間最重要的三種關係：繼承(Inheritance)、複合(Composition)、委託(Delegation)。
Part II 繼續探討更多相關主題，並加上低階的對象模型 (Object Model)，以及高
階的 Templates (模板) 編程。

本課程所談主題都隸屬 C++1.0 (C++98)；至於 C++ 2.0 (C++11/14) 帶來的嶄新
內容則由我的另一門課程涵蓋。C++2.0 在語言和標準庫兩方面都帶來了很多新
事物，份量足以形成另一門課程。

你將獲得整個 video 課程的完整講義 (也就是 video 呈現的每一張投影片畫面)，
和完整的示例程序。你可以 (也必要) 在視聽過程中隨時停格思考和閱讀講義。

侯捷簡介：程序員，軟件工程師，臺灣工研院副研究員，教授，專欄主筆。曾任
教於中壢元智大學、上海同濟大學、南京大學。著有《無責任書評》三卷、《深
入淺出 MFC》、《STL 源碼剖析》…，譯有《Effective C++》《More Effective C++》
《C++ Primer》《The C++ Standard Library》…

---

以下这份不太细致的主题划分，帮助您认识整个课程内容。

## C++面向對象編程 (C++Object-Oriented Programming)

### Part I

**Introduction of C++98, TR1, C++11, C++14**<br>
&emsp;Bibliography<br>
&emsp;Data and Functions, from C to C++<br>
&emsp;Basic forms of C++ programs<br>
&emsp;About output<br>
&emsp;Guard declarations of header files<br>
&emsp;Layout of headers<br>
&emsp;Object Based<br>
&emsp;Class without pointer member<br>
&emsp;&emsp;Class declarations<br>
&emsp;&emsp;Class template, introductions and overviews<br>
&emsp;&emsp;What is 'this'<br>
&emsp;&emsp;Inline functions<br>
&emsp;&emsp;Access levels<br>
&emsp;&emsp;Constructor (ctor)<br>
&emsp;&emsp;Const member functions<br>
&emsp;&emsp;Parameters : pass by value vs. pass by reference<br>
&emsp;&emsp;Return values : return by value vs. return by reference<br>
&emsp;&emsp;Friend<br>
&emsp;&emsp;Definitions outside class body<br>
&emsp;&emsp;Operator overloading, as member function<br>
&emsp;&emsp;Return by reference, again<br>
&emsp;&emsp;Operator overloading, as non-member function<br>
&emsp;&emsp;Temporary objects<br>
&emsp;&emsp;Expertise<br>
&emsp;&emsp;Code demonstration<br>
&emsp;class with pointer members<br>
&emsp;&emsp;The "Big Three"<br>
&emsp;&emsp;&emsp;Copy Constructor<br>
&emsp;&emsp;&emsp;Copy Assignment Operator<br>
&emsp;&emsp;&emsp;Destructor<br>
&emsp;&emsp;Ctor and Dtor, in our String class<br>
&emsp;&emsp;"MUST HAVE" in our String class<br>
&emsp;&emsp;&emsp;Copy Constructor<br>
&emsp;&emsp;&emsp;Copy assignment operator<br>
&emsp;&emsp;Deal with "self assignment"<br>
&emsp;&emsp;Another way to deal with "self assignment" : Copy and Swap<br>
&emsp;&emsp;Overloading output operator (<<)<br>
&emsp;&emsp;Expertise<br>
&emsp;&emsp;Code demonstration<br>
&emsp;Objects from stack vs. objects from heap<br>
&emsp;&emsp;Objects lifetime<br>
&emsp;&emsp;new expression : allocate memory and then invoke ctor<br>
&emsp;&emsp;delete expression : invoke dtor and then free memory<br>
&emsp;&emsp;Anatomy of memory blocks from heap<br>
&emsp;&emsp;Allocate an array dynamically<br>
&emsp;&emsp;new[] and delete[]<br>
&emsp;MORE ISSUES :<br>
&emsp;&emsp;static<br>
&emsp;&emsp;private ctors<br>
&emsp;&emsp;cout<br>
&emsp;&emsp;Class template<br>
&emsp;&emsp;Function template<br>
&emsp;&emsp;namespace<br>
&emsp;&emsp;Standard Library : Introductions and Overviews<br>
&emsp;Object Oriented<br>
&emsp;&emsp;Composition means "has-a"<br>
&emsp;&emsp;&emsp;Construction : from inside to outside<br>
&emsp;&emsp;&emsp;Destruction : from outside to inside<br>
&emsp;&emsp;Delegation means "Composition by reference"<br>
&emsp;&emsp;Inheritance means "is-a"<br>
&emsp;&emsp;&emsp;Construction : from inside to outside<br>
&emsp;&emsp;&emsp;Destruction : from outside to inside<br>
&emsp;&emsp;Construction and Destruction, when Inheritance+Composition<br>
&emsp;&emsp;Inheritance with virtual functions<br>
&emsp;&emsp;Virtual functions typical usage 1 : Template Method<br>
&emsp;&emsp;Virtual functions typical usage 2 : Polymorphism<br>
&emsp;&emsp;Virtual functions inside out : vptr, vtbl, and dynamic binding<br>
&emsp;&emsp;Delegation + Inheritance : Observer<br>
&emsp;&emsp;Delegation + Inheritance : Composite<br>
&emsp;&emsp;Delegation + Inheritance : Prototype<br>

### Part II

**緒論**
Conversion function (轉換函數)<br>
Non-explicit one-argument constructor<br>
Pointer-like classes, 關於智能指針<br>
Pointer-like classes, 關於迭代器<br>
Function-like classes, 所謂仿函數<br>
標準庫中的仿函數的奇特模樣<br>
namespace 經驗談<br>
class template, 類模板<br>
function template, 函數模板<br>
member template, 成員模板<br>
specialization, 模板特化<br>
partial specialization, 模板偏特化 —— 個數的偏<br>
partial specialization, 模板偏特化 —— 範圍的偏<br>
template template parameter, 模板模板參數<br>
variadic templates (since C++11)<br>
auto (since C++11)<br>
ranged-base for (since C++11)<br>
reference<br>
Composition (複合) 關係下的構造和析構<br>
Inheritance (繼承) 關係下的構造和析構<br>
Inheritance+Composition 關係下的構造和析構<br>
對象模型 (Object Model) ：關於 vptr 和 vtbl<br>
對象模型 (Object Model) ：關於 this<br>
對象模型 (Object Model) ：關於 Dynamic Binding<br>
談談 const<br>
關於 new, delete<br>
重載 ::operator new, ::operator delete<br>
重載 ::operator new[], ::operator delete[]<br>
重載 member operator new/delete<br>
重載 member operator new[]/delete[]<br>
示例<br>
重載 new(), delete()<br>
示例<br>
basic_string 使用 new(extra) 擴充申請量<br>
-- the end

