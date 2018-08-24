/**
* 分析：树的遍历+BFS，有点晚有点困，15分钟一次AC
*       考试的时候倒数第二题是这种难度就好了
**/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 101;

int n, m, levels = 1, maxnum = 0, maxlevel = 1;
int level[maxn], num[maxn]; //结点所在的层数，该层具有的结点数
vector<int> child[maxn];

void BFS() {
    queue<int> q;
    q.push(1);
    num[levels] = 1;
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        if(child[parent].size() != 0) {
            levels++;
            for(int i = 0; i < child[parent].size(); i++) {
                q.push(child[parent][i]);
                level[child[parent][i]] = level[parent] + 1;
                num[level[parent] + 1]++;
            }
        }
    }
}

int main() {
    int id, k, kid;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &kid);
            child[id].push_back(kid);
        }
    }
    level[1] = 1;
    BFS();
    for(int i = 1; i <= levels; i++) {
        if(num[i] > maxnum) {
            maxnum = num[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
