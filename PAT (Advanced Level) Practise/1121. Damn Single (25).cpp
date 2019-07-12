#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int couple[maxn], gest[maxn];
bool f[maxn];
vector<int>ans;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        couple[x] = y;
        couple[y] = x;
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &gest[i]);
        f[gest[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        if (f[couple[gest[i]]] == true)
            continue;
        else
            ans.push_back(gest[i]);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%05d", ans[i]);
        if (i != ans.size() - 1)
            printf(" ");
    }
    return 0;
}
