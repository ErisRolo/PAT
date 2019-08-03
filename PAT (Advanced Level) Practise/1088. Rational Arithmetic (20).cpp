/**
* 分析：分数四则运算，套模板即可，加减乘除写出一个基本就是复制粘贴了，不过作为20分的题感觉还是很费时间
*       所以一定要熟练，要能迅速地把模板写出来
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef long long LL;

struct Fraction {
    LL up, down;
};

LL gcd(LL a, LL b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

Fraction reduction(Fraction f) {
    if(f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0) {
        f.down = 1;
    } else {
        LL d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}

void showFraction(Fraction f) {
    if(f.up < 0)
        printf("(");
    if(f.down == 1)
        printf("%lld", f.up);
    else if(abs(f.up) > f.down)
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld", f.up, f.down);
    if(f.up < 0)
        printf(")");
}

int main() {
    Fraction a, b, c1, c2, c3, c4;
    scanf("%lld/%lld", &a.up, &a.down);
    a = reduction(a);
    scanf("%lld/%lld", &b.up, &b.down);
    b = reduction(b);
    //加法
    c1.up = a.up * b.down + b.up * a.down;
    c1.down = a.down * b.down;
    c1 = reduction(c1);
    showFraction(a);
    printf(" + ");
    showFraction(b);
    printf(" = ");
    showFraction(c1);
    printf("\n");
    //减法
    c2.up = a.up * b.down - b.up * a.down;
    c2.down = a.down * b.down;
    c2 = reduction(c2);
    showFraction(a);
    printf(" - ");
    showFraction(b);
    printf(" = ");
    showFraction(c2);
    printf("\n");
    //乘法
    c3.up = a.up * b.up;
    c3.down = a.down * b.down;
    c3 = reduction(c3);
    showFraction(a);
    printf(" * ");
    showFraction(b);
    printf(" = ");
    showFraction(c3);
    printf("\n");
    //除法
    c4.up = a.up * b.down;
    c4.down = a.down * b.up;
    c4 = reduction(c4);
    showFraction(a);
    printf(" / ");
    showFraction(b);
    printf(" = ");
    if(b.up == 0 && b.down == 1)
        printf("Inf"); //对除数为0进行特判
    else
        showFraction(c4);
    return 0;
}
