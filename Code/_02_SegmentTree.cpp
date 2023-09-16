#include<iostream>

using namespace std;

const long long MAX = 100;
long long a[MAX];
long long d[4 * MAX];
long long b[4 * MAX];

// build a segment tree
void build(long long s, long long t, long long p) {
    // 对[s,t]区间建立线段树，当前根的编号为p
    if (s == t) {
        d[p] = a[s];
        return;
    }
    long long m = s + ((t - s) >> 1);
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

// 区间求和
long long getSum(long long l, long long r, long long s, long long t, long long p) {
    //[l,r]为查询区间，[s,t]为当前结点所包含的区间，p为当前结点
    if (l <= s && r >= t)
        return d[p];    //当前区间为询问区间的子集时，直接返回当前区间的和
    long long m = s + ((t - s) >> 1), sum = 0;
    if (b[p] && s != t) {
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p]; //将标记下传给子结点
        b[p] = 0;                               //清空当前结点的标记
    }
    //如果左儿子代表的区间[s.m]与询问区间有交集，则递归查询左儿子
    if (l <= m)
        sum += getSum(l, r, s, m, p * 2);
    //如果右儿子代表的区间[m+1,t]与询问区间有交集，则递归查询右儿子
    if (r > m)
        sum += getSum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}

// 区间修改（区间加上某个值）
void update(long long l, long long r, long long s, long long t, long long c, long long p) {
    //[l,r]为修改区间，c为被修改元素的变化量，[s,t]为当前结点包含的区间,p为当前结点的编号
    //当前区间为修改区间的子集时，直接修改当前结点的值，然后打标记，结束修改
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }
    long long m = s + ((t - s) >> 1);
    //如果当前节点的懒标记非空且当前节点不是叶子节点
    if (b[p] && s != t) {
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p]; //将标记下传给子结点
        b[p] = 0;                               //清空当前结点的标记
    }
    if (l <= m)
        update(l, r, s, m, c, p * 2);
    if (r > m)
        update(l, r, m+1, t, c, p * 2 + 1);
    
    // 更新当前节点的值为左子节点和右子节点的值之和
    d[p] = d[p * 2] + d[p * 2 + 1];
}

// 区间询问
long long query(long long p, long long s, long long t, long long l, long long r) {
    if (!p) return 0;    //如果结点为空，返回0
    if (s >= l && t <= r) return d[p];
    long long m = s + ((t - s) >> 1), ans = 0;
    if (l <= m)
        ans += query(p * 2, s, m, l, r);
    if (r > m)
        ans += query(p * 2 + 1, m + 1, t, l, r);
    return ans;
}

int main() {
    long long n; // 数组长度
    cout << "请输入数组长度 n: ";
    cin >> n;

    // 输入数组元素
    cout << "请输入 " << n << " 个整数作为数组元素：" << endl;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 构建线段树
    build(1, n, 1);

    long long choice;
    do {
        cout << "请选择操作：" << endl;
        cout << "1. 区间求和" << endl;
        cout << "2. 区间修改" << endl;
        cout << "3. 退出" << endl;
        cin >> choice;

        if (choice == 1) {
            long long l, r;
            cout << "请输入查询区间 [l, r]：" << endl;
            cin >> l >> r;
            long long sum = getSum(l, r, 1, n, 1);
            cout << "区间 [" << l << ", " << r << "] 的和为：" << sum << endl;
            cout << endl;
        }
        else if (choice == 2) {
            long long l, r, c;
            cout << "请输入修改区间 [l, r]：" << endl;
            cin >> l >> r;
            cout << "请输入增量 c：" << endl;
            cin >> c;
            update(l, r, 1, n, c, 1);
            cout << "区间 [" << l << ", " << r << "] 已修改" << endl;
        }

    } while (choice != 3);

    cout << "程序已退出。" << endl;
    return 0;
}
