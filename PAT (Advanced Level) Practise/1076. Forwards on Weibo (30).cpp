/**
* 分析：图的BFS遍历，思路感觉比DFS明晰，可以一口气写出来
*       这道题要注意的是，因为是多次查询，所以每次查询前inq数组要清0
**/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1010;

int n, l, k;
bool inq[maxn];

struct Node {
    int id;
    int layer;
};
vector<Node> Adj[maxn];

int BFS(int id, int l) {
    int forwards = 0;
    Node start;
    start.id = id;
    start.layer = 0;
    queue<Node> q;
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()) {
        Node temp = q.front();
        int tempid = temp.id;
        q.pop();
        for(int i = 0; i < Adj[tempid].size(); i++) {
            Node next = Adj[tempid][i];
            next.layer = temp.layer + 1;
            int nextid = next.id;
            int nextlayer = next.layer;
            if(inq[nextid] == false && nextlayer <= l) {
                q.push(next);
                inq[nextid] = true;
                forwards++;
            }
        }
    }
    return forwards;
}

int main() {
    Node node;
    int numfollow, follow;
    scanf("%d%d", &n, &l);
    for(int i = 1; i <= n; i++) {
        node.id = i;
        scanf("%d", &numfollow);
        for(int j = 0; j < numfollow; j++) {
            scanf("%d", &follow);
            Adj[follow].push_back(node);
        }
    }
    int query, res;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &query);
        fill(inq, inq + maxn, 0);
        res = BFS(query, l);
        printf("%d\n", res);
    }
    return 0;
}
