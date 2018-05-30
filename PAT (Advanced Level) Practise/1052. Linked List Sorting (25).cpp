#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;

//定义静态链表（步骤1）
struct Node {
    int address, data, next;
    bool flag; //结点是否在链表上

} node[maxn];

bool cmp(Node a, Node b) {
    if (a.flag == false || b.flag == false)
        return a.flag > b.flag; //只要a和b中有一个无效结点，就把它放后面去
    else
        return a.data < b.data; //如果都是有效结点，则按要求排序
}

int main() {
    //初始化（步骤2）
    for (int i = 0; i < maxn; i++)
        node[i].flag = false;
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int count = 0, p = begin;
    //枚举链表，对flag进行标记，同时计数有效结点个数（步骤3）
    while (p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if (count == 0) {
        //特判，新链表中没有结点时输出0 -1
        printf("0 -1");
    } else {
        //筛选有效结点，并按data从小到大排序（步骤4）
        sort(node, node + maxn, cmp);
        //输出结果（步骤5）
        //防止-1被%05d化，提前判断
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; i++) {
            if (i != count - 1)
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else
                printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}
