/**
* 分析：现在是凌晨一点半，又是一道供应链问题，脑子不太好使了，竟然做了20分钟才AC
*       主要两个坑：其一，因为是求最低价，因此初值应该设为一个很大的数而不是0
*                   其二，只能统计零售商，即叶子结点个数，其他结点即使售价等于最小值也不能计数
*       以后遇到这种题，有些地方可以完全照搬以前的写，但也要具体情况具体分析
*       比如这题的根结点就得自己找题目不会告诉你，而DFS遍历必须从根结点开始，所以要灵活
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e11;

int n, root, cnt = 0;
double p, r, lp = INF;
double ps[maxn];

struct Node {
    int weight;
    int flag; //用来找根结点
    vector<int> child;
} node[maxn];

void DFS(int index, double p) {
    ps[index] = p;
    if(node[index].child.size() == 0) {
        if(p < lp)
            lp = p;
        p = p / (1.0 + r / 100);
        return;
    }
    for(int i = 0; i < node[index].child.size(); i++)
        DFS(node[index].child[i], p * (1.0 + r / 100));
}


int main() {
    int k, id;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k != 0) {
            for(int j = 0; j < k; j++) {
                scanf("%d", &id);
                node[i].child.push_back(id);
                node[id].flag = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(node[i].flag == 0) {
            root = i;
            break;
        }
    }
    DFS(root, p);
    for(int i = 0; i < n; i++) {
        if(ps[i] == lp && node[i].child.size() == 0) {
            cnt++;
        }
    }
    printf("%.4f %d", lp, cnt);
    return 0;
}
