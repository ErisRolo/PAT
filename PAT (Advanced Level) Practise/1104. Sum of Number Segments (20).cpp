/**
* 分析：找规律
*       数据更新，需要long double
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long double tmp, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp * (n - i) * (i + 1);
    }
    printf("%.2Lf\n", sum);
    return 0;
}
