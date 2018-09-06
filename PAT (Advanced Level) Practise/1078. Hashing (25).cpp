#include <cstdio>
#include <cmath>
const int maxn = 10010;

int Tsize, n;
int hash[maxn];
bool flag = false;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int H(int key) {
    return key % Tsize;
}

int main() {
    int temp, h;
    scanf("%d%d", &Tsize, &n);
    while(!isPrime(Tsize))
        Tsize++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(hash[H(temp)] == 0) {
            hash[H(temp)] = temp;
            printf("%d", H(temp));
        } else {
            flag = false;
            for(int k = 1; k <= Tsize / 2; k++) {
                int h = H(temp) + k * k;
                if(h >= Tsize)
                    h = h % Tsize;
                if(hash[h] == 0) {
                    hash[h] = temp;
                    flag = true;
                    break;
                }
            }
            if(flag == true)
                printf("%d");
            else
                printf("-");
        }
        if(i != n - 1)
            printf(" ");
    }
    return 0;
}
