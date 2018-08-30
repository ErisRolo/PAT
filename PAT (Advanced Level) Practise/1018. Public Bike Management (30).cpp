/* 1018. Public Bike Management (30)

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.


Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


const int INF = 2147483647;
int Cmax, N, Sp, M;
// 最大容量, 城市数, 问题城市编号, 路数


int G[501][501]; // 路长
bool visit[501] = {false};
int d[501]; // 到 0 最短路径
int c[501]; // 每个城市的 bike
vector<int> pre[501]; // 前驱
vector<int> path; 
vector<int> result; 
// vector<vector<int>> res;
int min_need = INF;
int min_avalible = INF;


void dfs(int now){
    if(now == 0){
        path.push_back(now);
        int need = 0, avalible = 0;
        // res.push_back(path);
        for(int i = path.size() - 2; i >= 0; i--){
            int id = path[i];
            if(c[id] < 0){
                // 需要补充
                if(avalible > abs(c[id])){
                    avalible -= abs(c[id]);
                }
                else{
                    need += (abs(c[id]) - avalible); 
                    avalible = 0;
                }
            }
            else if(c[id] > 0){
                // 需要回收
                avalible += c[id];
            }
            // cout << "now need is :" << need << ". avalible is : " << avalible << endl;
        }
        // cout << "============" << endl;
        if(need < min_need){
            min_need = need;
            min_avalible = avalible;
            result = path;
        }
        else if(need == min_need && avalible < min_avalible){
            min_need = need;
            min_avalible = avalible;
            result = path; 
        }
        path.pop_back();
    }
    path.push_back(now);
    for(int i = 0; i < pre[now].size(); i++){
        dfs(pre[now][i]);
    }
    path.pop_back();
}

void dijkstra(int start){
    d[start] = 0;
    for(int i = 0; i <= N; i++){
        int u = -1, min = INF;        
        for(int j = 0; j <= N; j++){
            if(visit[j] || d[i] == INF) continue;
            if(d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        if(u == Sp) return;
        for(int j = 0; j <= N; j++){
            if(!visit[j] && G[u][j] != INF){
                // 未访问且有路
                if(d[u] + G[u][j] < d[j]){
                    d[j] = d[u] + G[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(d[u] + G[u][j] == d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

int main(){
    cin >> Cmax >> N >> Sp >> M;
    for(int i = 1; i <= N; i++){
        cin >> c[i];
        c[i] -= Cmax/2; 
    }
    fill(G[0], G[0] + 501 * 501, INF);
    for(int i = 0; i < M; i++){
        int a, b, l;
        cin >> a >> b >> l;
        G[a][b] = G[b][a] = l;
    }
    for(int i = 0; i <= N; i++){
        d[i] = INF;
    }
    dijkstra(0);
    dfs(Sp);
    cout << min_need << " 0";
    for(auto i = result.end()-2; i >= result.begin(); i--){
        cout << "->" << *i;
    }
    cout << " " << min_avalible;
    // for(auto i : result){
    //     cout << i << endl;
    // }
    // cout << "back is " << min_need << endl;
    // cout << "========" << endl;
    // for(auto i = res.begin(); i != res.end(); i++){
    //     for(auto j = i->begin(); j != i->end(); j++){
    //         cout <<  *j << " "; 
    //     }
    //     cout << endl;
    // }
    return  0;
}