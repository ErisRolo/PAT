/**
* 分析：有内味了
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp1(Node a, Node b) {
    return a.order < b.order;
}

bool cmp2(Node a, Node b) {
    return a.order > b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = maxn;
    int begin, n, k, address, data, next;
    scanf("%d%d%d", &begin, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, cnt = 0;
    while(p != -1) {
        node[p].order = cnt++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp1);
    for(int i = 0; i < cnt; i++) {
        if(i + k <= cnt) {
            sort(node + i, node + i + k, cmp2);
            i = i + k - 1;
        } else
            break;
    }
    for(int i = 0; i < cnt; i++) {
        if(i != cnt - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        else
            printf("%05d %d -1", node[i].address, node[i].data);
    }
    return 0;
}






//**
//* 分析：我记错了，链表题还是有一定思维难度的，简单的可能是树的遍历问题。。。
//*       以前写的下标太乱了，这次写的清楚一点
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 100010;
//
//struct Node {
//    int address, data, next;
//    int order;
//} node[maxn];
//
//bool cmp(Node a, Node b) {
//    return a.order < b.order;
//}
//
//int main() {
//    for(int i = 0; i < maxn; i++) {
//        node[i].order = maxn;
//    }
//    int begin, n, k, address;
//    scanf("%d%d%d", &begin, &n, &k);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &address);
//        scanf("%d%d", &node[address].data, &node[address].next);
//        node[address].address = address;
//    }
//    int p = begin, count = 0;
//    while(p != -1) {
//        node[p].order = count++;
//        p = node[p].next;
//    }
//    sort(node, node + maxn, cmp);
//    for(int i = 0; i < count / k; i++) { //重点在于处理每一块最后一个结点的next
//        for(int j = (i + 1) * k - 1; j > i * k; j--) { // (i+1)*k-1即每块的起始点下标为总数减1，结束点下标为i*k，可以举例子写写看
//            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
//        }
//        if(i < count / k - 1) { //如果不是最后一块
//            printf("%05d %d %05d\n", node[i * k].address, node[i * k].data, node[(i + 2)*k - 1].address); //next为下一块的起始点
//        }
//        if(i == count / k - 1) { //如果是最后一块
//            if(count % k == 0) { //如果正好分成整数块，后面没有其他结点
//                printf("%05d %d -1\n", node[i * k].address, node[i * k].data);
//            } else {
//                printf("%05d %d %05d\n", node[i * k].address, node[i * k].data, node[(i + 1)*k].address);
//                for(int t = (i + 1) * k; t < count; t++) {
//                    if(t != count - 1)
//                        printf("%05d %d %05d\n", node[t].address, node[t].data, node[t + 1].address);
//                    else
//                        printf("%05d %d -1\n", node[t].address, node[t].data);
//                }
//            }
//        }
//    }
//    return 0;
//}






//**
//* 分析：链表处理，因此此题要求按顺序输出，因此特殊性质order设为maxn
//*       然后给有效结点编码，从小到大排序即可，这样无效结点都在后面
//*       （其实我设成最小值也实现了从小到大排序，就是多写了两句。。。）
//*       此题要注意第⑤步，对最后一个结点的next地址分情况讨论，思路要清晰
//*       还有即使将有效结点按1 - count排序，数组下标仍是0 - count-1，不要忽略这个问题
//**/
//
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 100010;
//
//struct Node {
//    int address, data, next;
//    int order;
//} node[maxn];
//
//bool cmp(Node a, Node b) {
//    if(a.order == -1 || b.order == -1)
//        return a.order > b.order;
//    else
//        return a.order < b.order;
//}
//
//int main() {
//    for(int i = 0; i < maxn; i++)
//        node[i].order = -1;
//    int begin, n, k;
//    int address, data, next;
//    scanf("%d %d %d", &begin, &n, &k);
//    for(int i = 0; i < n; i++) {
//        scanf("%d %d %d", &address, &data, &next);
//        node[address].address = address;
//        node[address].data = data;
//        node[address].next = next;
//    }
//    int p = begin, count = 0;
//    for(int i = 1; p != -1; i++) {
//        node[p].order = i;
//        p = node[p].next;
//        count++;
//    }
//    sort(node, node + maxn, cmp);
//    //步骤⑤
//    for(int i = 1; i <= count / k; i++) {
//        for(int j = i * k - 1; j > 0 + (i - 1)*k; j--)
//            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
//        //将每一块的最后一个结点单独输出，根据其next地址分情况讨论
//        if(i < count / k) { //不是最后一块
//            printf("%05d %d %05d\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data, node[(i + 1)*k - 1].address);
//        } else if(i == count / k) { //是最后一块
//            if(count % k == 0) { //是最后一个结点（即没有不成块的剩余结点）
//                printf("%05d %d -1\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data);
//            } else { //不是最后一个结点
//                printf("%05d %d %05d\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data, node[i * k].address);
//                for(int t = i * k ; t < count - 1; t++)
//                    printf("%05d %d %05d\n", node[t].address, node[t].data, node[t + 1].address);
//                printf("%05d %d -1\n", node[count - 1].address, node[count - 1].data);
//            }
//        }
//    }
//    return 0;
//}
