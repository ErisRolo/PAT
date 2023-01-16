/**
 * 分析：待更新
 **/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int n, in[maxn];
map<int, int> ans;

void deal(int index, int L, int R) {
    if (L > R)
        return;
    int pos = L;
    for (int i = L + 1; i <= R; i++)
        if (in[i] < in[pos])
            pos = i;
    ans[index] = in[pos];
    deal(index << 1, L, pos - 1);
    deal(index << 1 | 1, pos + 1, R);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    deal(1, 0, n - 1);
    for (auto it : ans) {
        if (it.first != 1)
            cout << ' ';
        cout << it.second;
    }
    return 0;
}