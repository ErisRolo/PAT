#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int a[maxn], n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = a[0];
    for(int i = 1; i < n; i++) {
        ans = (ans + a[i]) / 2;
    }
    printf("%d", ans);
    return 0;
}
