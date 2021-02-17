以下内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：[MATLAB基础教程-台大郭彦甫（14课全-高清-含课件）](https://www.bilibili.com/video/BV1DA411Y7bN)

-----------

## 数字图像简述

![image-20210131115053887](https://i.loli.net/2021/01/31/xuIgU9fZVKGFOhn.png)

+ 数字图像大概可以分为如上图所示的三类：彩色、灰阶、黑白；
+ 计算机存储图像时，实际上当作一个矩阵来存储，简单来说，矩阵的大小即为图片的像素大小；
+ 对于最简单的黑白图像，是一个二维 01 矩阵，图片的每一个像素点对应一个数值，黑色为0，白色为1；
  对于灰阶图像，是一个二维矩阵，每一个像素点对应的数值为 `uint8` 类型，即 0~255；越白数值越大；
  对于彩色图像，可以简单地理解为三个灰阶矩阵叠加成的一个三维矩阵，其每一个灰阶矩阵分别对应 R G B；这样每一个像素点对应三个数值，叠加得到该像素点的颜色；
+ MATLAB 对于图片的处理实际上就是对这样的矩阵做各种运算；

## 图像准备

+ [A = imread(filename)](https://ww2.mathworks.cn/help/matlab/ref/imread.html) 读取图像并存入变量 `A`，`A` 实际上是一个矩阵，其内容如前所述；
+ [imshow(A)](https://ww2.mathworks.cn/help/matlab/ref/imshow.html) 显示 `A` 中存有的图像；
+ [imageinfo(filename)](https://ww2.mathworks.cn/help/images/ref/imageinfo.html) 一个工具箱，用于查看图像的各种信息；
+ [imtool(filename)](https://ww2.mathworks.cn/help/images/ref/imtool.html) `imtool(A)` 一个图像处理工具箱，常用它查看图像的像素点信息（即矩阵中元素的值）；
+ [imwrite(I, 'newImage.png')](https://ww2.mathworks.cn/help/matlab/ref/imwrite.html) 将处理后的图片 `I` 存入文件

## 图像算法

### 图像乘法

![image-20210131161933165](https://i.loli.net/2021/01/31/ETqs6mijaNBLzFJ.png)

+ [Z = immultiply(X, Y)](https://ww2.mathworks.cn/help/images/ref/immultiply.html) 将图像 `X` 乘以 `Y`；
+ 如果`Y` 是常数，则`X`每一个元素值乘以Y；比如上图将图片乘以 1.5 变得更亮；要变得更暗则乘以小于 1 的数；
+ 如果`Y` 是图片（矩阵），则必须是和`X`等大小的图片，两个矩阵做点乘；
+ [Z = imdivide(X, Y)](https://ww2.mathworks.cn/help/images/ref/imdivide.html) 与矩阵乘法对应的矩阵除法

### 图像加法

![image-20210131162652324](https://i.loli.net/2021/01/31/f6lO4STRo7hvGPW.png)

+ [Z = imadd(X, Y)](https://ww2.mathworks.cn/help/images/ref/imadd.html) 将图像 `X` 加上 `Y`；
+ 如果`Y` 是常数，则`X`每一个元素值加上 Y；
+ 如果`Y` 是图片（矩阵），则必须是和`X`等大小的图片，两个矩阵做加法；比如上图将两个图片相加；
+ [Z = imsubtract(X, Y)](https://ww2.mathworks.cn/help/images/ref/imsubtract.html) 与图像加法对应的图像减法

> 图像的加减乘除可能会出现超出 `uint8` 的范围，matlab不会发生溢出之类的现象，而是对于超过255的结果其值即为255；对于小于0的结果其值即为0；
>
> 对图像的处理实际上就是对矩阵的运算，因此 `Z = X.*Y` `Z = X+Y` 可以达到一样的效果，matlab只是将其封装成了如上述的函数而非魔法；（包括后续一系列函数也是这样）

### 图像直方图

![image-20210131163813610](https://i.loli.net/2021/01/31/oCt4RHP35rOkGZ6.png)

+ [imhist(I)](https://ww2.mathworks.cn/help/images/ref/imhist.html) 画出图像 `I` 的色阶直方图（实际上是图像矩阵元素数值的直方图），只使用于灰阶图像；
+ `[cunts, bin] = imhist(I)` 返回直方图 x 轴的索引 `bin` 和对应的直方图高度(个数) `cunts`；
+ [histeq(I)](https://ww2.mathworks.cn/help/images/ref/imsteq.html) 使图像直方图分布均匀，即增强图像的对比度；
  ![image-20210131165122516](https://i.loli.net/2021/01/31/vfK29GeE16RCygD.png)

### 图像几何变换

图像的几何变换实质上是将图像矩阵与某一变换矩阵做矩阵乘法：
![image-20210131170822398](https://i.loli.net/2021/01/31/USFw14He7oxYGdZ.png)

### 图像旋转

![image-20210131171407341](https://i.loli.net/2021/01/31/5i8rHmqCeRhpnZg.png)

+ [J = imrotate(I,angle,method)](https://ww2.mathworks.cn/help/images/ref/imrotate.html) 将图片旋转 `angle` 度，参数 `method` 指出使用的插值方法；

### 补充几个函数

| 函数                                                         | 作用                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Z = imabsdiff(X, Y)](https://ww2.mathworks.cn/help/images/ref/imabsdiff.html) | 两个图像的绝对差，返回差的绝对值(注意和`imsubtract`的区别)   |
| [imapplymatrix](https://ww2.mathworks.cn/help/images/ref/imapplymatrix.html) | 对彩色图像的 RGB 对应的三个值线性组合(即赋不同权重组合)，得到灰阶图像； |
| [imcomplement](https://ww2.mathworks.cn/help/images/ref/imcomplement.html) | 计算图像的补图，即将颜色反转                                 |
| [imlincomb](https://ww2.mathworks.cn/help/images/ref/imlincomb.html) | 将多张图片线性组合(即按照不同的权重叠加)                     |

# 练习

![](https://i.loli.net/2021/01/31/HF7MOQsJA5fSyaW.png)

```matlab
I = imread('rice.png');
subplot(131)
imshow(I)
J = immultiply(I, 2); % 增强亮度
subplot(132)
imshow(J)
J = histeq(J); % 再增强对比度
subplot(133)
imshow(J)
```

![image-20210131181644511](https://i.loli.net/2021/01/31/Rm5kgN4ZpIWEUMc.png)

```matlab
I = imread('rice.png');
subplot(131); imshow(I)
J = immultiply(I, 2); % 增强亮度
subplot(132); imshow(J)
J = histeq(J); % 再增强对比度
subplot(133); imshow(J)

figure
subplot(121); imhist(I) % 原图的histogram
subplot(122); imhist(J) % 增强亮度和对比度后的histogram
```

