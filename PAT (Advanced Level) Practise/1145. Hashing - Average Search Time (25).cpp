/**
* 分析：平方探测法，要求掌握Hash基本概念，插入时0 - Tsize-1，查找时0 - Tsize
*        不要轻易用bool数组，容易段错误和超时
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int Tsize, n, m;
int h[maxn];
bool flag;

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

int H(int key) {
    return key % Tsize;
}

int main() {
    scanf("%d%d%d", &Tsize, &n, &m);
    while(!isPrime(Tsize))
        Tsize++;
    int temp, key;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        for(int k = 0; k <= Tsize; k++) {
            int pos = H(temp) + k * k;
            if(pos >= Tsize)
                pos = pos % Tsize;
            if(h[pos] == 0) {
                h[pos] = temp;
                flag = true;
                break;
            }
        }
        if(flag == false)
            printf("%d cannot be inserted.\n", temp);
        flag = false;
    }
    int query, cnt = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d", &query);
        for(int j = 0; j <= Tsize; j++) {
            cnt++;
            int pos = H(query) + j * j;
            if(pos >= Tsize)
                pos = pos % Tsize;
            if(h[pos] == query || h[pos] == 0) {
                break;
            }
        }
    }
    printf("%.1f", cnt * 1.0 / m);
    return 0;
}

