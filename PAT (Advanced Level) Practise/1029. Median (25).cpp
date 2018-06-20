#include <cstdio>
const int maxn = 1000010; //序列最大长度
const int INF = 0x7fffffff; //int上限，本题设成10^7也能过

int S1[maxn], S2[maxn]; //两个递增序列

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);  //输入第一个序列
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &S2[i]);  //输入第二个序列
    S1[n] = S2[m] = INF; //两个序列的最后一个元素设为int上限
    int medianPos = (n + m - 1) / 2; //medianPos为中间位置
    int i = 0, j = 0, count = 0; //count计数当前的位置
    //只要count未达到medianPos，就继续循环
    while (count < medianPos) {
        if (S1[i] < S2[j])
            i++; //S1[i]更小，则选择S1[i]
        else
            j++; //S2[j]更小，则选择S2[j]
        count++; //count加1
    }
    //输出两个序列当前位置较小的元素
    if (S1[i] < S2[j])
        printf("%d\n", S1[i]);
    else
        printf("%d\n", S2[j]);
    return 0;
}
