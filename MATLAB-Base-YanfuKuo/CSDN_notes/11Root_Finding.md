@[toc](方程式求根)
# 符号解
## 符号寻根`solve()`
在此之前有必要介绍一下符号变量`symbolic variables`
`syms var1 ... varN`：创建符号变量，以空格分隔不同的变量。
这是一种特殊的变量，以这种方式`syms x`声明的变量，matlab当作符号处理，通过此变量运算赋值所得`y=x^3+x`也是符号变量（`sym类型`）

#### 求解一般方程
`S = solve(eqn,var)`：解出关于变量var的方程eqn，如果不指定var，则由`symvar`函数决定要解的变量。`solve(x + 1 == 2, x)` 解出x的方程`x + 1 = 2`。
通过`solve()`求解出来的解也是sym类型，不是double类型的数值。
>+ `C = symvar(expr)` 搜索表达式 `expr`，查找除 `i、j、pi、inf、nan、eps` 和公共函数之外的标识符。这些标识符是表达式中变量的名称。`symvar` 返回搜索到的标识符。如果 `symvar` 找不到标识符，则 C 是一个空的元胞数组。
>+ 较新版本matlab**删除了对字符向量或字符串输入的支持**。**需要先使用 `syms` 来声明sym变量，然后将 `solve('2*x == 1','x')` 这样的输入替换为 `solve(2*x == 1,x)`** 。

![](https://img-blog.csdnimg.cn/20200810114952381.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
#### 求解方程组
还可以利用`solve()`求解方程组：
不过需要注意，如下图所示，求解结果赋值给A，此时A是一个结构体`struct`，包含x、y两个成员，通过`A.x/A.y`可以查看求解结果。
![](https://img-blog.csdnimg.cn/2020081014422721.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
#### 求解符号方程
`solve()`还可以用来求解用符号代替常数的方程。
`solve()`的第二个参数指定自变量（即要求解的对象），如图中第二例；若无指定则由`symval()`函数得出，如图中第一例：
![](https://img-blog.csdnimg.cn/20200810145213744.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
#### 符号函数求微分`diff()`
将变量声明为`sym类型`可以直接对其使用`diff()`函数，求解微分式。
`diff(g,x)`：指定g对x求导（若有多个自变量，则为求偏导）；
执行以下代码，`yprime`是一个`sym类型`值为`20*x^4`：
![](https://img-blog.csdnimg.cn/20200810155423845.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
#### 符号函数求积分`int()`
![](https://img-blog.csdnimg.cn/2020081017044268.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
利用`int()`函数，可以对符号函数求积分，常数项为0；
`subs(s,old,new)` 用 new 替换所有的 old ，然后计算此时 s的值并返回，但s本身还是原来的样子，没有改变。
<br>
## 符号解与数值解
|  |优点  | 缺点 |
|:--:|:--|:--|
| 符号解 |分析解决方案<br>让你直观的了解解决方案的形式  |可能过于复杂<br>有时无法解决问题|
|数值解|总是得到解决<br>能使解决方案准确无误<br>易于编码|难以提取更深层次的理解|
<br>
<br>

# 数值解
## `fsolve()`
`x = fsolve(fun,x0)`：从`x0`开始，尝试找出离`x0`最近的，方程`fun(x)=0`的根。
若x0为向量或矩阵，则分别给出离每一个元素最近的根，输出为和x0同大小的向量或矩阵。
给出函数`f(x)=0`在x=0附件的根：
![](https://img-blog.csdnimg.cn/20200810181350165.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
若要解方程组，需要先将方程组的方程放入一个函数中，然后通过`@functionname`获得handle。注意`fsolve()`的第二个参数表示寻根的起始点(初始值)，而不是每个方程对应的`=`右边的值(默认都为0)：
![](https://img-blog.csdnimg.cn/20200814204701272.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
可以不必单独创建一个函数文件，直接在script文件的最后加上function的整体结构就可以，如练习4。
>如果是多元方程组，似乎只能如上图所示，使用矩阵x来作为function的input，并用矩阵x的每一个元素来表示不同的自变量。当使用多个参数来作为input时，在`fsolve()`中通过函数handle调用该函数时总是会提示“输入参数的数目不足”。暂且按照图示方法作好了。

<br>

## `fzero()`
`x = fzero(fun,x0)`：从x0开始，尝试求出离x0最近的 fun(x) = 0 的解，此解是 fun(x) 变号的位置，即`f(x-),f(x+)`异号。fzero 无法求例如 x^2 这类函数的根。
若x0是一个向量[a,b]，则[a,b]即为寻根的范围：(注意与`fslove()`不同)
![](https://img-blog.csdnimg.cn/20200814193923709.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>

## 多项式寻根`roots()`
`r = roots(p)`：以列向量的形式返回 p 表示的多项式的根。输入 p 是一个包含 n+1 多项式系数的向量。
`roots()`只能用于多项式寻根。
![](https://img-blog.csdnimg.cn/20200814210314104.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>
<br>
# 习题
![](https://img-blog.csdnimg.cn/20200810151541969.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
```matlab
% 问题1
syms x y a b r;
f=(x-a)^2+(y-b)^2-r^2;
A=solve(f,x,y);
A.x	%查看求解出来的x
A.y	%查看求解出来的y 

% 问题2
syms a b c d;
A=[a b;c d];
B=inv(A);
```
>`Y = inv(X)` 计算方阵 X 的 逆矩阵，如果X是由sym类型元素组成的，也可以直接使用

<br>

![](https://img-blog.csdnimg.cn/20200810163026418.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70)
```matlab
close all;
clear all;
syms x y;
f=exp(x^2)/(x^3-x+3);
fprime=diff(f);         %默认对x求导

g=(x^2+x*y-1)/(y^3+x+3);
gprime=diff(g,x);       %指定对x求偏导
```
<br>

![](https://img-blog.csdnimg.cn/20200810171026376.png)

```
clear all;
close all;
%方法1，其实是近似算出具体数值
y=@(x) (x.^2-x+1)./(x+3);
z1=integral(y,0,10);
disp(z1);

%方法2，算出积分函数，再代入数据计算，最后的结果依然是sym类型
syms x;
y=(x.^2-x+1)./(x+3);
z2=int(y);
z2=subs(z2,x,10)-subs(z2,x,0);
disp(z2);
```
<br>

![](https://img-blog.csdnimg.cn/20200813180657707.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
```matlab
fun=@root2d;
%从(5,5)处开始寻根
x=fsolve(fun,[-5,-5]);
disp(x);

function F=root2d(x)
    F(1)=2*x(1)-x(2)-exp(-x(1));
    F(2)=-x(1)+2*x(2)-exp(-x(2));
end
```
<br>
<br>
<br>

以上内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：<https://www.bilibili.com/video/BV1DA411Y7bN>
课件下载：[MATLAB教程](https://download.csdn.net/download/weixin_45840825/12696065)
郭彦甫老师的YouTube主页：[@Yanfu Kuo](https://www.youtube.com/user/machinelearningandvi?pbjreload=101v)
原视频：<https://www.youtube.com/watch?v=KHFZLkm9qs0&t=8s>
