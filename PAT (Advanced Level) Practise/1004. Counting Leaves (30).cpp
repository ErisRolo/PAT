/**
* 分析：初学之后做的树的遍历的第二道题
*       虽然是30分压轴题，但是感觉考点基础，给定一棵树，输出每层的叶子结点个数
*       一开始想用DFS，但感觉不顺改用了BFS，一开始没注意到根结点从1开始写的0
*       改正之后提交，此时有两个测试点没通过，只得了19分，至此时间控制在了半小时以内
*       然后修改，发现对层数的处理逻辑有问题，仅用一个整型变量无法记录每层的叶子数和最后的层数
*       应该分开处理，数组存储结点所在的层数，整型变量单独统计
*       这样其子结点层数等于父节点层数加一，每次入队的时候用max函数更新最大层数即为树的层数
*       最后提交，一次AC，修改用了15分钟以内，至此时间控制在了一个小时以内
*       勉强及格，这还是日常训练状态，考场上就不一定了，还要继续练习
**/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;

int n, m;
vector<int> child[maxn];
int levels = 1;
int level[maxn] = {0};
int nochild[maxn] = {0};

void BFS() {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int root = q.front();
        q.pop();
        if(child[root].size() != 0) {
            for(int i = 0; i < child[root].size(); i++) {
                q.push(child[root][i]);
                level[child[root][i]] = level[root] + 1;
                levels = max(levels, level[child[root][i]]);
            }
        } else {
            nochild[level[root]]++;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int id, cnt, kid;
        scanf("%d%d", &id, &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &kid);
            child[id].push_back(kid);
        }
    }
    level[1] = 1;
    BFS();
    for(int i = 1; i <= levels; i++) {
        if(i < levels)
            printf("%d ", nochild[i]);
        else
            printf("%d", nochild[i]);
    }
    return 0;
}
