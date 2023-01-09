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
    int b1, b2, n, address;
    scanf("%d%d%d", &b1, &b2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        node[address].address = address;
        scanf("%d%d", &node[address].data, &node[address].next);
    }
    int p1 = b1, cnt1 = 0;
    while (p1 != -1) {
        cnt1++;
        p1 = node[p1].next;
    }
    int p2 = b2, cnt2 = 0;
    while (p2 != -1) {
        cnt2++;
        p2 = node[p2].next;
    }
    int cnt = cnt1 + cnt2;
    if (cnt2 > cnt1) {  //长的链表设为b1
        swap(b1, b2);
        swap(cnt1, cnt2);
    }
    int ord = 1;
    p1 = b1;
    while (p1 != -1) {
        node[p1].order = ord++;
        p1 = node[p1].next;
    }
    p2 = b2;
    while (p2 != -1) {
        node[p2].order = ord++;
        p2 = node[p2].next;
    }
    sort(node, node + maxn, cmp);
    int j = 0;
    if (cnt1 != 0 && cnt2 != 0) {
        for (int i = 0; i < cnt1; i++) {
            printf("%05d %d ", node[i].address, node[i].data);
            j++;
            if (j % 2 == 0 && j != 0 && j / 2 <= cnt2) {
                printf("%05d\n", node[cnt - j / 2].address);
                printf("%05d %d ", node[cnt - j / 2].address, node[cnt - j / 2].data);
                if (i != cnt1 - 1)
                    printf("%05d\n", node[i + 1].address);
                else
                    printf("-1\n");
            } else {
                if (i != cnt1 - 1)
                    printf("%05d\n", node[i + 1].address);
                else
                    printf("-1\n");
            }
        }
    }
    if (cnt1 != 0 && cnt2 == 0) {
        for (int i = 0; i < cnt1; i++) {
            if (i != cnt1 - 1)
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else
                printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    if (cnt1 == 0 && cnt2 != 0) {
        for (int i = 0; i < cnt2; i++) {
            if (i != cnt2 - 1)
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else
                printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    if (cnt1 == 0 && cnt2 == 0) {
        printf("0 -1\n");
    }
    return 0;
}