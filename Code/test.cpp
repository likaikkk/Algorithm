#include<iostream>
using namespace std;

int m, arr[100];
// 定义深度优先搜索函数dfs，接受三个参数：n（目标和），i（当前数组的长度），a（当前可选的最小整数）
void dfs(int n, int i, int a) {
    if (n == 0) {
        for (int j = 1;j <= i - 1;j++)
            cout << arr[j];
        cout << endl;
    }
    if (i <= m) {
        for (int j = a;j <= n;j++) {
            arr[i] = j;
            dfs(n - j, i + 1, j);
        }
        // 递归调用dfs函数，传入新的参数
        // n-j表示减去已选择的整数后的新目标和
        // i+1表示数组长度增加1
        // j表示下一个可选整数的最小值
    }
}

int main() {
    int n; // 输入的目标和
    scanf("%d%d", &n, &m); // 从标准输入中读取目标和n和数组长度m
    dfs(n, 1, 1); // 调用dfs函数开始搜索
    return 0;
}

