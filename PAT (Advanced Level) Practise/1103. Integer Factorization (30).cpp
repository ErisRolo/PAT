/**
* 分析：DFS，要想明白为什么用DFS，要找到死胡同和岔路口，要考虑题目要求
*       注意递归条件和输出格式
*       沃日尼玛为啥CB编译器有这种bug，pow(5,2)竟然会等于24卧槽？
**/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, k, p, maxfacsum = -1;
vector<int> fac, ans, temp;

void DFS(int index, int nowk, int sum, int facsum) {
    //死胡同
    if(nowk == k && sum == n) {
        if(facsum > maxfacsum) {
            maxfacsum = facsum;
            ans = temp;
        }
        return;
    }
    if(nowk > k || sum > n)
        return;
    //岔道口
    if(index >= 1) {
        temp.push_back(index);
        DFS(index, nowk + 1, sum + fac[index], facsum + index);
        temp.pop_back();
        DFS(index - 1, nowk, sum, facsum);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    //预处理
    for(int i = 0; pow(i, p) <= n; i++)
        fac.push_back(pow(i, p));
    DFS(fac.size() - 1, 0, 0, 0);
    if(maxfacsum == -1)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for(int i = 1; i < ans.size(); i++)
            printf(" + %d^%d", ans[i], p);
    }
    return 0;
}
