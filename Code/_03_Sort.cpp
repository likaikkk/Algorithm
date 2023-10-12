#include<iostream>

using namespace std;

#define MAX 1000  //对于计数排序来说输入数据最大范围
int b[MAX];
int m[MAX]; //用于归并排序的临时数组
//选择排序
void selection_sort(int* a, int n) {
    for (int i = 1;i < n;i++)
        for (int j = i + 1;j <= n;j++)
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

//冒泡排序
void bubble_sort(int* a, int n) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1;i < n;i++) {
            if (a[i] > a[i + 1]) {
                flag = true;
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

//插入排序
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
}

//计数排序
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

//快速排序
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

//归并排序
//合并两个有序数组
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
        tempArr[k++] = sourceArr[j++];
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



int main() {
    int n;
    cout << "请输入一个正整数n: " << endl;
    cin >> n;
    cout << "请输入" << n << "个整数：" << endl;
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }

    cout << "请选择排序方式：" << endl;
    cout << "1. 选择排序" << endl;
    cout << "2. 冒泡排序" << endl;
    cout << "3. 插入排序" << endl;
    cout << "4. 计数排序" << endl;
    cout << "5. 快速排序" << endl;
    cout << "6. 归并排序" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        selection_sort(b, n);
        break;
    case 2:
        bubble_sort(b, n);
        break;

    case 3:
        insert_sort(b, n);
        break;
    case 4:
        counting_sort(b, n);
        break;
    case 5:
        quick_sort(b, 1, n);
        break;
    case 6:
        merge_sort(b, m, 1, n);
        break;
    default:
        cout << "无效的选择" << endl;
        return 1;
    }

    cout << "排序后的数组：" << endl;
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";


    return 0;
}