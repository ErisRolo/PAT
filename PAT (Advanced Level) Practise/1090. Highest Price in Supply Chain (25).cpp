/**
* 分析：又是供应链问题，有了之前的经验没啥好说的
*       12分钟一次AC，希望考试可以保持这种熟练度
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;

int n, root, cnt = 0;
double p, r, hp = 0.0;
double ps[maxn] = {0.0};

struct Node {
    int weight;
    vector<int> child;
} node[maxn];

void DFS(int index, double p) {
    ps[index] = p;
    if(node[index].child.size() == 0) {
        if(p > hp)
            hp = p;
        p = p / (1.0 + r / 100);
        return;
    }
    for(int i = 0; i < node[index].child.size(); i++)
        DFS(node[index].child[i], p * ( 1.0 + r / 100));
}

int main() {
    int id;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        if(id != -1)
            node[id].child.push_back(i);
        else
            root = i;
    }
    DFS(root, p);
    for(int i = 0; i < n; i++) {
        if(ps[i] == hp)
            cnt++;
    }
    printf("%.2f %d", hp, cnt);
    return 0;
}
