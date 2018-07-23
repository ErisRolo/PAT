#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n < 2)
        return false;
    for(int i = 2; i < int(sqrt(n)) + 1; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int get_reverse(int N, int D) {
    int a[999];
    int cnt =  0;
    while(N > 0) {
        a[cnt++] = N % D;
        N = N / D;
    }
    int rev = 0;
    for(int i = 0; i < cnt; i++) {
        rev = rev * D + a[i];
    }
    // printf("rev is %d\n", rev);
    return rev;
}

void print(int N, int D) {
    if(!isPrime(N))
        printf("No\n");
    else {
        int rev = get_reverse(N, D);
        // printf("\nrev is %d\n",rev);
        if(!isPrime(rev))
            printf("No\n");
        else
            printf("Yes\n");
    }
}

int main() {
    while(true) {
        int N, D;
        scanf("%d", &N);
        if(N < 0)
            break;
        else {
            scanf("%d", &D);
            print(N, D);
        }
    }
    return 0;
}
