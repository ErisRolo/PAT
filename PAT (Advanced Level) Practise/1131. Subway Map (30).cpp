/**
* 分析：北京地铁，可以用dijkstra+DFS模板得27分，只需修改下DFS
*       对于线路的存储，不应该用顶点所属的线路存，因为中转站在多条线路上，会有歧义，应该将边所属的线路存储下来
*       但是这样做，最后一个点会超时，最后一个点数据点超过10000个，dijkstra部分复杂度会达到10^8导致TLE
*       所以还需要改成堆优化的版本进行优化，详情见代码
*       因为路径长度都是1，所以还可以只用DFS，这里的DFS是改写最短路径的DFS部分实现的，是图有环，需要bool数组标记是否访问
*       第一标尺仍为距离，即路径上的结点个数减1，即边数；第二标尺为中转站数（中转次数），即路线发生改变的时候统计一次
*       不过即使只用DFS最后一个测试点在服务器不好的时候也会超时，所以需要用unordered_map优化，一维表示二维
*       line[a*maxn+b]表示a->b，line[b*maxn+a]表示b->a
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 1000000000;

//DFS版本
int n, m, query, st, ed, cline;
vector<int> adj[maxn];
//int line[maxn][maxn];
unordered_map<int, int> line;

int mindis, mintran;
bool vis[maxn];
vector<int> path, temppath;
void DFS(int u) {
    if(u == ed) {
        temppath.push_back(u);
        int dis = temppath.size() - 1;
        int tran = 0;
        int tline = line[temppath[0] * maxn + temppath[1]];
        for(int i = 2; i < temppath.size(); i++) {
            int id = temppath[i], lastid = temppath[i - 1];
            if(line[id * maxn + lastid] != tline) {
                tran++;
                tline = line[id * maxn + lastid];
            }
        }
        if(dis < mindis) {
            path = temppath;
            mindis = dis;
            mintran = tran;
        } else if(dis == mindis && tran < mintran) {
            path = temppath;
            mintran = tran;
        }
        temppath.pop_back();
        return;
    }
    vis[u] = true;
    temppath.push_back(u);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(vis[v] == false)
            DFS(v);
    }
    temppath.pop_back();
    vis[u] = false;
}

int main() {
    int a, b;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        scanf("%d", &a);
        for(int j = 2; j <= m; j++) {
            scanf("%d", &b);
            //line[a][b] = line[b][a] = i;
            line[a * maxn + b] = line[b * maxn + a] = i;
            adj[a].push_back(b);
            adj[b].push_back(a);
            a = b;
        }
    }
    scanf("%d", &query);
    while(query--) {
        scanf("%d%d", &st, &ed);
        temppath.clear();
        path.clear();
        mindis = inf, mintran = inf;
        DFS(st);
        printf("%d\n", path.size() - 1);
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == st) { //如果为起点
                printf("Take Line#%d from %04d to ", line[st * maxn + path[i + 1]], st);
                cline = line[st * maxn + path[i + 1]];
            } else if(path[i] == ed) { //如果为终点
                printf("%04d.\n", ed);
            } else if(line[path[i]*maxn + path[i + 1]] != cline) { //如果为中转站
                printf("%04d.\n", path[i]);
                printf("Take Line#%d from %04d to ", line[path[i]*maxn + path[i + 1]], path[i]);
                cline = line[path[i] * maxn + path[i + 1]];
            }
        }
    }
    return 0;
}













//Dijkstra+DFS版本
//int n, m, query, st, ed, cline;
//vector<int> adj[maxn];
//int line[maxn][maxn]; //标记所属线路
//
//int d[maxn];
//bool vis[maxn];
//vector<int> pre[maxn];
////堆优化
//struct cmp {
//    bool operator() (const int &x, const int &y)const {
//        return d[x] > d[y];
//    }
//};
//priority_queue<int, vector<int>, cmp> q;
//void Dijkstra(int s) {
//    fill(vis, vis + maxn, false);
//    fill(d, d + maxn, inf);
//    d[s] = 0;
//
//    //堆优化
//    q.push(s);
//    while(!q.empty()) {
//        int u = q.top();
//        q.pop();
//        if(vis[u])
//            continue;
//        vis[u] = true;
//        for(int i = 0; i < adj[u].size(); i++) {
//            int v = adj[u][i];
//            if(vis[v] == false) {
//                if(d[u] + 1 < d[v]) {
//                    d[v] = d[u] + 1;
//                    q.push(v);
//                    pre[v].clear();
//                    pre[v].push_back(u);
//                } else if(d[u] + 1 == d[v]) {
//                    q.push(v);
//                    pre[v].push_back(u);
//                }
//            }
//        }
//    }
//
////	for(int i = 0; i < maxn; i++) {
////		int u = -1, min = inf;
////		for(int j = 0; j < maxn; j++) {
////			if(vis[j] == false && d[j] < min) {
////				u = j;
////				min = d[j];
////			}
////		}
////		if(u == -1)
////			return;
////		vis[u] = true;
////		for(int j = 0; j < adj[u].size(); j++) {
////			int v = adj[u][j];
////			if(vis[v] == false) {
////				if(d[u] + 1 < d[v]) {
////					d[v] = d[u] + 1;
////					pre[v].clear();
////					pre[v].push_back(u);
////				} else if(d[u] + 1 == d[v]) {
////					pre[v].push_back(u);
////				}
////			}
////
////		}
////	}
//
//}
//
//int mintran = inf;
//vector<int> path, temppath;
//void DFS(int v) {
//    if(v == st) {
//        temppath.push_back(v);
//        int tran = 0, tline;
//        for(int i = temppath.size() - 1; i > 0; i--) {
//            int id = temppath[i], nextid = temppath[i - 1];
//            if(temppath[i] == st) { //如果为起点
//                tline = line[id][nextid];
//            } else if(line[id][nextid] != tline) { //如果线路发生改变
//                tran++;
//                tline = line[id][nextid];
//            }
//        }
//        if(tran < mintran) {
//            mintran = tran;
//            path = temppath;
//        }
//        temppath.pop_back();
//        return;
//    }
//    temppath.push_back(v);
//    for(int i = 0; i < pre[v].size(); i++)
//        DFS(pre[v][i]);
//    temppath.pop_back();
//}
//
//int main() {
//    int a, b;
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++) {
//        scanf("%d", &m);
//        scanf("%d", &a);
//        for(int j = 2; j <= m; j++) {
//            scanf("%d", &b);
//            line[a][b] = line[b][a] = i;
//            adj[a].push_back(b);
//            adj[b].push_back(a);
//            a = b;
//        }
//    }
//    scanf("%d", &query);
//    while(query--) {
//        scanf("%d%d", &st, &ed);
//        for(int i = 1; i < maxn; i++)
//            pre[i].clear();
//        path.clear();
//        mintran = inf;
//        Dijkstra(st);
//        DFS(ed);
//        printf("%d\n", path.size() - 1);
//        for(int i = path.size() - 1; i >= 0; i--) {
//            if(path[i] == st) { //如果为起点
//                printf("Take Line#%d from %04d to ", line[st][path[i - 1]], st);
//                cline = line[st][path[i - 1]];
//            } else if(path[i] == ed) { //如果为终点
//                printf("%04d.\n", ed);
//            } else if( line[path[i]][path[i - 1]] != cline) { //如果线路发生改变
//                printf("%04d.\n", path[i]);
//                printf("Take Line#%d from %04d to ", line[path[i]][path[i - 1]], path[i]);
//                cline = line[path[i]][path[i - 1]];
//            }
//        }
//    }
//    return 0;
//}
