/**
* 分析：已知BST先序序列求任意两结点的最近公共祖先
*       记住规律：遍历先序序列，第一个满足大于等于其中一结点并小于等于另一结点的结点即为所求
*       此题用bool数组标记会有一个段错误和一个测试点无法通过，扣5分，改成map可AC
*       切记不要轻易用bool数组
**/

#include <cstdio>
#include <map>
using namespace std;
const int maxn = 10010;

int m, n;
int pre[maxn];
//bool flag[maxn];
map<int, bool> mp;

int main() {
    scanf("%d%d", &m, &n);
    int temp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        pre[i] = temp;
        //flag[temp] = true;
        mp[temp] = true;
    }
    int u, v, r;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        for(int j = 0; j < n; j++) {
            r = pre[j];
            if((r >= u && r <= v) || (r <= u && r >= v))
                break;
        }
//        if(flag[u] == false && flag[v] == false) {
//            printf("ERROR: %d and %d are not found.\n", u, v);
//        } else if(flag[u] == false || flag[v] == false) {
//            printf("ERROR: %d is not found.\n", flag[u] == false ? u : v);
//        } else if(r == u || r == v) {
//            printf("%d is an ancestor of %d.\n", r, r == u ? v : u);
//        } else {
//            printf("LCA of %d and %d is %d.\n", u, v, r);
//        }
        if(mp[u] == false && mp[v] == false) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if(mp[u] == false || mp[v] == false) {
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        } else if(r == u || r == v) {
            printf("%d is an ancestor of %d.\n", r, r == u ? v : u);
        } else {
            printf("LCA of %d and %d is %d.\n", u, v, r);
        }
    }
    return 0;
}
