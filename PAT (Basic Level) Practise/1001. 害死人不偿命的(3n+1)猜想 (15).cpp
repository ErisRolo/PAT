/**
* 分析：放松。。。心态要平和。。。
**/

#include <cstdio>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while(n != 1) {
        if(n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
            n = n / 2;
        }
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
