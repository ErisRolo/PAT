/**
* 分析：并不是真的快排，只是判断主元，数量级为10^5，暴力O(n^2)会TLE，只有12分
*       改为用数组记录每一位左边最大的数和右边最小的数，关键在于递推关系
*       而递推又要注意初值的处理，左边找最大值则初始化一个最小值，右边找最小值则初始化一个最大值
*       默认d[0]左边比它小为-1，d[n-1]右边比它大为inf
*       主元个数为0时，需要输出一个换行，不然会格式错误，直接在末尾加个\n就好
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];
int leftMax[maxn], rightMin[maxn]; //左边记录最大，右边记录最小，不含本位
vector<int> ans;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    leftMax[0] = -1;
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], d[i - 1]);
    }
    rightMin[n - 1] = 0x7fffffff;
    for(int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], d[i + 1]);
    }
    for(int i = 0; i < n; i++) {
        if(leftMax[i] < d[i] && rightMin[i] > d[i]) {
            ans.push_back(d[i]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
        if(i != ans.size() - 1)
            printf(" ");
    }
    printf("\n"); //主元个数为0
    return 0;
}
