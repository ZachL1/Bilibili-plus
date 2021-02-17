以下内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：[MATLAB基础教程-台大郭彦甫（14课全-高清-含课件）](https://www.bilibili.com/video/BV1DA411Y7bN)

-----------
# [脚本编写](https://ww2.mathworks.cn/help/matlab/learn_matlab/scripts.html)

`%%`将整个脚本文件分为若干“节”，可以选择“运行当前节”来执行某部分代码，方便`debug`：
![](https://img-blog.csdnimg.cn/img_convert/4b7442c2566b6ef2c8aa30d02574f983.png)

也可以添加断点`debug`，此时鼠标悬停于变量上可以查看该变量详细信息：![](https://img-blog.csdnimg.cn/img_convert/7ce57d20cd90d77dc6e6b947f79bb73f.png)
<br>

# 结构化程序设计

### [逻辑运算符](https://ww2.mathworks.cn/help/matlab/logical-operations.html)

matlab中的不等于：`~=`
其他均与c一致：![](https://img-blog.csdnimg.cn/img_convert/a1b0642b6fea36f81caca36bd2ba693a.png)

### 控制语句

注意matlab中[if-else](https://ww2.mathworks.cn/help/matlab/ref/if.html)、[for](https://ww2.mathworks.cn/help/matlab/ref/for.html)、[while](https://ww2.mathworks.cn/help/matlab/ref/while.html)、[switch](https://ww2.mathworks.cn/help/matlab/ref/switch.html)...均需要以`end`结尾
![](https://img-blog.csdnimg.cn/img_convert/b5bd71f6749ea7602f1eb3b77cf3dd13.png)

+ matlab中`switch`语句与c不一样，不需要 [break](https://ww2.mathworks.cn/help/matlab/ref/break.html) 跳出，不会逐一执行每一条。
+ [otherwise](https://ww2.mathworks.cn/help/matlab/ref/otherwise.html) ：相当于`defult`
+ `break`语句会结束`for`或`while`循环的执行，但不结束`switch`语句的执行。
![](https://i.loli.net/2021/01/27/I17lqMC3ybaJHir.png)
### 为变量预分配空间
如果未预分配空间（如前面script中第一节），matlab会在每次迭代时调整其大小，会比较费时间：
![](https://img-blog.csdnimg.cn/img_convert/3d582f15a49e4c1da6c2f48e962af1b1.png)

+ `tic-toc`可以用于计时。
### Script 小技巧
![](https://img-blog.csdnimg.cn/img_convert/1f841645ee6e0093bb5288865ea8fa66.png)
+ 在脚本开头，使用下列 `command`：
`clear all` ：删除以前的变量
`close all` ：关闭所有的图形
+ 使用省略号使脚本更具可读性（添加`...`来换行）
+ 按`Ctrl+C`提前结束运行
<br>
# 自定义函数

### [function 编写](https://ww2.mathworks.cn/help/matlab/ref/function.html)

像这样定义一个 无参、无返回值 的函数：
![](https://i.loli.net/2021/01/27/A4hkpTYfSbyMzE8.png)

+ 函数以关键字 `function` 开始，以 `end` 结尾；
+ 函数一般保存为单独文件，函数名 必须和 文件名一致；
  函数文件与脚本文件都为 `.m` 文件；
+ 也可将临时使用的函数定义在脚本文件内，但需要定义在文件最后；
+ 输入函数 [`input()`](https://ww2.mathworks.cn/help/matlab/ref/input.html)；
  输出可以用 [`disp()`](https://ww2.mathworks.cn/help/matlab/ref/disp.html) 或者 [`fprintf()`](https://ww2.mathworks.cn/help/matlab/ref/fprintf.html)——与c语言的 `printf` 使用基本一致，但需要注意 matlab 中对于字符串均使用 `''` 而不是 `""` ，`fprintf()` 中的内容使用 `''`括起来；

像这样定义一个 多参、多返回值 的函数（多输入输出）：
![](https://i.loli.net/2021/01/27/NVdPfQgHxju6Llb.png)

+ 注意在函数体中并不需要明示 `return` ，只需要在返回列表中写出对应的变量名就行，matlab会帮你做好一切；
+ 要在调用函数时接收返回值，使用类似 `[Acc Force]` 这样的变量矩阵来接收，函数将分别返回对应的值；使用 `[~, Force]` 来接收部分返回值；

### [Function Handles](https://ww2.mathworks.cn/help/matlab/ref/function_handle.html)

![](https://i.loli.net/2021/01/27/BUbKM6GZFW3Irgc.png)

一种创建匿名函数的方法，即不必在 `.m` 文件中定义的单行表达式函数。
function handles 其实是一个 pointer，它使 `f` 指向函数 `exp(-2*x)` ；`f` 的输入在 `@(x)` 处，此处的 x 则将成为函数 exp 的输入参数。

# 练习

![](https://i.loli.net/2021/01/27/XYzrRsopQPeD3bZ.png)
```matlab
sum = 0; % 设置初始值为0
i=1;
while i <= 999
    sum = sum + i;
    i = i+1;
end
fprintf('和为：%d\n', sum);
```



![](https://i.loli.net/2021/01/27/IUNP9t1cQHKwzSj.png)

```matlab
%% 方法一：普通的遍历
A = [0  -1  4
     9 -14 25
    -34 49 64]
B = zeros(size(A)); %生成一个和A同样大小的全零矩阵
for i=1:size(A, 1)  %遍历数组A
    for j=1:size(A, 2)
        if(A(i,j) < 0)
            B(i,j)=1; % 下标置为1表示数组A对应的元素为负
            A(i,j)=0; % 负的项置为0
        end
    end
end

%% 方法二：矩阵思想
A = [0  -1  4
     9 -14 25
    -34 49 64]
B = A < 0 %返回一个零一矩阵，数组A中元素小于0的对应位置为1
A(B) = 0 %将数组B指定位置值置为0
```

请务必好好思考方法二，并运行一遍看看结果。
MATLAB 的全称是 Matrix Laboratory（矩阵实验室），以矩阵的思维来利用matlab往往能事半功倍！



![](https://i.loli.net/2021/01/27/D2bfHnugFvkPydV.png)

```matlab
% 以下所有内容可以保存在一个脚本文件中
% 或者也可以将函数单独保存在 F2C.m 文件中
F = input('请输入华氏温度：');
while(F) % 检查是否有输入
    fprintf('摄氏温度为：%f\n', F2C(F));
    
    F = input('请继续输入华氏温度：(输入空行结束)');
end

function C = F2C(F)
    C = (F-32).*5./9;
end
```

