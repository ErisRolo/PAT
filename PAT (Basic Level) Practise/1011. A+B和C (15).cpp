#include <cstdio>

int main() {
    int T, tcase = 1;
    scanf("%d", &T); //输入数据组数
    //循环T次
    while (T--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c)
            printf("Case #%d: true\n", tcase++);
        else
            printf("Case #%d: false\n", tcase++);

    }
    return 0;
}
