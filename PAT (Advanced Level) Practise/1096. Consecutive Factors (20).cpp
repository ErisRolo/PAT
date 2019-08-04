/**
* 分析：表面分解质因子，实际是最长连续子列问题
*       整数n不能被大于sqrt(n)的数整除（除了它本身），只需遍历2-sqrt(n)，在线处理即可
*       读清题意，最后要求输出的是最大长度，而不是整除的结果！！！
*       还有题目数据上界是2^31，所以要用long long，防止乘积溢出
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n;
    scanf("%lld", &n);
    LL sqr = (LL)sqrt(1.0 * n);
    LL ans, maxlen = 0;
    for(LL i = 2; i <= sqr; i++) {
        if(n % i == 0) {
            LL j = i, temp = 1, len = 0;
            while(j <= sqr) {
                temp *= j;
                if(n % temp == 0) {
                    len++;
                    j++;
                } else
                    break;
            }
            if(len > maxlen) {
                maxlen = len;
                ans = i;
            }
        }
    }
    if(maxlen == 0)
        printf("1\n%lld", n);
    else if(maxlen == 1)
        printf("1\n");
    else
        printf("%lld\n", maxlen);
    for(LL i = 0; i < maxlen; i++) {
        printf("%lld", ans);
        if(i != maxlen - 1)
            printf("*");
        ans++;
    }
    return 0;
}
