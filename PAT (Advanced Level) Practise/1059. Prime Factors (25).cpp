/**
* 分析：分解质因子，套模板即可，但要注意特判 1
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;

struct factor {
    int x, cnt;
} fac[10];

int prime[maxn], pnum = 0;
bool p[maxn] = {false}; //false表明为素数
void Find_Prime() {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            prime[pnum++] = i;
            for(int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    Find_Prime();
    LL n;
    scanf("%lld", &n);
    LL res = n;
    int sqr = (int)sqrt(1.0 * n);
    int num = 0;
    for(int i = 0; i < pnum && prime[i] <= sqr; i++) {
        if(n % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(n % prime[i] == 0) {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
    }
    if(n != 1) {
        fac[num].x = n;
        fac[num].cnt = 1;
        num++;
    }
    printf("%lld=", res);
    if(res == 1)
        printf("1"); // 特判 1
    for(int i = 0; i < num; i++) {
        printf("%d", fac[i].x);
        if(fac[i].cnt != 1) {
            printf("^%d", fac[i].cnt);
        }
        if(i != num - 1)
            printf("*");
    }
    return 0;
}
