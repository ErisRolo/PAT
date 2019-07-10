#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    int a, b;
    scanf("%d/%d", &a, &b);
    int t = gcd(a, b);
    a = a / t, b = b / t;
    for(int i = 1; i < n; i++) {
        int c, d;
        scanf("%d/%d", &c, &d);
        a = a * d + b * c;
        b = b * d;
        int t = gcd(a, b);
        a = a / t, b = b / t;
    }
    if(a % b == 0)
        printf("%d", a / b);
    else {
        if(abs(a) > abs(b)) {
            if(a > 0)
                printf("%d %d/%d", a / b, a - a / b * b, b);
            else {
                a = -a;
                printf("-%d %d/%d", a / b, a - a / b * b, b);
            }
        } else
            printf("%d/%d", a, b);
    }
    return 0;
}
