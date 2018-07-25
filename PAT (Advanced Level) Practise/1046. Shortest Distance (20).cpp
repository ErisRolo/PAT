#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int s = 0;
int sum[100010] = {0};

void get_result(int a, int b) {
    if(a > b)
        swap(a, b);
    int d1 = sum[b] - sum[a];
    int d2 = s - d1;
    printf("%d\n", min(d1, d2));
}
int main() {
    scanf("%d", &N);
    int tmp;
    for(int i = 2; i <= N; i++) {
        scanf("%d", &tmp);
        s += tmp;
        sum[i] = s;
    }
    scanf("%d", &tmp); // tmp 最后表示 第一个到最后一个的距离
    s += tmp;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        get_result(a, b);
    }
    return 0;
}
