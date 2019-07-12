#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int now = 1;
    int E = a[1] - 1;
    for(int i = a[1]; i <= a[n]; i++) {
        if(n - now + 1 < i )
            break;
        while(a[now] <= i && now <= n)
            now++;
        if(n - now + 1 >= i)
            E = i;
    }
    printf("%d\n", E);
    return 0;
}
