//2023/10/6
/*
一只长度不计的蠕虫位于 n 英寸深的井的底部。它每次向上爬 u 英寸，但是必须休息一次才能再次向上爬。在休息的时候，它滑落了 d 英寸。之后它将重复向上爬和休息的过程。蠕虫爬出井口需要至少爬多少次？如果蠕虫爬完后刚好到达井的顶部，我们也设作蠕虫已经爬出井口。
 */
#include<iostream>
using namespace std;

int main() {
    int n, u, d;
    cin >> n >> u >> d;
    int time = 0, dist = 0;
    while (true) {
        dist += u;
        time++;
        if (dist >= n)
            break;
        dist -= d;
    }
    cout << time;
}
