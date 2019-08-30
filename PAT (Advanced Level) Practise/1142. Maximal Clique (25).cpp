/**
* 分析：我去年写的辣鸡算法都没超时，这次模拟的算法竟然有一个点TLE
*       简单修改，去掉一个vector，删掉一个内部的二重循环，改用bool数组AC
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, m, q, k, a, b, v;
int num[maxn];
int g[maxn][maxn];
vector<int> s;
bool vis[maxn];
bool isclique, ismax;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    scanf("%d", &q);
    while(q--) {
        fill(vis, vis + maxn, false);
        fill(num, num + maxn, 0);
        s.clear();
        isclique = true;
        ismax = true;
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &v);
            s.push_back(v);
            vis[v] = true;
        }
        for(auto i : s) {
            for(auto j : s) {
                if(i != j && g[i][j] != 1) {
                    isclique = false;
                    break;
                }
            }
        }
        if(isclique) {
            for(int i = 1; i <= n; i++) {
                if(vis[i] == false) {
                    for(auto j : s) {
                        if(g[i][j] == 1)
                            num[i]++;
                    }
                    if(num[i] == s.size()) {
                        ismax = false;
                        break;
                    }
                }
            }
        }
        if(isclique) {
            if(ismax)
                printf("Yes\n");
            else
                printf("Not Maximal\n");
        } else
            printf("Not a Clique\n");
    }
    return 0;
}





















//#include <cstdio>
//#include <vector>
//using namespace std;
//const int maxn = 210;
//
//int n, e;
//int m, k, temp;
//int g[maxn][maxn];
//vector<int> vec;
//bool flag[maxn];
//
//bool judgeC(vector<int> vec) {
//    for(int i = 0; i < vec.size(); i++) {
//        for(int j = i + 1; j < vec.size(); j++) {
//            if(g[vec[i]][vec[j]] == 0)
//                return false;
//        }
//    }
//    return true;
//}
//
//bool judgeM(vector<int> vec) {
//    for(int i = 1; i <= n; i++) {
//        if(flag[i] == false) {
//            vec.push_back(i);
//            if(judgeC(vec))
//                return false;
//            vec.pop_back();
//        }
//    }
//    return true;
//}
//
//int main() {
//    fill(g[0], g[0] + maxn * maxn, 0);
//    scanf("%d%d", &n, &e);
//    int a, b;
//    for(int i = 0; i < e; i++) {
//        scanf("%d%d", &a, &b);
//        g[a][b] = g[b][a] = 1;
//    }
//    scanf("%d", &m);
//    for(int i = 0; i < m; i++) {
//        vec.clear();
//        fill(flag, flag + maxn, false);
//        scanf("%d", &k);
//        for(int j = 0; j < k; j++) {
//            scanf("%d", &temp);
//            vec.push_back(temp);
//            flag[temp] = true;
//        }
//        if(judgeC(vec)) {
//            if(judgeM(vec))
//                printf("Yes\n");
//            else
//                printf("Not Maximal\n");
//        } else {
//            printf("Not a Clique\n");
//        }
//    }
//    return 0;
//}
