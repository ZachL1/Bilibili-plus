以下内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：[MATLAB基础教程-台大郭彦甫（14课全-高清-含课件）](https://www.bilibili.com/video/BV1DA411Y7bN)

-----------

为了解决下列问题展开：
![image-20210131215140272](https://i.loli.net/2021/01/31/mc3jRskV58irNwL.png)

## 图像黑白化

对灰阶图像黑白化，即把图像颜色较深的那部分值设为全黑(0)，较浅那一部分设为全白(1)；
量化来说，就是对于图像的 histogram 图，选取一个合适的值(分界线)，将小于这个值的点设置为0，大于的设置为1：
![image-20210131222851388](https://i.loli.net/2021/01/31/5uNQ3vtlGeSjsEr.png)

+ [level = graythresh(I)](https://ww2.mathworks.cn/help/images/ref/graythresh.html) 可以计算出这个合适的值；
+ [bw = im2bw(I, level)](https://ww2.mathworks.cn/help/images/ref/im2bw.html) 则根据阈值 `I` 来把图像黑白化；
  ![](https://i.loli.net/2021/02/01/Gze3KI92VkLlQMJ.png)

## 图像背景

可以看出，简单的黑白化，会由于图像的整体亮度不均，导致效果不理想；
可以通过去除背景后再黑白化来优化。

+ [BG = imopen(I, strel('disk', 15))](https://ww2.mathworks.cn/help/images/ref/imopen.html) 可以通过此方法得到 rice.png 的背景；
  其中 [strel()](https://ww2.mathworks.cn/help/images/ref/strel.html) 的参数需要根据不同图像进行调整；
  与此对应的还有 [imclose(I, strel('disk', 15))](https://ww2.mathworks.cn/help/images/ref/imclose.html) 看用来对图像去噪；
+ [I2 = imsubtract(I, BG)](https://ww2.mathworks.cn/help/images/ref/imsubtract.html) 使用上一节的图像减法，得到去除背景后的图像，此时的图像整体亮度较为均衡，对其黑白化：
  ![image-20210131225740683](https://i.loli.net/2021/01/31/SH1N3kQFeR9YpEB.png)

## 图像计数

+ [[labeled,n] = bwlabel(BW, 8)](https://ww2.mathworks.cn/help/images/ref/bwlabel.html) 对二维黑白图中的连通分量进行标注，返回标注后的图像矩阵 `labeled` 和连通分量数 `n`；
  其原理即为对黑白图像的 01 矩阵全局 DFS，将连通的像素点标上同一个编号，`bwlabel(BW,conn)` 的第二个参数用于指定连通性：
  ![image-20210131230755678](https://i.loli.net/2021/01/31/wfy5BOACcoqMxan.png)
+ [RGB_label=label2rgb(labeled)](https://ww2.mathworks.cn/help/images/ref/label2rgb.html) 可以对标注的连通分量上色；
+ [graindata = regionprops(labeled, 'basic')](https://ww2.mathworks.cn/help/images/ref/regionprops.html) 给出每一个连通分量的 面积、中心、边界框 三个属性；
+ [ObjI = bwselect(BW)](https://ww2.mathworks.cn/help/images/ref/bwselect.html) 手动选择显示特定的连通分量，选择完成按回车键

```matlab
I=imread('rice.png');
BG=imopen(I, strel('disk', 15));
I2=imsubtract(I, BG); level=graythresh(I2);
BW=im2bw(I2, level);
% 计数
[labeled, numObjects]=bwlabel(BW, 8); 
% 上色
RGB_label=label2rgb(labeled); figure; imshow(RGB_label); 
% 给出连通分量的属性
graindata = regionprops(labeled, 'basic'); 
graindata(51) % 查看第51个连通分量的各属性
% 选择连通分量
ObjI = bwselect(BW); figure; imshow(ObjI);
```

# 练习

![image-20210131234447367](https://i.loli.net/2021/01/31/VxhWNbkGHqRzfyX.png)

```matlab
I = imread('rice.png');
imhist(I);
BW = I > 130; % 通过观察图像的histogram选择适当阈值
subplot(121); imshow(BW);
BW2 = I > graythresh(I)*255; % 通过函数计算合适的阈值
subplot(122); imshow(BW2);
```

> 实际上，灰阶图转化为黑白图，只需要 `I > x` 一条语句即可实现，大于阈值 `x` 的点将置为1，小于的将置为0；关键在于阈值的确定，可以通过观察图像的 histogram 图选择合适的，也可以通过函数计算

![image-20210131235244713](https://i.loli.net/2021/01/31/vTsE6P8VFX9LBMR.png)

```matlab
I=imread('rice.png');
BG=imopen(I, strel('disk', 15));
I2=imsubtract(I, BG); level=graythresh(I2);
BW=im2bw(I2, level);
[labeled, numObjects]=bwlabel(BW, 8);

%% 直方图
num_of_lab = zeros(1,numObjects); %预为哈希表先分配空间
for i=1:size(labeled, 1)
    for j=1:size(labeled, 2)
        index = labeled(i,j);
        if index ~= 0 %如果该点不为0，即被标记了，对应该标记的米粒大小加一
           num_of_lab(index)=num_of_lab(index)+1; %思想类似哈希表
        end
    end
end
histogram(num_of_lab)

%% 上色
r = BW * 255; %把白色部分的red分量置为全红
g = zeros(size(BW)); %green分量和blue分量为全0
b = zeros(size(BW));
red_rice = cat(3,r,g,b); %将RGB三个分量拼接为一个三维的彩图矩阵
figure; imshow(red_rice)
```

> 从连通块大小(连通块中像素点个数)的 histogram 中可以看出，连通块大小集中在150到250作用，说明米粒基本上就是这个大小(每个米粒大小差不多)；
> 但居然还存在小于100这样的连通块，这可能是一些噪点或者边界的不完整米粒，可以考虑去除这部分连通块数；
> 还有大于350的连通块，这可能是两颗米粒相邻比较近，被标记为一个连通块，可以考虑将这部分连通块数乘以2；