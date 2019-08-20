/**
* 分析：快乐模拟，需要掌握的是m和n的求法
*       N=m*n，m≥n，m-n最小，令n等于根号N，然后n--直至N%n==0，则m=N/n
*       坑点在于N为1时需要特判，N为不等于2的倍数的完全平方数时也需要特判
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int A[maxn], M[maxn][maxn];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    if(N == 1) {
        printf("%d", A[0]);
        return 0;
    }
    sort(A, A + N, greater<int>());
    int n = sqrt(N);
    while(N % n != 0)
        n--;
    int m = N / n;
    int i = 1, j = 1, num = 0;
    int u = 1, d = m, l = 1, r = n; //上下左右边界
    while(num < N) {
        while(num < N && j < r) { //向右
            M[i][j] = A[num++];
            j++;
        }
        while(num < N && i < d) { //向下
            M[i][j] = A[num++];
            i++;
        }
        while(num < N && j > l) { //向左
            M[i][j] = A[num++];
            j--;
        }
        while(num < N && i > u) { //向上
            M[i][j] = A[num++];
            i--;
        } //此时 i=u j=l
        u++, d--, l++, r--; //缩小边界
        i++, j++; //重定位至左上角
        //if(N%2!=0&&m==n) {
        if(num == N - 1)
            M[i][j] = A[num++]; //特判完全平方数
        //}
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d", M[i][j]);
            if(j < n)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
