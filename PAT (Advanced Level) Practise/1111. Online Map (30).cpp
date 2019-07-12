#include <bits/stdc++.h>
using namespace std;
const int inf = 999999999;

int n, m, s, des, ansdis1, tempcnt = 0, cnt = inf;
bool visit[505];
int elength[505][505], etime[505][505], dis[505], t[505], pre[505];
vector<int> temppath, prepos[505], anspath1, anspath2;

void dfs(int index) {
    if(index == s) {
        if(tempcnt < cnt) {
            anspath2 = temppath;
            cnt = tempcnt;
        }
        return;
    }
    tempcnt++;
    temppath.push_back(index);
    for(int i = 0; i < prepos[index].size(); i++)
        dfs(prepos[index][i]);
    temppath.pop_back();
    tempcnt--;
}

int main() {
    cin >> n >> m;
    fill(elength[0], elength[0] + 505 * 505, inf);
    fill(dis, dis + 505, inf);
    fill(t, t + 505, inf);
    for(int i = 0; i < m; i++) {
        int a, b, flag, tempd, tempt;
        scanf("%d %d %d %d %d", &a, &b, &flag, &tempd, &tempt);
        elength[a][b] = tempd;
        etime[a][b] = tempt;
        if(flag == 0) {
            elength[b][a] = tempd;
            etime[b][a] = tempt;
        }
    }
    cin >> s >> des;
    dis[s] = 0;
    t[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(dis[j] < minn && visit[j] == false) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && elength[u][v] < inf) {
                if(dis[u] + elength[u][v] < dis[v]) {
                    dis[v] = dis[u] + elength[u][v];
                    t[v] = t[u] + etime[u][v];
                    pre[v] = u;
                } else if(dis[u] + elength[u][v] == dis[v] && t[u] + etime[u][v] < t[v]) {
                    t[v] = t[u] + etime[u][v];
                    pre[v] = u;
                }
            }
        }
    }
    ansdis1 = dis[des];
    int temp = des;
    while(temp != s) {
        anspath1.push_back(temp);
        temp = pre[temp];
    }
    fill(visit, visit + 505, false);
    fill(t, t + 505, inf);
    t[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(t[j] < minn && visit[j] == false) {
                u = j;
                minn = t[j];
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && elength[u][v] < inf) {
                if(t[u] + etime[u][v] < t[v]) {
                    t[v] = t[u] + etime[u][v];
                    prepos[v].clear();
                    prepos[v].push_back(u);
                } else if(t[u] + etime[u][v] == t[v])
                    prepos[v].push_back(u);
            }
        }
    }
    dfs(des);
    if(anspath2 == anspath1)
        printf("Distance = %d; Time = %d: %d", ansdis1, t[des], s);
    else {
        printf("Distance = %d: %d", ansdis1, s);
        for(int i = anspath1.size() - 1; i >= 0; --i)
            printf(" -> %d", anspath1[i]);
        printf("\nTime = %d: %d", t[des], s);
    }
    for(int i = anspath2.size() - 1; i >= 0; --i)
        printf(" -> %d", anspath2[i]);
    return 0;
}
