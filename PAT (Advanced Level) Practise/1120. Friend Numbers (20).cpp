#include <cstdio>
const int maxn = 10010;

int hash[maxn];

int main() {
    int n;
    int num, sum = 0, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        if(hash[sum] == 0) {
            hash[sum]++;
            count++;
        } else {
            hash[sum]++;
        }
        sum = 0;
    }
    printf("%d\n", count);
    for(int i = 0; i < maxn; i++) {
        if(hash[i] != 0 && count != 1) {
            printf("%d ", i);
            count--;
        } else if(hash[i] != 0 && count == 1)
            printf("%d", i);
    }
    return 0;
}
