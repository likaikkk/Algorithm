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

//高精度减法
string subString(string num1, string num2) {
    string n1 = num1;
    string n2 = num2;
    int flag = 0;
    if (n1.length() < n2.length() || n1.length() == n2.length() && n1 < n2) {
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

//高精度乘法
string multiply(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();

    // 结果的长度最多为两个输入数字的长度之和
    int result_len = len1 + len2;
    int carry = 0;
    string result(result_len, '0');

    // 从右往左逐位相乘
    for (int i = len1 - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int temp_carry = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2 + (result[i + j + 1] - '0') + temp_carry;
            temp_carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }

        result[i] = temp_carry + '0';
    }

    // 去掉前导零
    size_t start_pos = result.find_first_not_of('0');
    if (start_pos != string::npos) {
        return result.substr(start_pos);
    }
    else {
        return "0";
    }
}

int main() {
    string num1;
    string num2;
    cin >> num1 >> num2;
    // 调用高精度加法函数计算它们的和
    //string sum = addStrings(num1, num2);
    string diff = subString(num1, num2);
    // 打印结果
    //cout << sum << endl;
    cout << diff << endl;

    return 0;

}