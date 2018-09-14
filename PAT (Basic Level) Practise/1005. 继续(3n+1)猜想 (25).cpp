/**
* 分析：3n+1猜想，所以要注意3n+1的范围，数组要开大，不然会有段错误
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
int h[10000];
vector<int> v, ans;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        int n = v[i];
        if(h[n] == 0) {
            while(n != 1) {
                if(n % 2 == 0) {
                    n = n / 2;
                } else {
                    n = 3 * n + 1;
                    n = n / 2;
                }
                h[n] = 1;
            }
        }
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        if(h[v[i]] == 0)
            ans.push_back(v[i]);
    }
    for(int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
        if(i != ans.size() - 1)
            printf(" ");
    }
    return 0;
}
