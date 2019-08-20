/**
* 分析：归类为背包问题但我没看出来，用DFS只得了25分，有两个点TLE
*       参照晴神标程，视为价值c[i]和质量w[i]等价的01背包问题
*       靠没时间研究背包dp了，附一个吴佬提供的记忆化搜索的解法
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxv = 110;

int A[maxn];
int dp[maxn][maxv];

int dfs(int n, int m) {
    if(n <= 0 || m <= 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    else
        dp[n][m] = max(dfs(n - 1, m), m >= A[n] ? dfs(n - 1, m - A[n]) + A[n] : 0);
    return dp[n][m];
}

int main() {
    fill(dp[0], dp[0] + maxn * maxv, -1);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    sort(A + 1, A + n + 1, greater<int>());
    dfs(n, m);
    int res = m;
    vector<int>ans;
    for(int i = n; i > 0; i--) {
        if(A[i] == res || dp[i - 1][res - A[i]] == res - A[i]) {
            ans.push_back(A[i]);
            res -= A[i];
        }
    }
    if(res != 0)
        printf("No Solution");
    else {
        for(int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i]);
            if(i != ans.size() - 1)
                printf(" ");
        }
    }
    return 0;
}












//int n,m;
//int d[maxn];
//vector<int> ans,temp;
//
//void DFS(int index,int sum) {
//	if(sum==m) {
//		if(ans.size()==0)
//			ans=temp;
//		else if(temp<ans)
//			ans=temp;
//		return;
//	}
//	if(sum>m||index>=n)
//		return;
//	temp.push_back(index);
//	DFS(index+1,sum+d[index]);
//	temp.pop_back();
//	DFS(index+1,sum);
//}
//
//int main() {
//	scanf("%d%d",&n,&m);
//	for(int i=0; i<n; i++)
//		scanf("%d",&d[i]);
//	sort(d,d+n);
//	DFS(0,0);
//	if(ans.size()!=0) {
//		for(int i=0; i<ans.size(); i++) {
//			printf("%d",d[ans[i]]);
//			if(i!=ans.size()-1)
//				printf(" ");
//		}
//	} else {
//		printf("No Solution");
//	}
//	return 0;
//}
