/**
* 分析：简单题，暴力解决
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];
int h[maxn];
bool lonely[maxn];
set<int> ans;

int main() {
    fill(lonely, lonely + maxn, true);
    int n, m, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        h[a] = b;
        h[b] = a;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &d[i]);
    for(int i = 0; i < m; i++) {
        int temp = h[d[i]];
        for(int j = i; j < m; j++) {
            if(d[j] == temp) {
                lonely[temp] = lonely[d[i]] = false;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(lonely[d[i]] == true)
            ans.insert(d[i]);
    }
    int num = ans.size(), i = 0;
    printf("%d\n", num);
    for(auto it = ans.begin(); it != ans.end(); it++) {
        printf("%05d", *it);
        i++;
        if(i != num)
            printf(" ");
    }
    return 0;
}
