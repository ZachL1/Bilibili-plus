# STL 与泛型编程

> STL 就是泛型编程的最好示例。

通过泛型编程使用 C++ 标准库的 6 大部件。

6 大部件 (Components) ：

- 容器 Containers
- 分配器 Allocators ：容器通常都有默认的分配器，因此不需要使用者操心。
- 算法 Algorithms
- 迭代器 Iterators
- 适配器 Adapters
- 仿函数 Functors

![image-20220209155637692](images/image-20220209155637692.png)

### 容器 - 结构与分类

- 顺序容器：数组或链表实现
- 关联容器
  - 有序：红黑树实现
  - 无序：哈希表实现（一组桶） *C++11*

![image-20220209162214117](images/image-20220209162214117.png)

> 红框标注的为 C++11 新增容器，其中 array 是将原本的语言特显变为 array class
>
> vector 的扩充通过“分配器”实现，分配器完成底层的内存分配工作

##### vector 对象是如何增长的

TODO

> 参看 *《C++ Primer》* p317

##### deque 对象是如何增长的

deque 对象中其实是一连串的指针，每一个指针指向一个 buffer 。buffer 具有固定的长度，能容纳 n 个元素，当 deque 向前或向后增长时首先填充 buffer 内空闲的内存，当 buffer 满了之后再分配新的 buffer。

![image-20220209174417698](images/image-20220209174417698.png)

> **stack 和 queue 实际上是 deque 容器的适配器**，底层就是一个 deque ，各种操作是对 deque 容器的操作的再次封装。

### 源代码之分布

