+ 视频直达：[C++内存管理机制](https://www.bilibili.com/video/BV1Er4y1A7Xy)
+ 课程讲义下载直达：[slide](slide/)
+ 源代码直达：[code](./code/)

----

候捷老师 C++ 系列课程导航：（编号顺序可作为学习顺序参考）

1. [C++面向对象高级编程（上）-基于对象和面向对象](../C++-OOPBase1-HouJie/)
2. [C++面向对象高级编程（下）-兼谈对象模型](../C++-OOPBase2-HouJie/)
3. [C++标准库(STL)与泛型编程](../C++-STL-HouJie/)
4. [C++新标准-C++11/14](../C++-newC++11&14-HouJie/)
5. C++内存管理
6. [C++Startup揭秘](https://github.com/19PDP/Bilibili-plus)

---

## 课程简介

内存（memory，台湾术语称为“記憶體”）是电脑中的“脑”吗？CPU才是脑，
CPU才是计算机的三魂六魄。但若没有内存，一切只存在于虚无缥缈间，等同
于不存在。

内存曾经是最宝贵也最昂贵的周边资源，现代程序员无法想像DOS时代对内存
的锱铢必较。

俱往矣，且看今朝。我们（似乎）有用不完的便宜内存。但表象之下是操作系统和
标准库做了大量工作。而如果你开发内存高耗软件，或处于内存受限环境下（例
如嵌入式系统），就有必要深刻了解操作系统和标准库为你所做的内存管理，甚
至需要自行管理内存。

本课程分为六讲：

**第一讲：Primitives**

C++语言中与内存相关的所有基础构件（constructs），包括malloc/free，new/delete，
operator new/operator delete，placement new/placement delete，我将探讨它们的意
义、运用方式和重载方式。并以此开发一个极小型内存池（memory pool）。

**第二讲：std:：allocator**

标准库的兴起，意味我们可以摆脱内存管理的繁复琐屑，直接使用容器。但是容
器背后的分配器（allocator）攸关容器的速度性能和空间性能。我将比较Visual C++，
Borland C++，GNU C++标准库中的allocator，并深入探索其中最精巧的GNU
C++ allocator的设计。

**第三讲：malloc/free**

malloc/free是所有内存管理手段的最后一哩；通过它才和操作系统搭上线。当然
你也可以直接调用system API，但不建议。因此理解malloc/free的内部管理至为
重要。我将以Visual C++的CRT（C RunTime Library）所带的malloc/free源代码
为基础，深度探索这最基础最关键的内存分配与释放函数。

**第四讲：loki::allocator**

即使知名如GNU C++ pool allocator，也有其小缺陷。Loki（一套作风前沿的程序
库）的allocator设计精简功能完整几无缺点，很值得我们深究。

**第五讲：其他主题**

除了std:：allocator，GNU C++还带不少allocators，它们不是标准库的一部分，
可视为标准库的扩充。我将探讨这些扩充的allocator，特别是bitmap allocator。

我们谈的不只是应用，还深入设计原理与实现手法。在理解了这么多底层
（Windows Heap，CRT malloc/free，C++ new/delete，C++ allocators）之后，也许你终
于恍然大悟，再不需要自行管理内存了；或也许你终于有能力想像，该在何处以
何种方式加强内存管理。

你将获得整个video课程的完整讲义（也就是video呈现的每一张投影片画面），
和一个完整程序包括代码文件.cpp和可执行文件.exe。你可以在视听过程中随时
停格仔细阅读讲义，细细咀嚼我所绘制的各种示意图和源代码之间的流动路
线——这的确很需要时间和脑力，却能令你脑洞大开。

> 侯捷简介：程序员，软件工程师，台湾工研院副研究员，教授。曾任教于中坜元
> 智大学、上海同济大学、南京大学。著有《无责任书评》三卷、《深入浅出MFC》、
> 《STL源码剖析》…，译有《Effective C++》《More Effective C++》《C++ Primer》
> 《The C++ Standard Library》…。

---

以下这份不算太细致的主题划分，协助您认识整个课程内容，以及在视听过程中正确翻找讲义。末尾的编号就是讲义的页码。

## 内存管理101–从平地到万丈高楼

主题划分

#### 第一讲：C++内存构件

Overview 1-10<br>
内存分配的每一层面 11<br>
四个基本层面的用法 12-14<br>
基本构件之一 new/delete expressions 15-17<br>
基本构件之二 array new/delete 18-21<br>
基本构件之三 placement new/delete 22<br>
基本构件之分配流程 23-24<br>
基本构件之重载 25-34<br>
Per-class allocator第一版本 35-36<br>
Per-class allocator第二版本 37-38<br>
Common static allocator（第三版本）39-41<br>
Macro allocator（第四版本）42-43<br>
GNU C++ allocator（第五版本）样貌44<br>
杂项讨论 45-48

#### 第二讲：std::allocator

内存块布局 52<br>
VC6 allocator 53<br>
BC5 allocator 54<br>
GNU allocator 55-60<br>
GNU allocator行为剖析 61-76<br>
GNU allocator源码剖析 77-87<br>
GNU allocator检讨 88-89<br>
GNU allocator监视 90-91<br>
GNU allocator移植到C语言 92

#### 第三讲：malloc/free

VC6和VC10的malloc比较 96-97<br>
Small Block Heap（SBH）初始化 98-99<br>
SBH行为分析–内存块大小之计算 100-104<br>
SBH行为分析–数据结构 105-107<br>
SBH行为分析–分配之详细图解 108<br>
SBH行为分析–分配+释放之连续动作图解 109-115<br>
SBH检讨 116-122

#### 第四讲：Loki:：allocator

上中下三个classes分析 127<br>
Loki::allocator行为图解 128-134<br>
class Chunk分析 135-137<br>
class FixedAllocator分析 138-140<br>
Loki::allocator检讨 141

#### 第五讲：Other Issues

GNU C++对allocators的描述 144-149<br>
VS2013标准分配器与new_allocator 150<br>
G4.9 标准分配器与new_allocator 151<br>
G4.9 malloc_allocator 152<br>
G4.9 array_allocator 153-155<br>
G4.9 debug_allocator 156<br>
G4.9 _pool_alloc 157-159<br>
G4.9 bitmap_allocator 160-170<br>
G4.9 使用G4.9分配器 171-172

-- the end