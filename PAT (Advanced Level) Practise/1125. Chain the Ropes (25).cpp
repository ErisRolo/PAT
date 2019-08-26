/**
* 分析：chain的操作实际就是两个数相加除以2
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

double d[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &d[i]);
    sort(d, d + n);
    int ans = (int)((d[0] + d[1]) / 2);
    for(int i = 2; i < n; i++)
        ans = (int)((ans + d[i]) / 2);
    printf("%d", ans);
    return 0;
}
