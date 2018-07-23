// 思路：求连通分量（极大连通子图）个数
// 并查集

#include <cstdio>
#include <utility> // 注意 pair 是 <utility> 头文件里的
#include <vector>
using namespace std;

int N, M, K;
int father[1001];
vector<pair<int, int>> roads;

int find_father(int x) {
    int a = x; // 暂存 x
    // 先找到根节点
    while(father[x] != x) {
        x = father[x];
    }
    // 路径压缩，防止深度过大
    while(father[a] != a) { // 注意这个顺序
        // 如果是先 father[a] = x, 这把 a 原来的父节点改掉了，上不去了
        int z = a;     // 暂存<原来>的 a
        a = father[a]; // a 变为a的父节点
        father[z] = x; // <原来>的 a 直接设为 x 子节点

        // 也可以暂存原来的父节点
    }
    return x; // 返回根节点
}

int count() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(find_father(i) == i)
            cnt++; // 有一个根节点，计数+1
    }
    return cnt - 1;
}

void print_del(int del) {
    for(auto i = roads.begin(); i != roads.end(); i++) {
        int a = i->first;
        int b = i->second;
        if(a != del and b != del) {
            // 除了要删除的节点外，本身a,b就相连
            int root_a = find_father(a);
            int root_b = find_father(b);
            // 合并
            if(root_a != root_b)
                father[root_a] = root_b;
        }
    }
    printf("%d\n", count() - 1); // count() 为连通分量个数，但要排除删除的节点
}

int main() {
    scanf("%d %d %o", &N, &M, &K);
    // read roads
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        roads.push_back(make_pair(a, b));
    }
    // read check list
    for(int i = 0; i < K; i++) {
        // 每次查找后都会修改 father，每次都必须初始化每个节点都为根节点
        for(int i = 0; i < N; i++) {
            father[i] = i;
        }
        int del;
        scanf("%d", &del);
        print_del(del);
    }
    return 0;
}
