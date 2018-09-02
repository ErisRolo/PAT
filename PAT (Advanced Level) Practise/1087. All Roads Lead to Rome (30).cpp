/**
* 分析：Dijkstra+DFS，一小时内搞定，局部变量别忘了初始化
**/

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 420;
const int inf = 1000000000;

int n, k;
int s;
string st;
int maxhappy = 0, numpath = 0;
double avghappy = 0;
int g[maxn][maxn];
int d[maxn], h[maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path, temppath;
map<string, int> strtoid;
map<int, string> idtostr;

int num = 0;
int getid(string str) {
    if(strtoid.find(str) == strtoid.end()) {
        strtoid[str] = num;
        idtostr[num] = str;
        return num++;
    } else {
        return strtoid[str];
    }
}

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && g[u][v] != inf) {
                if(d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + g[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if(v == s) {
        temppath.push_back(v);
        int hap = 0;
        double avghap;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            hap += h[id];
        }
        avghap  = hap * 1.0 / (temppath.size() - 1);
        if(hap > maxhappy) {
            maxhappy = hap;
            path = temppath;
            avghappy = avghap;
        } else if(hap == maxhappy && avghap > avghappy) {
            path = temppath;
            avghappy = avghap;
        }
        numpath++;
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    temppath.pop_back();
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d", &n, &k);
    cin >> st;
    s = getid(st);
    int c, happy;
    string city;
    for(int i = 1; i <= n - 1; i++) {
        cin >> city >> happy;
        c = getid(city);
        h[c] = happy;
    }
    int a, b, cost;
    string c1, c2;
    for(int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> cost;
        a = getid(c1);
        b = getid(c2);
        g[a][b] = g[b][a] = cost;
    }
    int e = getid("ROM");
    Dijkstra(s);
    DFS(e);
    cout << numpath << " " << d[e] << " " << maxhappy << " " << (int)avghappy << endl;
    for(int i = path.size() - 1; i > 0; i--)
        cout << idtostr[path[i]] << "->";
    cout << "ROM";
    return 0;
}
