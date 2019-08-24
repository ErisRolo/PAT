/**
* ·ÖÎö£º¼òµ¥Ìâ
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];

int main() {
    int n, n1, n2;
    int t1 = 0, t2 = 0, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    sort(d, d + n);
    if(n % 2 == 0)
        n1 = n2 = n / 2;
    else
        n1 = n / 2, n2 = n / 2 + 1;
    for(int i = 0; i < n1; i++)
        t1 += d[i];
    for(int i = n1; i < n; i++)
        t2 += d[i];
    printf("%d %d", abs(n1 - n2), abs(t1 - t2));
    return 0;
}
