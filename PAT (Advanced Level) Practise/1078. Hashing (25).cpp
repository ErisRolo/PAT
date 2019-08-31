/**
* 分析：Hash平方检测法标准写法
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int Tsize, n, key;
int h[maxn];

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &Tsize, &n);
    while(!isPrime(Tsize))
        Tsize++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        int hkey = key % Tsize;
        int k;
        for(k = 0; k < Tsize; k++) {
            int pos = (hkey + k * k) % Tsize;
            if(h[pos] == 0) {
                h[pos] = key;
                printf("%d", pos);
                break;
            }
        }
        if(k >= Tsize)
            printf("-");
        if(i != n - 1)
            printf(" ");
    }
    return 0;
}
