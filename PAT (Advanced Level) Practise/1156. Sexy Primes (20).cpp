#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool isSexy(int n) {
    if (isPrime(n)) {
        if (isPrime(n - 6) || isPrime(n + 6))
            return true;
        else
            return false;
    } else
        return false;
}
int main() {
    int n;
    scanf("%d", &n);
    if (isSexy(n)) {
        printf("Yes\n");
        if (isPrime(n - 6))
            printf("%d\n", n - 6);
        else
            printf("%d\n", n + 6);
    } else {
        printf("No\n");
        while (!isSexy(n))
            n++;
        printf("%d\n", n);
    }
    return 0;
}
