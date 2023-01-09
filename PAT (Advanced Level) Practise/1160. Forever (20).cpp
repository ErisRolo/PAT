#include <bits/stdc++.h>
using namespace std;

struct answer {
    int n, A;
};

bool cmp(answer a, answer b) {
    if (a.n != b.n)
        return a.n < b.n;
    else
        return a.A < b.A;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}

int calSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N, k, m;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &k, &m);  // k>3 则尾数必为99
        printf("Case %d\n", i);
        vector<answer> ans;
        int tm = m - 18;  //只需计算剩余几位的和为tm
        int minn = pow(10, k - 3), maxn = pow(10, k - 2);
        // cout<<"minn="<<minn<<" maxn="<<maxn<<endl;
        for (int tA = minn; tA < maxn; tA++) {
            // cout<<"sum="<<calSum(tA)<<endl;
            if (calSum(tA) == tm) {
                int A = tA * 100 + 99;
                int B = A + 1;
                int n = calSum(B);
                if (isPrime(gcd(m, n)) && gcd(m, n) > 2) {
                    ans.push_back({n, A});
                }
            }
        }
        if (ans.size() != 0) {
            sort(ans.begin(), ans.end(), cmp);
            for (int i = 0; i < ans.size(); i++) {
                printf("%d %d\n", ans[i].n, ans[i].A);
            }
        } else {
            printf("No Solution\n");
        }
    }
    return 0;
}