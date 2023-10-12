//2023/10/3
#include<iostream>
using namespace std;

#define max 10001000
int n, k;
int a[max], q[max];

void getMin() {//单调递增队列
    int head = 1, tail = 0;
    for (int i = 1;i <= n;i++) {
        while (head <= tail && a[q[tail]] >= a[i])//当队列不为空且队尾元素大于新元素时，tail回退，直到小于新元素
            tail--;
        q[++tail] = i;//更新tail
        if (q[head] < i - k + 1)//如果head超出k的范围，head++
            head++;
        if (i >= k)
            cout << a[q[head]] << " ";
    }
}

void getMax() {
    int head = 1, tail = 0;
    for (int i = 1;i <= n;i++) {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        if (q[head] < i - k + 1)
            head++;
        if (i >= k)
            cout << a[q[head]] << " ";
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    getMin();
    cout << endl;
    getMax();
    return 0;
}

/*
输入：
8 3
1 3 -1 -3 5 3 6 7
 */
