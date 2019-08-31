/**
* 分析：散列表平均查找时间，除留取余，解决冲突使用正向探测
*       查找成功的次数即找到这个数，查找失败是找到一个空的位置还没有找到或者超过步长超过表长还没有找到
*       要注意的是查找的时候步长要取到Tsize，这样超过表长还没有查找到那次才会算进次数里
*       或者干脆就都取等，反正插入的时候取等就是多查了一次，如果是双向探测是Tsize/2
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int Tsize, n, m, key, q;
double ans = 0;
int h[maxn];

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for(int i = 2; i <= sqr; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    scanf("%d%d%d", &Tsize, &n, &m);
    while(!isPrime(Tsize))
        Tsize++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        int hkey = key % Tsize;
        int k;
        for(k = 0; k < Tsize; k++) { //插入不用取等
            int pos = (hkey + k * k) % Tsize;
            if(h[pos] == 0) {
                h[pos] = key;
                break;
            }
        }
        if(k >= Tsize)
            printf("%d cannot be inserted.\n", key);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &q);
        int hkey = q % Tsize;
        int k;
        for(k = 0; k <= Tsize; k++) { //这里注意取等
            int pos = (hkey + k * k) % Tsize;
            if(h[pos] != q && h[pos] != 0) {
                ans++;
            } else {
                ans++;
                break;
            }
        }
    }
    printf("%.1f\n", ans / m);
    return 0;
}
