#include <cstdio>
const int maxn = 1010;

struct Student {
    long long id; //准考证号
    int examSeat; //考试座位号
} testSeat[maxn]; //以试机座位号作为下标来记录考生

int main() {
    int n, m, seat, examSeat;
    long long id;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %d %d", &id, &seat, &examSeat);
        testSeat[seat].id = id;
        testSeat[seat].examSeat = examSeat;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &seat);
        printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
    }
    return 0;
}
