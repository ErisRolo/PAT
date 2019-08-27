/**
* 分析：N皇后问题，并没有求解，只是判断，easy
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int col[maxn]; //第i列的棋子所在的行数

int main() {
    int k, n;
    scanf("%d", &k);
    while(k--) { //依次输入每列棋子所在的行数（从下往上数）
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &col[i]);
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(abs(j - i) == abs(col[j] - col[i]) || col[j] == col[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
