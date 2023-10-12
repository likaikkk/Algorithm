# 高精度

## 高精度加法

```cpp
#include<iostream>
#include<string>

using namespace std;

//高精度加法
string addStrings(string num1, string num2) {
    string result;
    //初始化进位为0
    int carry = 0;
    //初始化两个指针分别指向两个字符串的最低位
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    //从个位开始，逐位相加，直到两个字符串都被遍历了并且没有进位
    while (i >= 0 || j >= 0 || carry > 0) {
        //取出当前位的数字，如果已经遍历完了某个字符串，就相应数字置为0
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        //将当前位数字和进位相加
        int sum = digit1 + digit2 + carry;

        //更新进位
        carry = sum / 10;

        //计算当前位的数字
        int digitSum = sum % 10;

        //将当前位的数字转换为字符并拼接到结果字符串的前面
        result = to_string(digitSum) + result;

        //移动指针，继续下一位的相加
        i--;
        j--;
    }

    //返回最后的高精度加法结果
    return result;
}

int main() {
    string num1;
    string num2;
    cin >> num1 >> num2;
    // 调用高精度加法函数计算它们的和
    string sum = addStrings(num1, num2);

    // 打印结果
    cout << sum << endl;

    return 0;

}
```

## 高精度减法

```cpp
string subString(string num1, string num2) {
    int flag = 0;
    string n1 = num1;
    string n2 = num2;

    if (n1.length() < n2.length() || (n1.length() == n2.length() && n1 < n2)) {
        swap(n1, n2);
        flag = 1;
    }

    int i = n1.length() - 1;
    int j = n2.length() - 1;
    string result = "";
    int borrow = 0;

    while (i >= 0) {
        int digit1 = n1[i] - '0';
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        result = to_string(diff) + result;
        i--;
        j--;
    }

    while (!result.empty() && result[0] == '0')
        result.erase(result.begin());
    if (flag)
        result = '-' + result;
    return (result.empty()) ? "0" : result;
}

```

## 高精度乘法

```cpp
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a1[10001], b1[10001];  // 存储输入的两个大整数的字符数组
int a[10001], b[10001], i, x, len, j, c[10001]; // 用于存储整数的数组和迭代变量

int main()
{
    cin >> a1 >> b1; // 输入两个大整数
    int lena = strlen(a1); // 计算第一个大整数的长度
    int lenb = strlen(b1); // 计算第二个大整数的长度

    // 将输入的字符转换为整数并存储在数组中（逆序）
    for (i = 1; i <= lena; i++)
        a[i] = a1[lena - i] - '0';

    for (i = 1; i <= lenb; i++)
        b[i] = b1[lenb - i] - '0';

    // 执行大整数乘法
    for (i = 1; i <= lenb; i++)
        for (j = 1; j <= lena; j++)
            c[i + j - 1] += a[j] * b[i];

    // 处理进位
    for (i = 1; i < lena + lenb; i++)
        if (c[i] > 9)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }

    len = lena + lenb; // 计算结果的长度
    // 去除前导零
    while (c[len] == 0 && len > 1)
        len--;

    // 输出乘积
    for (i = len; i >= 1; i--)
        cout << c[i];

    return 0;
}
```
