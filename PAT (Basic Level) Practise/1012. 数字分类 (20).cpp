/**
* 分析：A2可能为0，所以输出时不能用≠0作为判断条件
*       服球了什么傻逼测试点
**/

#include <cstdio>

int main() {
    int n, d;
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    int f = 1, cnt = 0;
    bool flag=false;
    float a4 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &d);
        if(d % 5 == 0 && d % 2 == 0)
            a1 += d;
        else if(d % 5 == 1) {
            a2 += f * d;
            f *= -1;
            flag=true;
        } else if(d % 5 == 2)
            a3++;
        else if(d % 5 == 3) {
            a4 += d;
            cnt++;
        } else if(d % 5 == 4) {
            if(d > a5)
                a5 = d;
        }
    }
    if(a4 != 0)
        a4 = a4 / cnt;
    if(a1 != 0)
        printf("%d ", a1);
    else
        printf("N ");
    if(flag)
        printf("%d ", a2);
    else
        printf("N ");
    if(a3 != 0)
        printf("%d ", a3);
    else
        printf("N ");
    if(a4 != 0)
        printf("%.1f ", a4);
    else
        printf("N ");
    if(a5 != 0)
        printf("%d", a5);
    else
        printf("N");
    return 0;
}
