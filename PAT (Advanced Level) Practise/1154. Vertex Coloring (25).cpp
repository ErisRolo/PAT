/**
* 分析：并不会超限，用邻接表存储即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int n, m, k;
vector<int> adj[maxn];
int color[maxn];
set<int> colnum;


int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &k);
    while(k--) {
        bool flag = true;
        colnum.clear();
        fill(color, color + n, -1);
        for(int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            colnum.insert(color[i]);
        }
        for(int i = 0; i < n; i++) {
            for(auto j : adj[i]) {
                if(color[i] == color[j]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            printf("%d-coloring\n", colnum.size());
        else
            printf("No\n");
    }
    return 0;
}








//**
//* 分析：直接存储图会内存超限，改成存储边及其两个顶点
//*       用hash和set解决
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 10010;
//
//struct edge {
//    int a, b;
//} Edge[maxn];
//
//int n, m, k, color;
//int col[maxn];
//bool flag;
//set<int> cnt;
//
//int main() {
//    fill(col, col + maxn, 101);
//    scanf("%d%d", &n, &m);
//    for(int i = 0; i < m; i++) {
//        scanf("%d%d", &Edge[i].a, &Edge[i].b);
//    }
//    scanf("%d", &k);
//    for(int i = 0; i < k; i++) {
//        cnt.clear();
//        flag = true;
//        for(int j = 0; j < n; j++) {
//            scanf("%d", &color);
//            col[j] = color;
//            cnt.insert(color);
//        }
//        for(int j = 0; j < m; j++) {
//            if(col[Edge[j].a] == col[Edge[j].b]) {
//                flag = false;
//                break;
//            }
//        }
//        if(flag)
//            printf("%d-coloring\n", cnt.size());
//        else
//            printf("No\n");
//    }
//    return 0;
//}
