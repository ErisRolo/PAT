/**
* 分析：不要影响初试
**/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> p;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void init() {
    for(int i = 2; i < 100000; i++) {
        if(isPrime(i))
            p.push_back(i);
    }
}

int main() {
    init();
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i < p.size(); i++) {
        if(p[i] <= n && p[i] - p[i - 1] == 2)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}
