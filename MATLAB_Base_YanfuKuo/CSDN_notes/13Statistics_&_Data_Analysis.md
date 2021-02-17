@[TOC](统计)
# 叙述统计学
## 数值统计
主要介绍一些函数。

 **`M = mean(A)` 返回 A 沿大小不等于 1 的第一个数组维度的元素的均值**
如果 A 是向量，则 mean(A) 返回元素均值；
如果 A 为矩阵，那么 mean(A) 返回包含每列均值的行向量。

**`M = mean(A,'all')`** 计算 A 的所有元素的均值（R2018b及以上）。
**`M = mean(A,dim)`** 返回维度 dim 上的均值。例如，如果 A 为矩阵，则 mean(A,2) 是包含每一行均值的列向量。
**`M = mean(A,vecdim)`** 计算向量 vecdim 所指定的维度上的均值。例如，如果 A 是矩阵，则 mean(A,[1 2]) 是 A 中所有元素的均值，因为矩阵的每个元素都包含在由维度 1 和 2 定义的数组切片中。
<br>

**`M = median(A)` 返回 A 的中位数值**
如果 A 为向量，则 median(A) 返回 A 的中位数值。
如果 A 为非空矩阵，则 median(A) 将 A 的各列视为向量，并返回中位数值的行向量。
`M = median(A,'all')`/`M = median(A,dim)`/`M = median(A,vecdim)`与上述一致。
<br>
**`M = mode(A)` 返回 A 的样本众数**。如果有多个值以相同的次数出现，mode 将返回其中最小的值。
如果 A 为向量，则 mode(A) 返回 A 中出现次数最多的值。
如果 A 为非空矩阵，那么 mode(A) 将返回包含 A 每列众数的行向量。
`'all'/dim/vecdim`用法与上述一致
<br>
`Y = prctile(X,p)` 返回 X 中元素在 [0,100] 区间内的百分比 p 的百分数。
如果 X 是一个向量，那么 Y 是一个标量或向量，其长度与请求的百分比数（length( p)）相同。Y(i)包含p(i)百分位数。
如果X是一个矩阵，那么Y是一个行向量或矩阵，其中Y的行数等于请求的百分位数(length( p))。Y的第i行包含X的每一列的p(i)百分位数。
`'all'/dim/vecdim`用法与上述一致
<br>
**`S = std(A)` 返回 A 沿大小不等于 1 的第一个数组维度的元素的标准差**。
如果 A 是观测值的向量，则标准差为标量。
如果 A 是一个列为随机变量且行为观测值的矩阵，则 S 是一个包含与每列对应的标准差的行向量。
`'all'/dim/vecdim`用法与上述一致

默认情况下，标准差按 N-1 实现归一化，其中 N 是观测值数量。
**`S = std(A,w)` 指定一个权重方案**。当 w = 0 时（默认值），S 按 N-1 进行归一化。当 w = 1 时，S 按观测值数量 N 进行归一化。w 也可以是包含非负元素的权重向量。在这种情况下，w 的长度必须等于 std 将作用于的维度的长度。
<br>
**`V = var(A)` 返回 A 中沿大小不等于 1 的第一个数组维度的元素的方差**。
如果 A 是一个观测值向量，则方差为标量。
如果 A 是一个其各列为随机变量、其各行为观测值的矩阵，则 V 是一个包含对应于每列的方差的行向量。
`'all'/dim/vecdim`用法与上述一致

`V = var(A,w)` 指定权重方案。如果 w = 0（默认值），则 V 按观测值数量 -1 实现归一化。如果 w = 1，则它按观测值数量实现归一化。w 也可以是包含非负元素的权重向量。在这种情况下，w 的长度必须等于 var 将作用于的维度的长度。
<br>
## 图形统计
**`area()` 填充二维绘图**
区域图将 Y 中的元素显示为一个或多个曲线并填充每个曲线下方的区域。如果 Y 为矩阵，则曲线堆叠在一起，显示**每行元素占每个 x 区间的曲线总高度的相对量**。

**`stem()` 绘制离散序列数据**
stem(Y) 将数据序列 Y 绘制为从沿 x 轴的基线延伸的针状图。各个数据值由终止每个针状图的圆指示。
![](https://img-blog.csdnimg.cn/20200825221559749.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>
**`boxplot(x)` 为 x 中的数据创建一个方框图**。如果 x 是一个向量，boxplot 会绘制一个方框。如果 x 是一个矩阵，boxplot 为 x 的每一列绘制一个方框。
在每个方框中，中心标记表示中位数，方框的底部和顶部边缘分别表示第25和第75百分位数。晶须延伸到不被认为是离群值的最极端的数据点，离群值用 "+"号单独绘制。
![](https://img-blog.csdnimg.cn/20200826195611675.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>
**衡量分布偏度的方法**：
向左倾斜：skewness < 0
向右倾斜：skewness > 0
![](https://img-blog.csdnimg.cn/20200826202913284.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
**`y = skewness(X)` 返回 X 的样本偏度**。
如果 X 是一个向量，那么 skewness(X) 返回一个标量值，即 X 中元素的偏度。
如果 X 是一个矩阵，那么 skewness(X) 返回一个包含 X 中每一列样本偏度的行向量。
![](https://img-blog.csdnimg.cn/20200826202739350.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>
**`k = kurtosis(X)` 返回 X 的样本峰度**。
如果X是一个向量，那么kurtosis(X)返回一个标量值，它是X中元素的峰度。
如果X是一个矩阵，那么kurtosis(X)返回一个包含X中每一列的样本峰度的行向量。
![](https://img-blog.csdnimg.cn/20200826203504289.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
<br>
<br>
# 推论统计学
基本上都是统计学的知识，应该概率论与数理统计会教到。
日后补上（逃
<br>
<br>

# 练习
![](https://img-blog.csdnimg.cn/20200825222624855.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
```matlab
clear all;close all;
x = 1:14;
y = [1 3 5 5 5 5 7 9 9 9 10 13 14];
for i=1:14
    freqy(i) = length(find(y==i));
end
subplot(1,3,1); bar(x,freqy); xlim([0 15]);
subplot(1,3,2); area(x,freqy); xlim([0 15]);
subplot(1,3,3); stem(x,freqy); xlim([0 15]);
```
<br>

![](https://img-blog.csdnimg.cn/20200826200450225.png#pic_center)
```matlab
load stockreturns;
boxplot(stocks)
```
<br>
<br>
<br>

以上内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：<https://www.bilibili.com/video/BV1DA411Y7bN>
