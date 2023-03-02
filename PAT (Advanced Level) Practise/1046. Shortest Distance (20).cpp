#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];

int main() {
    int n, m, a, b, t, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (i != n)
            d[i + 1] = d[i] + t;
        sum += t;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        printf("%d\n", min(d[b] - d[a], sum - (d[b] - d[a])));
    }
    system("pause");
    return 0;
}

// /**
//  * 分析：一般做法会超时，因为每次查询都需要遍历整个数组
//  *       10^5次操作，10^4次遍历，极端情况下会有10^9次操作导致超出100ms时间限制
//  *       可以用A[i]数组表示1号结点按顺时针方向到达“i号结点顺时针方向的下一个结点”的距离
//  *       然后用差值表示两个结点间的距离，A[i]所代表的距离可以在输入时预处理得到，从而避免超时
//  *       学会用差值表示距离并预处理的方法
//  *       哎我也不知道怎么能想到超时和这种做法，多刷多积累吧。。。
//  **/

// #include <algorithm>
// #include <cstdio>
// using namespace std;
// const int maxn = 100005;

// int main() {
//     int n, query, src, des, tmp, sum = 0;
//     int A[maxn];  // A[i]表示1号结点按顺时针方向到达“i号结点顺时针方向的下一个结点”的距离
//     int D[maxn];  // D[i]表示第i个点和第i+1点之间的距离
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &D[i]);
//         sum += D[i];
//         A[i] = sum;
//     }
//     scanf("%d", &query);
//     //这个循环里面比一般做法少了一个循环，因为预处理了，可以避免超时
//     for (int i = 0; i < query; i++) {
//         scanf("%d%d", &src, &des);
//         if (src > des)
//             swap(src, des);
//         tmp = A[des - 1] - A[src - 1];
//         printf("%d\n", min(tmp, sum - tmp));
//     }
//     return 0;
// }

// /*
//     一般做法会超时，扣三分。。。

//     int main() {
//         int N, M, src, des, tmp, dis = 0, sum = 0;
//         int D[maxn]; //D[i]表示第i个点和第i+1点之间的距离
//         scanf("%d", &N);
//         for(int i = 1; i <= N; i++) {
//             scanf("%d", &D[i]);
//             sum += D[i];
//         }
//         scanf("%d", &M);
//         for(int i = 0; i < M; i++) {
//             scanf("%d%d", &src, &des);
//             if(src > des)
//                 swap(src, des);
//             for(int j = src; j < des; j++) {
//                 dis += D[j];
//             }
//             printf("%d\n", min(dis, sum - dis));
//             dis = 0;
//         }
//         return 0;
//     }
// */
