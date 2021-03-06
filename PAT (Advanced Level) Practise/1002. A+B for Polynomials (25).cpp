/**
* 分析：两个多项式求和，用一个double型数组存储多项式
*       数组下标表示幂次，元素值表示系数
*       先输入第一个多项式进行存储，输入第二个多项式时直接累加
*       统计非零项项数后按格式输出即可
*       注意保留一位小数，而且末尾没有空格
**/

#include <cstdio>
const int maxn = 1010;

int main() {
    int k, n, cnt = 0;
    double a, p[maxn] = {0};
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] = a;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    for(int i = 0; i < maxn; i++) {
        if(p[i] != 0)
            cnt++;
    }
    printf("%d", cnt);
    for(int i = maxn - 1; i >= 0; i--) {
        if(p[i] != 0)
            printf(" %d %.1f", i, p[i]);
    }
    return 0;
}
