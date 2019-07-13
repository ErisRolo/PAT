#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;

struct node {
    int index, times;
    bool operator<(const node&x)const {
        return times == x.times ? index<x.index : times > x.times;
    }
    node(int _x, int _y) : index(_x), times(_y) {}
};

int timet[maxn];
set<node>s;

int main() {
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i == 0) {
            timet[x]++;
            s.insert(node(x, timet[x]));
            continue;
        }
        printf("%d:", x);
        int cnt = 0;
        for (auto it = s.begin(); cnt < k && it != s.end(); it++, cnt++)
            printf(" %d", it->index);
        printf("\n");
        auto it = s.find(node(x, timet[x]));
        if (it != s.end())
            s.erase(it);
        timet[x]++;
        s.insert(node(x, timet[x]));
    }
    return 0;
}
