/**
* 分析：多项式相乘问题，先输入第一个多项式，用数组存储
*       然后输入第二个多项式，每输入一项，便与第一个多项式的每一项相乘
*       将结果存到结果数组中，最后统计非零项个数逆序输出即可
*       注意次数的范围是0到1000，乘积最高次可到2000，所以结果数组最少要开到2001
*       之前多项式相加只用了一个数组，现在多项式相乘需要用三个。。。
**/

#include <cstdio>
const int maxn = 2001;

int main() {
    int K, n, count = 0; //K为循环次数，n为指数，count用来统计非零项个数
    double temp, a[maxn] = {}, b[maxn] = {}, res[maxn] = {};
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        scanf("%d%lf", &n, &temp);
        a[n] = temp;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        scanf("%d%lf", &n, &temp);
        b[n] = temp;
        //用输入的这一项与已知多项式每一项相乘再输入下一项
        for(int j = 0; j < maxn; j++) {
            if(a[j] != 0) {
                res[n + j] += b[n] * a[j];
            }
        }
    }
    for(int i = 0; i < maxn; i++) {
        if(res[i] != 0)
            count++;
    }
    printf("%d", count);
    for(int i = maxn - 1; i >= 0; i--) {
        if(res[i] != 0)
            printf(" %d %.1f", i, res[i]);
    }
}
