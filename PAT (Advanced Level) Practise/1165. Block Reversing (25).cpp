#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    for (int i = 0; i < maxn; i++)
        node[i].order = maxn;
    int begin, n, k, block;
    int address, data, next;
    scanf("%d %d %d", &begin, &n, &k);
    block = ceil(n / k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, cnt = 0, a, b;
    while (p != -1) {
        cnt++;
        a = (cnt - 1) / k + 1;
        b = cnt - (a - 1) * k;
        node[p].order = (block - a) * k + b;
        // cout << "a=" << a << " b=" << b << " order=" << node[p].order << endl;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    for (int i = 0; i < cnt; i++) {
        if (i != cnt - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        else
            printf("%05d %d -1", node[i].address, node[i].data);
    }
    system("pause");
    return 0;
}