/**
* 分析：用了32分钟，比柳神多一倍的代码量，只拿了23分，还有一个2分的点没拿到。。。
*       分析原因可能是个别数据输出格式有误，不容易找出是哪里的数据
*       然后将用来判断输出格式的三个bool变量，是否第一次输出负数、是否有负数、是否有小于K的数
*       改为用一个bool变量控制输出，即是否第一次输出数据，成功A掉题目
*       因为这三种情况的输出格式实质上都是与是不是第一次输出有关，无论是什么类型的数据，输出格式是一样的
*       判断前面有什么数据反而复杂化了问题，既然输出格式一样，就没有必要分别讨论每种情况，用一种思维去分别判断三中情况就好
*       还是多思考多积累多总结
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.order == -1 || b.order == -1)
        return a.order > b.order;
    else
        return a.order < b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = -1;
    int begin, n, k;
    int address, data, next;
    scanf("%d %d %d", &begin, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, count = 0;
    while(p != -1) {
        node[p].order = ++count;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int isFirst = 1;
    for(int i = 0; i < count; i++) {
        if(node[i].data < 0) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    for(int i = 0; i < count; i++) {
        if(node[i].data >= 0 && node[i].data <= k) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    for(int i = 0; i < count; i++) {
        if(node[i].data > k) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    printf("-1");
    return 0;
}
