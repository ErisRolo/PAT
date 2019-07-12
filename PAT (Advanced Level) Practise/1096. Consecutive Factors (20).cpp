#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;

int main() {
    scanf("%lld", &n);
    LL maxlen = 0, ansi = 2;
    for(LL i = 2; i <= sqrt(n); i++) {
        LL temp = 1, j = i;
        while(1) {
            temp *= j;
            if(n % temp != 0)
                break;
            if(j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                ansi = i;
            }
            j++;
        }
    }
    if(maxlen == 0) {
        printf("1\n");
        printf("%lld", n);
    } else {
        printf("%lld\n", maxlen);
        for(LL i = ansi; i < ansi + maxlen; i++) {
            printf("%lld", i);
            if(i != ansi + maxlen - 1)
                printf("*");
        }
    }
    return 0;
}
