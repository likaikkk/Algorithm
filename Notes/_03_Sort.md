- [排序](#排序)
  - [排序简介](#排序简介)
    - [定义](#定义)
    - [性质](#性质)
      - [1.稳定性](#1稳定性)
      - [2.时间复杂度](#2时间复杂度)
  - [选择排序](#选择排序)
    - [定义](#定义-1)
    - [性质](#性质-1)
      - [稳定性](#稳定性)
      - [时间复杂度](#时间复杂度)
    - [代码实现](#代码实现)
  - [冒泡排序](#冒泡排序)
    - [定义](#定义-2)
    - [过程](#过程)
    - [性质](#性质-2)
      - [稳定性](#稳定性-1)
      - [时间复杂度](#时间复杂度-1)
    - [代码实现](#代码实现-1)
  - [插入排序](#插入排序)
    - [定义](#定义-3)
    - [性质](#性质-3)
      - [稳定性](#稳定性-2)
      - [时间复杂度](#时间复杂度-2)
    - [代码实现](#代码实现-2)
  - [计数排序](#计数排序)
    - [定义](#定义-4)
    - [过程](#过程-1)
    - [性质](#性质-4)
      - [稳定性](#稳定性-3)
      - [时间复杂度](#时间复杂度-3)
    - [代码实现](#代码实现-3)
  - [快速排序](#快速排序)
    - [定义](#定义-5)
    - [基本原理与实现](#基本原理与实现)
      - [过程](#过程-2)
      - [代码实现](#代码实现-4)
    - [性质](#性质-5)
      - [稳定性](#稳定性-4)
      - [时间复杂度](#时间复杂度-4)
    - [优化](#优化)
      - [三数取中](#三数取中)
      - [插入排序](#插入排序-1)
      - [随机选择枢纽元素](#随机选择枢纽元素)
  - [归并排序](#归并排序)
    - [定义](#定义-6)
    - [性质](#性质-6)
    - [过程](#过程-3)
      - [图解算法](#图解算法)
    - [实现](#实现)
  - [基数排序](#基数排序)
  - [堆排序](#堆排序)
  - [桶排序](#桶排序)
  - [希尔排序](#希尔排序)
  - [锦标赛排序](#锦标赛排序)
  - [tim 排序](#tim-排序)
  - [排序相关 STL](#排序相关-stl)
  - [排序应用](#排序应用)

# 排序

## 排序简介

### 定义

**排序算法**(Sorting algorithm)是一种将一组特定的数据按某种顺序进行排列的算法。排序算法多种多样，性质也大多不同。

### 性质

#### 1.稳定性

稳定性是指相等的元素经过排序之后相对顺序是否发生了改变。

拥有稳定性这一特性的算法会让原本有相等键值的纪录维持相对次序，即如果一个排序算法是稳定的，当有两个相等键值的纪录 $R$ 和 $S$，且在原本的列表中 $R$ 出现在 $S$ 之前，在排序过的列表中 $R$ 也将会是在 $S$ 之前。

基数排序、计数排序、插入排序、冒泡排序、归并排序是稳定排序。

选择排序、堆排序、快速排序、希尔排序不是稳定排序。

#### 2.时间复杂度

基于比较的排序算法的时间复杂度下限是 $O(n\log n)$ 的。

当然也有不是 $O(n\log n)$ 的。例如，计数排序 的时间复杂度是 $O(n+w)$，其中 $w$ 代表输入数据的值域大小。

![各种排序算法示意图](http://oi-wiki.com/basic/images/sort-intro-1.apng)

## 选择排序

### 定义

**选择排序**（英语：Selection sort）是一种简单直观的排序算法。它的工作原理是每次找出第 i 小的元素（也就是 A<sub>i..n</sub> 中最小的元素），然后将这个元素与数组第 i 个位置上的元素交换。

![Selection sort](http://oi-wiki.com/basic/images/selection-sort-1-animate-example.svg)

### 性质

#### 稳定性

由于 swap（交换两个元素）操作的存在，选择排序是一种不稳定的排序算法。

#### 时间复杂度

选择排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为 O(n<sup>2</sup>)。

### 代码实现

```cpp
void selection_sort(int* a, int n) {
  for (int i = 1; i < n; ++i) {
    int ith = i;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] < a[ith]) {
        ith = j;
      }
    }
    std::swap(a[i], a[ith]);
  }
}
```

## 冒泡排序

### 定义

**冒泡排序**（英语：Bubble sort）是一种简单的排序算法。由于在算法的执行过程中，较小的元素像是气泡般慢慢「浮」到数列的顶端，故叫做冒泡排序。

### 过程

它的工作原理是每次检查相邻两个元素，如果前面的元素与后面的元素满足给定的排序条件，就将相邻两个元素交换。当没有相邻的元素需要交换时，排序就完成了。

经过 i 次扫描后，数列的末尾 i 项必然是最大的 i 项，因此冒泡排序最多需要扫描 n-1 遍数组就能完成排序。

![Selection sort](https://imgconvert.csdnimg.cn/aHR0cDovL3d3dy5jeHl4aWFvd3UuY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDE5LzEwLzE1NzEwNTgyNzktMWYxMTRhNzUwOTBkNTViLmdpZg)

### 性质

#### 稳定性

冒泡排序是一种稳定的排序算法。

#### 时间复杂度

在序列完全有序时，冒泡排序只需遍历一遍数组，不用执行任何交换操作，时间复杂度为 $O(n)$。

在最坏情况下，冒泡排序要执行 $\frac{(n-1)n}{2}$ 次交换操作，时间复杂度为 $O(n^2)$。

冒泡排序的平均时间复杂度为 $O(n^2)$。

### 代码实现

```cpp
// 假设数组的大小是 n + 1，冒泡排序从数组下标 1 开始
void bubble_sort(int *a, int n) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i + 1]) {
        flag = true;
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}
```

## 插入排序

### 定义

**插入排序**（英语：Insertion sort）是一种简单直观的排序算法。它的工作原理为将待排列元素划分为「已排序」和「未排序」两部分，每次从「未排序的」元素中选择一个插入到「已排序的」元素中的正确位置。

一个与插入排序相同的操作是打扑克牌时，从牌桌上抓一张牌，按牌面大小插到手牌后，再抓下一张牌。

![Selection sort](http://oi-wiki.com/basic/images/insertion-sort-1-animate-example.svg)

### 性质

#### 稳定性

插入排序是一种稳定的排序算法。

#### 时间复杂度

插入排序的最优时间复杂度为 $O(n)$，在数列几乎有序时效率很高。

插入排序的最坏时间复杂度和平均时间复杂度都为 $O(n^2)$。

### 代码实现

```cpp
void insert_sort(int* a, int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j = i - 1;
            int key = a[i];
            while (j >= 0 && key < a[j]) {  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;      //插入到正确位置
        }
    }
```

## 计数排序

### 定义

**计数排序**（英语：Counting sort）是一种线性时间的排序算法。

### 过程

计数排序的工作原理是使用一个额外的数组 C，其中第 $i$ 个元素是待排序数组 A 中值等于 $i$ 的元素的个数，然后根据数组 C 来将 A 中的元素排到正确的位置。

![](http://oi-wiki.com/basic/images/counting-sort-1-animate-example.svg)

### 性质

#### 稳定性

计数排序是一种稳定的排序

#### 时间复杂度

计数排序的时间复杂度为 $O(n+w)$，其中 $w$ 代表待排序数据的值域大小。

### 代码实现

```cpp
void counting_sort(int* a, int n) {
    //求出最大数组
    int max_element = a[1];
    for (int i = 2;i <= n;i++)
        if (a[i] > max_element)
            max_element = a[i];

    //创建一个技术数组，大小为最大元素值加一，所有元素赋值为0
    int count[MAX + 1] = { 0 };

    for (int i = 1;i <= n;i++) {
        count[a[i]]++;
    }

    int index = 1;
    for (int i = 1;i <= max_element;i++) {
        while (count[i] > 0) {
            a[index] = i;//根据计数信息将元素放回原数组
            index++;
            count[i]--;
        }
    }
}
```

## 快速排序

### 定义

**快速排序**（英语：Quicksort），又称分区交换排序（英语：partition-exchange sort），简称「快排」，是一种被广泛运用的排序算法。

### 基本原理与实现

#### 过程

快速排序的工作原理是通过 `分治` 的方式来将一个数组排序。

快速排序分为三个过程：

1. 将数列划分为两部分（要求保证相对大小关系）；
2. 递归到两个子序列中分别进行快速排序；
3. 不用合并，因为此时数列已经完全有序。

和归并排序不同，第一步并不是直接分成前后两个序列，而是在分的过程中要保证相对大小关系。具体来说，第一步要是要把数列分成两个部分，然后保证前一个子数列中的数都小于后一个子数列中的数。为了保证平均时间复杂度，一般是随机选择一个数 m 来当做两个子数列的分界。

之后，维护一前一后两个指针 p 和 q，依次考虑当前的数是否放在了应该放的位置（前还是后）。如果当前的数没放对，比如说如果后面的指针 q 遇到了一个比 m 小的数，那么可以交换 p 和 q 位置上的数，再把 p 向后移一位。当前的数的位置全放对后，再移动指针继续处理，直到两个指针相遇。

其实，快速排序没有指定应如何具体实现第一步，不论是选择 m 的过程还是划分的过程，都有不止一种实现方法。

第三步中的序列已经分别有序且第一个序列中的数都小于第二个数，所以直接拼接起来就好了。

#### 代码实现

```cpp
void quick_sort(int* a, int left, int right) {
    if (left < right) {
        int pivot = a[left];//选择第一个元素为枢纽元素
        int low = left, high = right;
        while (low < high) {
            // 从右向左找到第一个小于枢纽元素的元素
            while (low < high && a[high] >= pivot) {
                high--;
            }
            a[low] = a[high];// 将找到的元素放入左边的位置

            // 从左向右找到第一个大于枢纽元素的元素
            while (low < high && a[low] <= pivot) {
                low++;
            }
            a[high] = a[low];// 将找到的元素放入右边的位置
        }
        a[low] = pivot;// 枢纽元素归位

        // 递归排序枢纽元素左右两侧的子数组

        quick_sort(a, left, low - 1);
        quick_sort(a, low + 1, right);
    }

}
```

### 性质

#### 稳定性

快速排序是一种不稳定的排序算法。

#### 时间复杂度

快速排序的最优时间复杂度和平均时间复杂度为 $O(n\log n)$，最坏时间复杂度为 $O(n^2)$。

对于最优情况，每一次选择的分界值都是序列的中位数，此时算法时间复杂度满足的递推式为

$T(n) = 2T(\dfrac{n}{2}) + \Theta(n)$，由主定理，$T(n) = \Theta(n\log n)$。

对于最坏情况，每一次选择的分界值都是序列的最值，此时算法时间复杂度满足的递推式为 $T(n) = T(n - 1) + \Theta(n)$，累加可得 $T(n) = \Theta(n^2)$。

对于平均情况，每一次选择的分界值可以看作是等概率随机的。

在实践中，几乎不可能达到最坏情况，而快速排序的内存访问遵循局部性原理，所以多数情况下快速排序的表现大幅优于堆排序等其他复杂度为 $O(n \log n)$ 的排序算法。

### 优化

如果仅按照上文所述的基本思想来实现快速排序（或者是直接照抄模板）的话，那大概率是通不过 P1177【模板】快速排序 这道模板的。因为有毒瘤数据能够把朴素的快速排序卡成 $O(n^2)$。

所以，我们需要对朴素快速排序思想加以优化。较为常见的优化思路有以下三种。

- 通过 **三数取中**（即选取第一个、最后一个以及中间的元素中的中位数） 的方法来选择两个子序列的分界元素（即比较基准）。这样可以避免极端数据（如升序序列或降序序列）带来的退化；
- 当序列较短时，使用 **插入排序** 的效率更高；
- **随机选择枢纽元素**，随机选择枢纽元素可以降低快速排序在平均情况下的时间复杂度，并减少出现最坏情况的概率。你可以使用随机数生成器来选择枢纽元素，而不是总是选择第一个元素。

#### 三数取中

```cpp
int mid = left + (right - left) / 2;
if (a[left] > a[mid]) {
    swap(a[left], a[mid]);
}
if (a[left] > a[right]) {
    swap(a[left], a[right]);
}
if (a[mid] > a[right]) {
    swap(a[mid], a[right]);
}

int pivot = a[mid];
swap(a[mid], a[left]);
```

#### 插入排序

```cpp
void insertion_sort(int* a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= left && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void quick_sort(int* a, int left, int right) {
    if (right - left + 1 <= INSERTION_SORT_THRESHOLD) { // 设定一个阈值
        insertion_sort(a, left, right);
    } else {
        // 继续快速排序
    }
}
```

#### 随机选择枢纽元素

```cpp
int pivot_index = rand() % (right - left + 1) + left;
int pivot = a[pivot_index];
swap(a[pivot_index], a[left]);
```

## 归并排序

### 定义

**归并排序**（merge sort）是高效的基于比较的稳定排序算法。

### 性质

稳定性：稳定

归并排序基于分治思想将数组分段排序后合并，时间复杂度在最优、最坏与平均情况下均为 $\Theta (n \log n)$，空间复杂度为 $\Theta (n)$。

归并排序可以只使用 $\Theta (1)$ 的辅助空间，但为便捷通常使用与原数组等长的辅助数组。

### 过程

归并排序算法有两个基本的操作，一个是**分**，也就是把原数组划分成两个子数组的过程。另一个是**治**，它将两个有序数组合并成一个更大的有序数组。

1. 将待排序的线性表不断地切分成若干个子表，直到每个子表只包含一个元素，这时，可以认为只包含一个元素的子表是有序表。
2. 将子表两两合并，每合并一次，就会产生一个新的且更长的有序表，重复这一步骤，直到最后只剩下一个子表，这个子表就是排好序的线性表。

#### 图解算法

假设我们有一个初始数列为{8, 4, 5, 7, 1, 3, 6, 2}，整个归并排序的过程如下图所示。

**分而治之**
![](https://img-blog.csdnimg.cn/20200209191150963.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3RpZGxl,size_16,color_FFFFFF,t_70)
可以看到这种结构很像一棵完全二叉树，本文的归并排序我们采用递归去实现（也可采用迭代的方式去实现）。分阶段可以理解为就是递归拆分子序列的过程，递归深度为 log2n。

**合并两个有序数组流程**

再来看看治阶段，我们需要将两个已经有序的子序列合并成一个有序序列，比如上图中的最后一次合并，要将[4,5,7,8]和[1,2,3,6]两个已经有序的子序列，合并为最终序列[1,2,3,4,5,6,7,8]，来看下实现步骤。

![](https://img-blog.csdnimg.cn/20200209191419709.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3RpZGxl,size_16,color_FFFFFF,t_70)

**动画演示**
![](https://img-blog.csdnimg.cn/20200209185525881.gif)

### 实现

```cpp
void merge(int* sourceArr, int* tempArr, int startIndex, int midIndex, int endIndex) {
    int i = startIndex, j = midIndex + 1, k = startIndex;

    //将两个有序的子数组合并为一个有序的数组
    while (i != midIndex + 1 && j != endIndex + 1) {
        if (sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }

    //处理剩余元素
    while (i != midIndex + 1)
    {
        tempArr[k++] = sourceArr[i++];
    }
    while (j != endIndex + 1)
    {
        tempArr[k++] = sourceArr[j++`];
    }

    //将合并后的结果复制回原数组
    for (int i = startIndex;i <= endIndex;i++)
        sourceArr[i] = tempArr[i];
}
//归并排序主函数
void merge_sort(int* sourceArr, int* tempArr, int startIndex, int endIndex) {
    int midIndex;

    //如果startIndex小于endIndex，继续递归排序
    if (startIndex < endIndex) {
        midIndex = startIndex + (endIndex - startIndex) / 2;//避免整数溢出
        merge_sort(sourceArr, tempArr, startIndex, midIndex);
        merge_sort(sourceArr, tempArr, midIndex + 1, endIndex);
        merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}


```

## 基数排序

## 堆排序

## 桶排序

## 希尔排序

## 锦标赛排序

## tim 排序

## 排序相关 STL

## 排序应用
