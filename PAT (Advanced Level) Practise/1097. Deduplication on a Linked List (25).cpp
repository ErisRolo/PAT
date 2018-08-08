/**
* 分析：链表处理，找出绝对值相同的数字，第一个序列只留一个，其余的放到第二个序列
*       可以将链表从小到大排序，无效结点的顺序设为2*maxn
*       然后在1 - maxn放第一个序列，在maxn+1 - 2*maxn放第二序列，分别输出即可
*       就是以后对-1特判，不要写i < count-1然后再输出count-1
*       尽量写成if(i != count-1)  else  的样子，有时候方便处理多个序列的输出
*       这题还是挺好的，思路一定要顺，不要总想着在步骤⑤的输出上搞事情
*       可以在步骤③有骚操作直接把组分好，然后步骤⑤仅输出就好
*       总之还是不要太生硬地套模板，要有自己的思路，模板只提供主体框架
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

bool isExist[maxn] = {false};

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = 2 * maxn;
    int begin, n;
    int address, data, next;
    scanf("%d %d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, cnt1 = 0, cnt2 = 0;
    while(p != -1) {
        if(isExist[abs(node[p].data)] == false) {
            isExist[abs(node[p].data)] = true;
            node[p].order = ++cnt1;
        } else {
            node[p].order = ++cnt2 + maxn;
        }
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int count = cnt1 + cnt2;
    for(int i = 0; i < count; i++) {
        if(i != cnt1 - 1 && i != count - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        else
            printf("%05d %d -1\n", node[i].address, node[i].data);
    }
    return 0;
}
