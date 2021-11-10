# 第二章总结

## 1.数学基础

### 四个数学定义：

##### 定义一：T(N)=O(f(N))    ——>T(N)的增长率小于等于(<=)f(N)的增长率

##### 定义二：T(N)=Ω(g(N))   ——>T(N)的增长率大于等于(>=)g(N)的增长率

##### 定义三：T(N)=θ(h(N))   ——>T(N)的增长率等于(=)h(N)的增长率

##### 定义四：T(N)=o(p(N))   ——>T(N)的增长率小于(<)p(N)的增长率

### **三个重要结论：**

法则1：如果T1(N)=O(f(N))且T2(N)=O(g(N))那么

（a）T1(N)+T2(N) = max(O(f(N)),O(g(N)))    加分原则

（b）T1(N)  * T2(N)=O(f(N)*g(N))

法则2：如果T(N)是一个K次多项式，则T(N)=θ(N^k)

法则3：对任意常数k,(logN)^k=O(N)。对数的增长得非常缓慢。

## 2.运行时间计算

为了简化分析，约定：不存在特定的时间单位。因此，常抛弃一些常数系数和低阶项，从而便于计算大O运行时间。

### （1）简单例子

```c
int Sum(int N)
{
    int i, partialSum;
 
    partialSum = 0;              //1 个时间单元
    for (i = 1; i <= N; i++)     //初始化耗时 1 个时间单元，测试比较耗时 N + 1 个时间单元，自增运算耗时 N 个时间单元
        partialSum += i * i * i; //4 个时间单元（2 次乘，1 次加，1 次赋值），循环 N 次耗时 4N 个时间单元
    return partialSum;           //1 个时间单元
}
```

总量为：6N+4，按照约定，该函数是O(N)

### （2）一般法则

**法则1——for循环：**

一次for循环的运行时间至多是该for循环内语句（包括测试）的运行时间乘以迭代的次数。

**法则2——嵌套的for循环**

从里向外分析这些循环。在一组嵌套循环内部的一条语句总的运行时间为该语句的运行时间乘以该组所有for循环的大小的乘积。

**法则3——顺序语句**

将各个语句的运行时间求和即可（这意味着，其中的最大值就是所得的运行时间）

**法则4——if/else 语句**

一个if/else语句的运行时间从不超过判断的时间再加上分支语句中运行时间较长者的总的运行时间。

## 3.最大子序列和问题

问题描述：给定整数A1，A2,，... ，AN（可能有负数），求∑jk=i Ak的最大值（为方便起见，如果所有整数均为负数，则最大子序列和为0）。

### （1）算法一:暴力穷举

```c
int maxSequenceSum1(const int A[], int N)
{
    int i, j, k, maxSum, thisSum;
 
    maxSum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            thisSum = 0;
            for (k = i; k <= j; k++)
                thisSum += A[k];
 
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
　　return maxSum;
}
```

### （2）算法二：撤销一个for循环，降低立方级的运行时间

```c
int maxSequenceSum2(const int A[], int N)
{
    int i, j, maxSum, thisSum;
 
    maxSum = 0;
    for (i = 0; i < N; i++)
    {
        thisSum = 0;
        for (j = i; j < N; j++)
        {
            thisSum += A[j];
 
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
```

### (3)算法三:利用“分治”的思想

```c
int maxSubSum(const int A[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;
 
    if (left == right)    /*Base case*/
    {
        if (A[left] > 0)
            return A[left];
        else
            return 0;
    }
 
    center = (left + right) / 2;
    maxLeftSum = maxSubSum(A, left, center);
    maxRightSum = maxSubSum(A, center + 1, right);
 
    maxLeftBorderSum = 0;    leftBorderSum = 0;
    for (i = center; i >= left; i--)
    {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
 
    maxRightBorderSum = 0;    rightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max(maxLeftSum, maxRightSum,
        maxLeftBorderSum + maxRightBorderSum);
}
 
int maxSequenceSum3(const int A[], int N)
{
    return maxSubSum(A, 0, N - 1);
}
```

### (4)算法四:联机算法

```c
int maxSequenceSum4(const int A[], int N)
{
    int i, maxSum, thisSum;
 
    maxSum = 0; thisSum = 0;
    for (i = 0; i < N; i++)
    {
        thisSum += A[i];
 
        if (thisSum> maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}
```



## 4.运行时间中的对数

### （1）对分查找

给定一个整数X和A0，A1，... ，AN-1，后者已经预先排序并在内存中，求使得Ai = X的下标i，如果X不在数据中，则返回i = -1。

```c
int binarySearch(const int A[], int N, int X)
{
    int low, high, mid;
 
    low = 0;high = N - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] < X)
            low = mid + 1;
        else if (A[mid] > X)
            high = mid - 1;
        else
            return mid;
    }
    return -1;        //not found
}
```

### （2）欧几里得算法

计算最大公因数。两个整数的最大公因数（Gcd）是同时整除两者的最大整数。算法通过连续计算余数直到为 0 时停止，最后的非零余数就是最大公因数。

```c
unsigned int gcd(unsigned int M, unsigned int N)
{
    int rem;
 
    while (N > 0)
    {
        rem = M % N;
        M = N;
        N = rem;
    }
    return M;
}
```

### （3）幂运算

如果N是偶数，则XN = X(N/2) * X(N/2)；如果N是奇数，则XN = X(N-1/2) * X(N-1/2) * X。

```c
long pow(long X, unsigned int N)
{
    if (N == 0)
        return 1;
    if (N == 1)
        return X;
 
    if (isEven(N))
        return pow(X * X, N / 2);
    else
        return pow(X * X, N / 2) * X;
}
```

## 5.感悟：

1.学到了如何去估计一个算法的时间复杂度；

2.而且也通过最大子序列和问题的四种算法，了解到了如何去优化算法（从时间复杂度上）。

3.还清楚的了解到几种定义和计算时间复杂度时的计算法则。

4.还有三种O(logN)的算法例子。

