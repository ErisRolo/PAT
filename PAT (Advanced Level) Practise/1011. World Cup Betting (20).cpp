#include <cstdio>

char S[3] = { 'W', 'T', 'L' };

int main() {
    double ans = 1.0, tmp, a;
    int idx; //记录每行最大数字的下标
    for (int i = 0; i < 3; i++) {
        tmp = 0.0;
        //寻找该行最大的数字存于tmp
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a);
            if (a > tmp) {
                tmp = a;
                idx = j;
            }
        }
        ans *= tmp;
        printf("%c ", S[idx]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
