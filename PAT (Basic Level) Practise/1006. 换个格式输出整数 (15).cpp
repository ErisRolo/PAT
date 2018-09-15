/**
* 分析：放松一下
**/

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int b, s, d;
    b = n / 100;
    s = n / 10 % 10;
    d = n - b * 100 - s * 10;
    for(int i = 0; i < b; i++)
        printf("B");
    for(int i = 0; i < s; i++)
        printf("S");
    for(int i = 1; i <= d; i++)
        printf("%d", i);
    return 0;
}
