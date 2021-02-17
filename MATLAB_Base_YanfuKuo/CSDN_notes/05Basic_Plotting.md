以下内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：[MATLAB基础教程-台大郭彦甫（14课全-高清-含课件）](https://www.bilibili.com/video/BV1DA411Y7bN)

-----------

# 基础绘图

### [plot()](https://ww2.mathworks.cn/help/matlab/ref/plot.html) 基本使用

![image-20210128181159657](https://i.loli.net/2021/01/28/1GpfxJS7NDHv2gl.png)

+ `plot(x,y)`：如果 X 和 Y 都是向量，则它们的长度必须相同，plot 函数绘制 Y 对 X 的图；
+  如果 X 和 Y 均为矩阵，则它们的大小必须相同，plot 函数绘制 Y 的列对 X 的列的图（即矩阵X的第1列的数据记为一个vector：x1，Y的第一列记为一个vector：y1，plot(x1, y2)，第2, 3, 4…列类似。将对应的每一列绘制成一个单独的线条）。如：
  ![image-20210128181737627](https://i.loli.net/2021/01/28/yQYUG1lXg3dPmef.png)
+ 如果 X 或 Y 中的一个是向量而另一个是矩阵，则矩阵的各维中必须有一维与向量的长度相等。如果矩阵的列宽等于向量长度，则 plot 函数绘制矩阵中的每一列对向量的图。**如果矩阵的行宽等于向量长度，则该函数绘制矩阵中的每一行对向量的图。**如果矩阵为方阵，则该函数绘制每一列对向量的图。
  通常都会使矩阵的行宽等于向量长度，从而一次画多图，如：
  ![image-20210128182535419](https://i.loli.net/2021/01/28/4HelIStzgK7MbjZ.png)
+ `plot(x, y1, x, y2)`：同时画两条线；
  `plot(y)`：分别以x=1,2,3….对应于y的第1,2,3…个数值描点连线（即自动为y配置x坐标）；
+ 使用 `hold on` 保持上一次画图，使用 `hold off` 来关闭此功能， 不使用 `hold off` 画图将一直存在
  ![image-20210128194715807](https://i.loli.net/2021/01/28/m3O5qlWVP6LIKd9.png)

### plot() 描点、连线

+ `plot(X,Y,LineSpec)` 设置线型、标记符号和颜色
  `LIneSpec` 的内容可以包含三个参数，~~第一个表示颜色，第二个表示连线的类型，第三个表示描点的类型（误）~~，事实上这三个参数的顺序无关紧要；
  `plot(x,y,'b--o')` 即表示使用蓝色虚线，带圆形标记画图；
  各类型对应表示如下：
  ![image-20210128195116498](https://i.loli.net/2021/01/28/Op9L2qEszNTMdYR.png)
+ `plot(X1,Y1,LineSpec1,...,Xn,Yn,LineSpecn)` 设置每个线条的线型、标记符号和颜色. 可以混用 X、Y、LineSpec 三元组和 X、Y 对组：例如 `plot(X1,Y1,X2,Y2,LineSpec2,X3,Y3)`

### [legend()](https://ww2.mathworks.cn/help/matlab/ref/legend.html) 添加图例

+  添加图例，参数内容与画图时 `plot()` 的参数内容一一对应；
  ![image-20210128195229283](https://i.loli.net/2021/01/28/lfdKVC45qzWb9TG.png)
+ 也可以在画图时添加图例：`plot(x,y,'DisplayName','cos(x)')` 固定参数 `DisplayName`(可省略) 后的 `cos(x)` 即是为该曲线添加的图例说明；
+ 为图例指定其他参数：
  ![image-20210128195624063](https://i.loli.net/2021/01/28/YsgL5It8leHhGvV.png)
+ 图例位置参数对应的参数：![image-20210128195643224](https://i.loli.net/2021/01/28/qYTQOSo3R21Bywd.png)

### 添加标题与坐标轴

![image-20210128200438442](https://i.loli.net/2021/01/28/cLOYrm7saA9JMCI.png)

+ [title()](https://ww2.mathworks.cn/help/matlab/ref/title.html)：为图添加标题；
+ [suptitle()](https://ww2.mathworks.cn/help/matlab/ref/suptitle.html) 在一个 figure 中画多个子图时，添加一个大标题；
+ [xlabel()](https://ww2.mathworks.cn/help/matlab/ref/xlabel.html)、[ylabel()](https://ww2.mathworks.cn/help/matlab/ref/ylabel.html)、[zlabel()](https://ww2.mathworks.cn/help/matlab/ref/zlabel.html)：为 x y z 轴添加题注；
  注意诸如 `\pi` `e^{-x}` 这样的写法，使得公式显示的更漂亮

### 在图中添加文本说明

![image-20210128201018418](https://i.loli.net/2021/01/28/7biv25onFRtlfkj.png)

+ [line()](https://ww2.mathworks.cn/help/matlab/ref/line.html)：绘制基本线条. 在课件的这段代码中，`line()` 的第一个参数是 x 坐标，第二个参数是 y 坐标. 按照这两个向量连线画图；
  其实效果与plot差不多，基本的使用也与plot一样：
  ![](https://i.loli.net/2021/01/28/ezRs2lVc6LrP5Kk.png)

+ [text()](https://ww2.mathworks.cn/help/matlab/ref/text.html)：为数据点添加文本说明. 在课件中是使用 `text()` 结合 latex 语法在图中添加公式说明. 如课件截图中的标识，需要在 latex 语法前后添加 `$$`，以字符串的形式记入一个 string 变量 str 中；`text()` 前两个参数是说明在图中的起始位置，第3个参数是 latex 语句字符串，后两个是使用 latex 语法添加说明时的固有格式. 如果只是向图中添加普通文本说明，而非特殊语法(如latex语法)，则不需要最后两个参数.

  `text()` 还有很多不同用法，可以为图添加非常漂亮的说明，可以查看 [text()的官方文档](https://ww2.mathworks.cn/help/matlab/ref/text.html)，但就画图的出发点而言，其他的各种效果均可以通过截图添加文本实现，如此更加方便.

+ `Annotation(lineType, x, y)`：创建一个在当前图窗中的两个点之间延伸的线条或箭头注释。
  将 `lineType` 指定为 `line`(线条)、`arrow`(箭头) 或 `doublearrow`(双向箭头). 
  将 x 和 y 分别指定为 `[x_begin, x_end]` 和 `[y_begin, y_end]` 形式的二元素向量.

# 获取图像的相关 handle 更改图像属性

 ### 图像的属性

画出的一个图主要包括 Figure  Axes  Line 三个 Object
![image-20210128203041729](https://i.loli.net/2021/01/28/kLbVMQKIUncaFuz.png)

+ 通过 `h = plot(x,y)` 可以使 `h` 得到画出图形中 Line 的 handle (类似于file id)，以后便可以通过 h 来改变 Line 的一些属性； `gcf`、`gca`也类似

+ 比如像下面这样利用 `gca` 来改变 Axes，即数轴的属性：
  如图所示，[set()](https://ww2.mathworks.cn/help/matlab/ref/set.html)、[xlim()](https://ww2.mathworks.cn/help/matlab/ref/xlim.html)两种方式均可以改变数轴的范围
  ![image-20210128203426352](https://i.loli.net/2021/01/28/nFwlWoIzaACKBSp.png)

+ 从 R2014b 开始，matlab 已经支持类似 sturct 的圆点法来设置属性：
  下属代码可以达到一样的效果，（此方法严格遵守大小写，`g.xlim` 不可行）

  ```matlab
  g = gca;
  g.XLim = [0, 2*pi];
  g.YLim = [-1.2, 1.2];
  ```

### 设置数轴的字体与刻度

![image-20210128204709889](https://i.loli.net/2021/01/28/OcUxskAKRMbi2Lm.png)

+ `set(gca, 'fontsize', 25)`：可以将数轴上的字体设置为25号大小；

+ `set(gca, 'xtick'……)` 与 `set(gca, 'xticklabel'….)` 配合使用，前者 `xtick` 用于在数轴上对应的点处标出刻度，后者 `xticklabel` 在标出的刻度上对应地指定一个标签；
  课件中的例子即为：在 `x=0`, `pi/2`, `pi`, `3pi/2`, `2pi` 处标出刻度，然后以 0, 90, 180, 270, 360 对应地写上数轴；

+ 从 R2014b 开始，matlab 已经支持类似 sturct 的圆点法来设置属性：

  ```matlab
  g = gca;
  g.FontSize = 25;
  g.Xtick = 0:pi/2:2*pi; g.XtickLabel = 0:90:360;
  g.Xtick = 0:pi/2:2*pi; g.XtickLabel = {'0', '\pi/2', '\pi', '3\pi/2', '2\pi'};
  ```

+ [xtickangle(angle)](https://ww2.mathworks.cn/help/matlab/ref/xtickangle.html)：将当前坐标区的 x 轴刻度标签旋转到指定角度（以度为单位），其中 0 表示水平。指定正值表示逆时针旋转，负值表示顺时针旋转；
  `xtickangle(ax,angle)`：旋转 ax 指定的坐标区的刻度标签，而不是旋转当前坐标区的刻度标签；

+ x轴用时间表示：
  ![image-20210128205503161](https://i.loli.net/2021/01/28/hXEZ89wGmsKYDr4.png)

课件中的第三例，预期在x轴上标出 0, π/2….：
![image-20210128205811878](https://i.loli.net/2021/01/28/Q619x3zgRsFPYAv.png)
但貌似较新版本的 matlab 已经无法实现（2016b以及以上不再支持 `symbol` ）.
我利用与第二例类似的方法：

```matlab
set(gca,'xtick',0:pi/2:2*pi);
set(gca,'xticklabel',{'0','\pi/2','\pi','3\pi/2','2\pi'});
```

得到了不错的效果：
![image-20210128205842167](https://i.loli.net/2021/01/28/9M1vRYmnUVWlqe3.png)

### 更改线条属性

![image-20210128205911308](https://i.loli.net/2021/01/28/gnW5bfNTwzodeSM.png)

+ [delete(h)](https://ww2.mathworks.cn/help/matlab/ref/delete.html)：将画好的图形清除；
+ 使用圆点法完成上图实例
  ![image-20210128210042702](https://i.loli.net/2021/01/28/zfBPnikslKX4NAu.png)

### 描点属性

描出好看的点：
![image-20210128210207109](https://i.loli.net/2021/01/28/UQMjIpwiKxrbNB7.png)

+ `plot()` 有多个可选参数，这是常见的几个 [Line属性](https://ww2.mathworks.cn/help/matlab/ref/matlab.graphics.chart.primitive.line-properties.html) ：
  ![image-20210128210432206](https://i.loli.net/2021/01/28/tdyXLoSnKY3wN4v.png)
+ 由于需要所画图形的光滑性，对x的取值一般比较密集，这样一来对点的标记效果可能不理想，此时可以使用 `MarkerIndices` 参数选择性地标记部分点：
  x 实际上是一个 1×100 的向量，如果每一点都做标记，呈现的是一连串标记而非曲线，如图所示设置标记点 `1:5:length(y)`，每5个数据点做一个标记，即能达到预期效果
  ![image-20210128210524511](https://i.loli.net/2021/01/28/pN3TvtmYOA1EFbL.png)

### 多图多 Figure

![image-20210128210711427](https://i.loli.net/2021/01/28/sI3jYRxqeWEH5Zv.png)

+ 在画图前加上 [figure](https://ww2.mathworks.cn/help/matlab/ref/figure.html) 指令，然后 `plot()` 将创建第一个视窗 Figure1，第二次画图前若再加上figure 再 plot，则将创建第二个视窗 Figure2，前一个视窗依然在；
+ 还可以使用 `h = figure(1)` 创建一个编号为 1 的 Figure，并获得它的 handle，便可在有多个 Figure 时，利用 `h` 来设置编号为 1 的 Figure 的相关属性；
+ 需要注意的是，画多图后，“当前窗口”指的是最新创建的视窗，所以 gca、gcf 这些指令所做出的操作，结果均作用于最新创建的视窗；

### 多图多 Figure

![image-20210128211138828](https://i.loli.net/2021/01/28/u2kzb7f43GpOaTc.png)

+ [subplot(m,n,p)](https://ww2.mathworks.cn/help/matlab/ref/subplot.html) 将当前图窗划分为 m×n 网格，并在 p 指定的位置创建坐标区。按行号对子图位置进行编号. 第一个子图是第一行的第一列，第二个子图是第一行的第二列，依此类推. 如果指定的位置已存在坐标区，则此命令会将该坐标区设为当前坐标区；
+ `subplot(2,2,[3,4])`：连接 3、4 两个位置画一个长图；
+ 自定义子图的位置：
  ![image-20210128211352682](https://i.loli.net/2021/01/28/XCr63iwqZcGuWxN.png)
+ 创建一个包含多个子图的图窗，将每一个子图的 Axes 存入变量中，但不画图。所有子图创建完后再定位到目标子图，画图并进行更多个性化操作：
  ![image-20210128211419425.png](https://i.loli.net/2021/01/28/b7KESX3FN8MiPB2.png)

### 图像个性化操作

![image-20210128211524132](https://i.loli.net/2021/01/28/COnDP4gStwKIrNf.png)

+ [grid on/off](https://ww2.mathworks.cn/help/matlab/ref/grid.html)：使网格可见或不可见
  [box on/off](https://ww2.mathworks.cn/help/matlab/ref/box.html)：使盒子可见或不可见（即数轴左方和上方的边框）
  [axis on/off](https://ww2.mathworks.cn/help/matlab/ref/axis.html)：使数轴可见或不可见

### 保存绘图

+ [saveas(fig,filename)](https://ww2.mathworks.cn/help/matlab/ref/saveas.html)：将 `fig` 指定的图窗保存到 filename 文件中。务必加上文件扩展名，例如 `myplot.jpg`，如果不指定扩展名，则 `saveas()` 默认将图窗保存为 FIG 文件；

+ 要保存当前图窗，请将 `fig` 指定为 `gcf`，一般使用：
  .png 保存为位图，.svg 保存为矢量图，两种格式均可用于word

  ```matlab
  saveas(gcf, 'filename.png');
  saveas(gcf, 'filename.svg');
  saveas(gcf, 'filename.pdf');
  ```

+ `print(fig,filename)`：与 `saveas()` 使用基本一致。`print()` 应该会更加强大一些。目前浅度使用，二者均可；

  `print(gcf, 'filename.svg')` 保存的 .svg 格式图片 word 无法显示。

# 练习

![image-20210128213045285](https://i.loli.net/2021/01/28/9GoQHsNOifWpL2w.png)

```matlab
clear all;
close all;
t=linspace(1,2);
f=t.^2;
g=sin(2*pi*t);
p=plot(t,f,'b',t,g,'ro');
legend({'t^{2}','sin(2\pi t)'},'location','best');
title('Mini Assignment #1');
xlabel('Time (ms)');
ylabel('f(t)');
```

![image-20210128213155460](https://i.loli.net/2021/01/28/TGEi4IxgFHSNhn8.png)

```matlab
clear all;
close all;
t=linspace(1,2);
f=t.^2;
g=sin(2*pi*t);
p=plot(t,f,'b',t,g,'ro');
legend({'t^{2}','sin(2\pi t)'},'location','best');
title('Mini Assignment #1');
xlabel('Time (ms)');
ylabel('f(t)');
%==============以上均为练习1的代码==============%
%=========只需修改练习1图的一些属性即可==========%
p(1).Color='k';
p(1).LineWidth=3;
p(2).MarkerEdgeColor='m';
p(2).MarkerFaceColor='#7E2F8E';
p(2).MarkerSize=4;
g=gca;
g.FontSize=15
```

