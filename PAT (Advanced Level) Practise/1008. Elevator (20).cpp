/**
* 分析：简单题，直译即可，希望9.8PAT出这种难度的。。。
**/

#include <cstdio>

int main() {
    int N;
    int now = 0, to, time = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &to);
        if(to > now) {
            time += 6 * (to - now) + 5;
        } else {
            time += 4 * (now - to) + 5;
        }
        now = to;
    }
    printf("%d", time);
    return 0;
}
