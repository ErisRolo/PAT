/**
* 分析：经典DP模型之一 最长回文子串 dp[i][j] = dp[i+1][j-1]
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int dp[maxn][maxn];

int main() {
    int ans = 1;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
        if(i != s.size() - 1) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for(int L = 3; L <= s.size(); L++) { //枚举从3开始的每个长度，1和2已在设置边界时处理
        for(int i = 0; i + L - 1 < s.size(); i++) {
            int j = i + L - 1;
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
                if(dp[i][j] == 1)
                    ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
