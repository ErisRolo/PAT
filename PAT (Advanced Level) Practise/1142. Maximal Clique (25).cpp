/**
* 分析：最大团问题，要么之前了解这个概念，要么读懂题意。。。
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 210;

int n, e;
int m, k, temp;
int g[maxn][maxn];
vector<int> vec;
bool flag[maxn];

bool judgeC(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = i + 1; j < vec.size(); j++) {
            if(g[vec[i]][vec[j]] == 0)
                return false;
        }
    }
    return true;
}

bool judgeM(vector<int> vec) {
    for(int i = 1; i <= n; i++) {
        if(flag[i] == false) {
            vec.push_back(i);
            if(judgeC(vec))
                return false;
            vec.pop_back();
        }
    }
    return true;
}

int main() {
    fill(g[0], g[0] + maxn * maxn, 0);
    scanf("%d%d", &n, &e);
    int a, b;
    for(int i = 0; i < e; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        vec.clear();
        fill(flag, flag + maxn, false);
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &temp);
            vec.push_back(temp);
            flag[temp] = true;
        }
        if(judgeC(vec)) {
            if(judgeM(vec))
                printf("Yes\n");
            else
                printf("Not Maximal\n");
        } else {
            printf("Not a Clique\n");
        }
    }
    return 0;
}
