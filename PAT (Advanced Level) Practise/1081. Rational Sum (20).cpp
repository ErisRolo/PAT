/**
* 分析：分数加法运算，套模板即可，在刚记忆过的情况下不到20分钟AC
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef long long LL;

struct Fraction {
    LL up, down;
} f[maxn];

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
    if(f.down == 1) {
        printf("%lld", f.up);
    } else if(f.up > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
}

int main() {
    int n;
    Fraction temp, res;
    LL up, down;
    scanf("%d", &n);
    scanf("%lld/%lld", &temp.up, &temp.down);
    f[0] = reduction(temp);
    res = f[0];
    for(int i = 1; i < n; i++) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        f[i] = reduction(temp);
        res.up = res.up * f[i].down + f[i].up * res.down;
        res.down *= f[i].down;
        res = reduction(res);
    }
    showFraction(res);
    return 0;
}
