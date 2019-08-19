/**
* 分析：转化为DP模型最长不下降子列 dp[i]=max(1,dp[j]+1)
*       具体操作是把题目给定的程度排列转化为大小关系，用一个优先级数组，但这么做只有24分，有一个WA
*       重新读题发现有的点不能选，在状态转移方程的判断条件上多加一个判断即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int a[maxn], dp[maxn], p[maxn]; // 序列 以a[i]结尾的最大长度 优先级

int main() {
    fill(p, p + maxn, -1);
    int n, m, l, t, ans = -1;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        p[t] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < l; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(p[a[j]] <= p[a[i]] && dp[j] + 1 > dp[i] && p[a[j]] != -1) //被选的点不能是给出序列之外的
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
