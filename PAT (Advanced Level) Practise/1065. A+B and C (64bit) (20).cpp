#include <cstdio>

int main () {
    int T, tcase = 1;
    scanf("%d", &T);
    while(T--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long res = a + b; //res存放a+b的结果
        bool flag;
        if (a > 0 && b > 0 && res < 0)
            flag = true; //正溢出为true
        else if(a < 0 && b < 0 && res >= 0)
            flag = false; //负溢出为false
        else if(res > c)
            flag = true; //无溢出时，A+B>c时为true
        else
            flag = false; //无溢出时，A+B<=C时为false
        if(flag == true)
            printf("Case #%d: true\n", tcase++ );
        else
            printf("Case #%d: false\n", tcase++ );
    }
    return 0;
}
