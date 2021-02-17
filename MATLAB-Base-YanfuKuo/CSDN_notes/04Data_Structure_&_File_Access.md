以下内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：[MATLAB基础教程-台大郭彦甫（14课全-高清-含课件）](https://www.bilibili.com/video/BV1DA411Y7bN)

-----------

# [变量类型](https://ww2.mathworks.cn/help/matlab/data-types.html)

![](https://i.loli.net/2021/01/27/uNdftW4ZAoaTEkh.png)

+ 如上图所示，对于 `int` 需要显示指出位数，没有普通的 `int` ，对于 `float` ，对应matlab中的是 `single`；
+ 默认情况下，matlab 将所有数值型的数据都存储为 double；
  如果希望以其他类型存储，需要显示指出：`x = int32(4)`；
+ 事实上，类似上述 [int32()](https://ww2.mathworks.cn/help/matlab/ref/int32.html) 这样显示指出类型本质上是一个函数，将数据类型转换；
  类似的还有 [uint32()](https://ww2.mathworks.cn/help/matlab/ref/uint32.html)、[double()](https://ww2.mathworks.cn/help/matlab/ref/double.html) 等，上图各类型都有对应的函数。
+ `x = 'c'` 像这样用单引号括起来一个字符，即为 char 类型

### [String](https://ww2.mathworks.cn/help/matlab/ref/string.html)

字符串实际上是个字符 array ，因此可对其进行矩阵操作：
![](https://i.loli.net/2021/01/27/iKWNan7pzoHhkDc.png)

+ `[s1 s2]` 直接将两个字符串相连；
+ `[s1; s2]` 理论上将并联形成两行矩阵，但该例中 s1 与 s2 行宽不等，会报错；
+ 逻辑运算符用于 string，与应用于矩阵效果一致：
  ![](https://i.loli.net/2021/01/27/mQHNpyS948Cblfi.png)

### [Struct](https://ww2.mathworks.cn/help/matlab/ref/struct.html)

struct 的声明，直接像下图一样赋值即可：
![image-20210127205220279](https://i.loli.net/2021/01/27/yHxkFn3pegEMTzP.png)

+ 声明一个 struct 数组则如此：
  ![image-20210127205003761](https://i.loli.net/2021/01/27/piZeFd2W6gyzjU5.png)

+ 嵌套 struct 如下图操作：
  注意data、nest...是 struct 的下级
  ![image-20210127205246319](https://i.loli.net/2021/01/27/PZCFrinQWXxHwmt.png)

### [cell](https://ww2.mathworks.cn/help/matlab/ref/cell.html)

存储异构数据的另一种方法，与矩阵相似，但每个条目包含不同类型的数据；
声明使用 `{}` ，如图两种方式均可：
![image-20210127205518872](https://i.loli.net/2021/01/27/5crKUx8znWMaHkj.png)

+ 使用 `C = {, , ; , , }` 创建一个 2×3 的 cell
  `,` 用来分隔 cell 中的列， `;` 用来分隔 cell 中的行
  ![image-20210127205720308](https://i.loli.net/2021/01/27/Nf1SXPl8hzdao9u.png)

+ 使用 `{}` 可以得到具体的矩阵或 string
  注意使用 `()` 和 `{}` 的区别
  ![image-20210127205751298](https://i.loli.net/2021/01/27/IVfJhKdqE4xGWek.png)
+ **[cell2struct()](https://ww2.mathworks.cn/help/matlab/ref/cell2struct.html) 通过 cell 数组中包含的信息创建一个结构体，重点了解！**
  [num2cell()](https://ww2.mathworks.cn/help/matlab/ref/num2cell.html) 将数组转换为相同大小的 cell
  [mat2cell()](https://ww2.mathworks.cn/help/matlab/ref/mat2cell.html) 指定行、列划分数组为 cell

### 多维数组

方法一：如图所示用 `{}` 加三个下标声明：
![image-20210127205932788](https://i.loli.net/2021/01/27/7neQFaHSf3PNuJV.png)

方法二：也可以使用 [cat()](https://ww2.mathworks.cn/help/matlab/ref/cat.html) 函数串联数组：
![image-20210127210040073](https://i.loli.net/2021/01/27/qCXmZA59hT7PKLJ.png)

+ 第一个参数为1：纵向串联，需要A、B两个矩阵行宽（列数）一致；
  第一个参数为2：横向串联，需要A、B两个矩阵列宽一致；
  第一个参数为3：前后三维串联，需要A、B两个矩阵行宽和列宽均一致；
+ 直接使用 `[A; B]` 与 `cat(1, A, B)` 效果一致；
  直接使用 `[A B]` 与 `cat(2, A, B)` 效果一致
+ [size()](https://ww2.mathworks.cn/help/matlab/ref/size.html) 可以给出矩阵长度
  `size(A, 1)`：第 1 维的长度，上图中 dim1 的宽度，即列宽；
  `size(A, 2)`：第 2 维的长度，dim2 的宽度，行宽；
  `size(A, 3)`：第 3 维的长度，dim3 的宽度
+ [reshape()](https://ww2.mathworks.cn/help/matlab/ref/reshape.html) 改变数组行列数：
  可以看出 matlab 是 按列优先 存储矩阵的
  ![image-20210127211922049](https://i.loli.net/2021/01/27/7HwUNjgF5exaAVX.png)
  ![image-20210127211939120](https://i.loli.net/2021/01/27/O1NZnwhPMDI8CJ7.png)

[isinteger()](https://ww2.mathworks.cn/help/matlab/ref/isinteger.html)、[isnan()](https://ww2.mathworks.cn/help/matlab/ref/isnan.html)、[iscell()](https://ww2.mathworks.cn/help/matlab/ref/iscell.html)、[isempty()](https://ww2.mathworks.cn/help/matlab/ref/isempty.html) 等方法，如他们的名字一样，用来核实变量类型。

# 数据存取

### [save()](https://ww2.mathworks.cn/help/matlab/ref/save.html) 和 [load()](https://ww2.mathworks.cn/help/matlab/ref/load.html)

![image-20210128162227444](https://i.loli.net/2021/01/28/f1BOSCler73IXv5.png)

+ 使用 `save mydata.mat` 储存
  使用 `load('mydata.mat')` 读取
+ `save mydata.mat` 将数据以 matlab 私有格式存取为二进制文件，其他文本编辑器如 notepad 无法读取文件内容，但matlab使用 `load()` 读取文件时将得到完整数据（包括变量名、数据内容等）
+ `save mydata.mat -ascii` 实际上将所有数据存储为一个矩阵，其他文本编辑器可以读取到文件内容，但 matlab 使用 `load()` 读取文件时将所有数据以一个矩阵形式存入一个 matrix 变量中（如果行列无法对齐的话 matlab 还会报错）
+ `mydata1.mat` 中存储的数据如红框所示，`load()` 正常读取；
  `mydata2.mat` 中存储数据与 `mydata1.mat` 中一致，但以 `-ascii` 形式存储，读取时因为行列无法对齐报错；
  `mydata3.mat` 中存储的是 `mydata1.mat` 中删除一个 1×2 的 vector `ans` 后的数据，以 `-ascii` 形式存储，`load()` 得到一个 8×4的矩阵。
  ![image-20210128163624676](https://i.loli.net/2021/01/28/mufT7BrFkCJKohX.png)
+ `save('pqfile.mat','p','q')` 或者 `save pqfile.mat p q` 将指定变量 `p`、`q` 保存到文件 `pdfile.mat` 中

### 向 Excel 中读写数据

关于 [xlsread()](https://ww2.mathworks.cn/help/matlab/ref/xlsread.html) 和 [xlswrite](https://ww2.mathworks.cn/help/matlab/ref/xlswrite.html)：从 R2019a 开始 matlab 建议不再使用，以新函数代替。经过比较，新函数确实更加好用，也支持更多的文件格式，下面介绍新函数。

### [xlsread()](https://ww2.mathworks.cn/help/matlab/ref/xlsread.html) 的替代品：[readmatrix()](https://ww2.mathworks.cn/help/matlab/ref/readmatrix.html) 和 [readcell()](https://ww2.mathworks.cn/help/matlab/ref/readcell.html)

[`readmatrix()`](https://ww2.mathworks.cn/help/matlab/ref/readmatrix.html)：将内容读取为一个 matrix
![image-20210128165111815](https://i.loli.net/2021/01/28/rPIvVLaEYks26BD.png)

+ [`readmatrix()`](https://ww2.mathworks.cn/help/matlab/ref/readmatrix.html) 只读取数据，如果指定范围内有其他内容（如 string 等），将直接跳过；
+ 格式：`M = readmatrix('filename.xlsx','Sheet','sheetname','Range','rangenumber')`
  也可以直接 `M = readmatrixd('filename.xlsx')` 读取文件中所有数据；
+ 如果要读取的文件不再matlab当前的工作路径下，则在 `filename` 中指定完整路径名；

[`readcell()` ](https://ww2.mathworks.cn/help/matlab/ref/readcell.html)：将内容读取为一个 cell
使用方法与 `readmatrix()` 一致，但 `readcell()` 不止读取数据，而是读取指定范围内所有内容，并以 cell 存储入变量 M

### [xlswrite()](https://ww2.mathworks.cn/help/matlab/ref/xlswrite.html) 的替代品：[writematrix()](https://ww2.mathworks.cn/help/matlab/ref/writematrix.html) 和 [writecell()](https://ww2.mathworks.cn/help/matlab/ref/writecell.html)

#### 使用 `writematrix()` 将矩阵写入 .txt 文档：

![image-20210128170138303](https://i.loli.net/2021/01/28/A8FVIsZ26aiprKJ.png)

+ 直接 `writematrix(M)` 则默认以逗号分隔各元素写入 M.txt 文件中；
+ 指定分隔符则使用 `writematrix(M, 'filename.txt', 'Delimiter', ' ')`；
  matlab 支持使用 ` `、`\t`、`,`、`;`、`|`（对应的字符名称为 `space`、`tab`、`comma`、`semi`、`bar`）作为分隔符

#### 使用 `writematrix()` 将矩阵写入 Excel 文档

`writematrix(M, 'M.xls')` 将矩阵 M 储存的数据写入表格 M.xls
`writematrix(M, 'M.xls', 'Sheet', 2, 'Range', 'A3:E8')` 规定范围写入指定表格，注意参数列表中 `sheet` 后的参数可以是表格名也可以是第 `x` 个表格
![image-20210128170828580](https://i.loli.net/2021/01/28/Czus25SpIAOyNRl.png)



使用 `writecell()` 将 cell 写入 Excel 文档，调用格式与 `writematrix()` 一致；

> 关键在于如何将数据与字符同时写入文档，我尝试过将数据矩阵和表头矩阵放入一个 cell 中，效果并不理想。matlab 在写入时，似乎将 cell 的一个单元放入一个格子中，这也就意味着如果要得到预期效果需要将每一个数据以及每一个表头都作为 cell 的一个单元存储，似乎比较麻烦。我尝试使用以下方法：

将横轴的表头以 1×n 的 cell 存入 `title1`：`title1 = {'day1', 'day2', 'day3', 'day4', 'day5', 'day6'}`；
将纵轴的表头以 n×1 的 cell 存入 `title2`：`title2 = {'mut1'; 'mut2'; 'mut3'; 'mut4'; 'mut5'; 'mut6'}`；
再利用 `writecell()` 写入指定位置即可：
![image-20210128172200636](https://i.loli.net/2021/01/28/k8BT9FDwbUJVmLg.png)
该代码完整写入了表头和数据，效果如下：
![image-20210128172244897](https://i.loli.net/2021/01/28/OZubwSKGMyXAaRs.png)

### 低阶文件处理 I/O 函数

无论是写入还是读取都要先获得 `file id`，即通过 [fopen()](https://ww2.mathworks.cn/help/matlab/ref/fopen.html) 函数返回值获得；
写入时，`fopen()` 函数的 `permission` 参数处为 `w`，读取时为 `r`；
操作完毕后务必使用 [fclose(fid)](https://ww2.mathworks.cn/help/matlab/ref/fclose.html) 函数关闭文件，否则 matlab 将一直占用文件；
![image-20210128172544801](https://i.loli.net/2021/01/28/hvjTHy1rAYLgoJI.png)
![image-20210128172559984](https://i.loli.net/2021/01/28/HPRgb13xjqkATEa.png)
![image-20210128172613821](https://i.loli.net/2021/01/28/9LWbGjxYuIfs2BV.png)

`feof(fid)` 检查是否到达文件结尾，到达结尾返回 `true`：
![image-20210128172647143](https://i.loli.net/2021/01/28/jd4Aqr1BmTsVMOo.png)



# 练习

![image-20210128173059248](https://i.loli.net/2021/01/28/21maHwCfnlteQoW.png)

```matlab
s1 = 'I like the letter E';
s2 = s1(size(s1, 2):-1:1) %从s1的最后一个字符向前一个一个拷贝给s2

s3 = reverse(s1) %直接使用函数
```



![image-20210128174159435](https://i.loli.net/2021/01/28/f8JmNQRnhzWsGPO.png)

```matlab
B(1,1)={'This is the first cell'};
B(1,2)={[5+6j 4+5j]};
B(2,1)={[1 2 3; 4 5 6; 7 8 9]};
B(2,2)={[{'Tim'}, {'Chris'}]};
B
```

