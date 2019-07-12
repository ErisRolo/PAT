#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;

int a[maxn];

int main() {
    int n, s1 = 0, s2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    // nth_element(a,a+n/2,a+n);
    for(int i = 0; i < n; i++) {
        if(i < n / 2)
            s1 += a[i];
        else
            s2 += a[i];
    }
    cout << n % 2 << ' ' << s2 - s1 << endl;
    return 0;
}
