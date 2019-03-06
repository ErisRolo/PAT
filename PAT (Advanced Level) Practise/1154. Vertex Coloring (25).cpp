/**
* 分析：直接存储图会内存超限，改成存储边及其两个顶点
*       用hash和set解决
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

struct edge {
    int a, b;
} Edge[maxn];

int n, m, k, color;
int col[maxn];
bool flag;
set<int> cnt;

int main() {
    fill(col, col + maxn, 101);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &Edge[i].a, &Edge[i].b);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        cnt.clear();
        flag = true;
        for(int j = 0; j < n; j++) {
            scanf("%d", &color);
            col[j] = color;
            cnt.insert(color);
        }
        for(int j = 0; j < m; j++) {
            if(col[Edge[j].a] == col[Edge[j].b]) {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%d-coloring\n", cnt.size());
        else
            printf("No\n");
    }
    return 0;
}
