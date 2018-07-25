#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;

int h[55];
int tmp[55];
int result[55];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= 54; i++) {
        scanf("%d", &h[i]);
        result[i] = i; // 初始化, 第 i 个放在 i 位置
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 54; j++) {
            int num = result[j]; // 枚举第 i 个数字
            // h[j] 表示把 num 放到 h[j] 位置上去
            tmp[h[j]] = num;
        }
        for( int j = 1; j <= 54; j++) {
            result[j] = tmp[j];
        }
    }
    // 1   2         13  14  .........26
    // S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2
    for (int i = 1; i <= 54; i++) {
        int c = (result[i] - 1) / 13 + 1; // 第几组
        if (i == 1) {

            switch (c) {
            case 1:
                printf("S%d", result[i] - 13 * (c - 1));
                break;
            case 2:
                printf("H%d", result[i] - 13 * (c - 1));
                break;
            case 3:
                printf("C%d", result[i] - 13 * (c - 1));
                break;
            case 4:
                printf("D%d", result[i] - 13 * (c - 1));
                break;
            case 5:
                printf("J%d", result[i] - 13 * (c - 1));
            }
        } else {
            switch (c) {
            case 1:
                printf(" S%d", result[i] - 13 * (c - 1));
                break;
            case 2:
                printf(" H%d", result[i] - 13 * (c - 1));
                break;
            case 3:
                printf(" C%d", result[i] - 13 * (c - 1));
                break;
            case 4:
                printf(" D%d", result[i] - 13 * (c - 1));
                break;
            case 5:
                printf(" J%d", result[i] - 13 * (c - 1));
            }
        }
    }
    return 0;
}
