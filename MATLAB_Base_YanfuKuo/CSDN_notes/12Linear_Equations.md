@[toc](线性方程)
>本次内容涉及线性代数，视频中大部分在讲解线性代数的知识，只稍微提及了几个matlab来实现的指令。
>学了现代之后再来看一遍（逃~

# 求解线性方程
将线性方程组用矩阵 **`Ax=b`** 表示，则可通过求解矩阵来解方程：
![](https://img-blog.csdnimg.cn/20200819180539920.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)

#### 高斯消去法`rref()`
`R = rref(A)` 使用 Gauss-Jordan 消元法和部分主元消元法返回A的简化行阶梯形。
对增广矩阵 **`[A b]`** 使用`rref()`则可以求解 **`Ax=b`** 对应的线性方程组
![](https://img-blog.csdnimg.cn/20200819210621164.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
#### LU因子化
`[L,U,P] = lu(A)` 将满矩阵或稀疏矩阵 A 分解为一个上三角矩阵 U 和一个经过置换的下三角矩阵 L，使得 A = L*U；返回一个置换矩阵 P，并满足 A = P'\*L\*U。
通过执行 LU 分解，然后使用因子来简化问题，对线性方程组求解。
>一些矩阵分解函数
>+ `qr()`：正交三角分解
>+ `ldl()`：Hermitian 不定矩阵的分块 LDL 分解
>+ `ilu()`：不完全 LU 分解
>+ `chol()`：Cholesky 分解
>+ `gsvd()`：广义奇异值分解
>+ `svd()`：奇异值分解

<br>

#### 高效`mldivide()、\`
以上两种方法在对于一般的线性方程组的求解其实并不友好，过于繁琐。**实际上，更加高效的方式是使用`A\b`（或者`mldivide(A,b)`）可直接求得方程组的根 向量`x`。**
<br>
#### 克莱默法则
求解矩阵方程 **`Ax=b`** ，**x**等于**A**的逆矩阵乘以**b**，即 **x=A^-1^b** 
通过`inv(A)`对矩阵A求逆，然后直接计算即可：`x = inv(A)*b`
>需要注意，矩阵A的逆矩阵可能不存在

<br>

# 线性系统
#### 特征值和特征向量`eig()`
`e = eig(A)` 返回一个列向量，其中包含方阵 A 的特征值；
`[V,D] = eig(A)` 返回特征值的对角矩阵 D 和矩阵 V，其列是对应的右特征向量，使得 A*V = V*D。

模糊综合评价中利用`eig()`求解最大特征根和权向量：
![](https://img-blog.csdnimg.cn/202008201741376.png#pic_center)
<br>
#### 矩阵指数`expm()`
`Y = expm(X)` 计算 X 的矩阵指数。如果 X 有一组完整的特征向量 V 和对应特征值 D，[V,D] = eig(X)，则expm(X) = V*diag(exp(diag(D)))/V；
对于逐个元素的指数运算，使用 `exp()`
![](https://img-blog.csdnimg.cn/20200820175219699.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)


# 习题
![](https://img-blog.csdnimg.cn/20200819214210506.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTg0MDgyNQ==,size_16,color_FFFFFF,t_70#pic_center)
```matlab
syms R1 R2 R3 R4 R5 V1 V2;
A=[R1 0 0 R4 0;0 R2 0 -R4 R5;0 0 -R3 0 R5;1 -1 0 -1 0;0 1 -1 0 -1];
b=[V1;0;V2;0;0];
x=A\b
```
<br>
<br>
<br>

以上内容为个人笔记，部分图片来源于郭老师课件或课程截图。
笔记汇总：[MATLAB基础教程](https://blog.csdn.net/weixin_45840825/article/details/107865933)
课程视频：<https://www.bilibili.com/video/BV1DA411Y7bN>

