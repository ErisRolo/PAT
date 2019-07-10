#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target, num;
    cin >> n >> target;
    vector<int> sum(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> num;
        sum[i + 1] = sum[i] + num;
    }
    vector<int> res(n + 1);
    int mm = 999999999;
    for(int i = 1; i <= n; i++) {
        int left = i, right = n;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(sum[mid] - sum[i - 1] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(sum[right] - sum[i - 1] >= target) {
            if(sum[right] - sum[i - 1] < mm)
                mm = sum[right] - sum[i - 1];
            res[i] = right;
        } else
            break;
    }
    for(int i = 1; i <= n; i++) {
        if(sum[res[i]] - sum[i - 1] == mm)
            printf("%d-%d\n", i, res[i]);
    }
    return 0;
}
