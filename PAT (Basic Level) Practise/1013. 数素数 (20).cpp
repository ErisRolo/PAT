/**
* 分析：抓紧做课设 然后今天一定要刷完概率
**/

#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, m, p = 2, num, cnt = 0, block = 0;
    scanf("%d%d", &n, &m);
    num = m - n + 1;
    while(cnt < n) {
        if(isPrime(p))
            cnt++;
        p++;
    }
    p--;
    cnt = 0;
    for(; cnt < num; p++) {
        if(isPrime(p)) {
            printf("%d", p);
            cnt++;
            block++;
            if(block < 10 && cnt != num)
                printf(" ");
            if(block == 10) {
                printf("\n");
                block = 0;
            }
        }
    }
    return 0;
}
