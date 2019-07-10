#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b) ;
}

void func(long long m, long long n) {
    int flag1 = 0, flag2 = 0, flag = 0;
    if(n == 0) {
        printf("Inf");
        return ;
    }
    if(m == 0) {
        printf("0");
        return ;
    }
    if(m < 0)
        flag1 = 1;
    if(n < 0)
        flag2 = 1;
    m = abs(m), n = abs(n);
    if(flag1 == 1 && flag2 == 1)
        flag = 0;
    else if(flag1 == 1 || flag2 == 1)
        flag = 1;
    if(m == n) {
        if(flag == 1)
            printf("(-1)");
        else
            printf("1");
        return ;
    }
    long long x = m % n, y = m / n;
    if(x == 0) {
        if(flag == 0)
            printf("%d", y);
        else
            printf("(-%d)", y);
        return ;
    } else {
        long long t1 = m - y * n, t2 = n, t = gcd(t1, t2);
        t1 /= t, t2 /= t;
        if(flag == 1) {
            printf("(-");
            if(y == 0) {
                printf("%lld/%lld", t1, t2);
            } else {
                printf("%lld %lld/%lld", y, t1, t2);
            }
            printf(")");
        } else {
            if(y == 0) {
                printf("%lld/%lld", t1, t2);
            } else {
                printf("%lld %lld/%lld", y, t1, t2);
            }
        }
    }
}

int main() {
    long long int a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
//	printf("%lld %lld %lld %lld",a,b,c,d);
    func(a, b);
    printf(" + ");
    func(c, d);
    printf(" = ");
    func(a * d + c * b, b * d);
    printf("\n");
    func(a, b);
    printf(" - ");
    func(c, d);
    printf(" = ");
    func(a * d - c * b, b * d);
    printf("\n");
    func(a, b);
    printf(" * ");
    func(c, d);
    printf(" = ");
    func(a * c, b * d);
    printf("\n");
    func(a, b);
    printf(" / ");
    func(c, d);
    printf(" = ");
    func(a * d, b * c);
    printf("\n");
    return 0;
}
