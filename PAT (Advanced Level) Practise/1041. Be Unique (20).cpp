/**
* 分析：输入一行数，找出第一个不同的数，用简单的散列（Hash）即可
*       因为范围1<= d <=10^4，所以用一个10^4大小的整型数组存储数据出现次数即可
*       再用一个整型数组存储输入数据，输出时按输入顺序判断那几个数据即可
*       不用遍历整个hash，遍历整个hash也不能按顺序输出第一个不同的数
*       简单题，主要想到用hash就行，这题我写的和晴神一样，可能是看到这是hash这一章的题受到提示了吧
*       要记住使用hash的情景，用空间换时间，比如此题需要统计不同数字出现的次数
*       记住hash的主要思想，就是将元素通过一个函数转换为整数，使得该整数可以尽量唯一地代表这个元素
**/

#include <cstdio>
const int maxn = 10001;

int main() {
    int N, bet;
    scanf("%d", &N);
    int temp[N], hash[maxn];
    for(int i = 0; i < N; i++) {
        scanf("%d", &bet);
        temp[i] = bet;
        hash[bet]++;
    }
    for(int i = 0; i < N; i++) {
        if(hash[temp[i]] == 1) {
            printf("%d", temp[i]);
            break;
        }
        if(i == N - 1)
            printf("None");
    }
    return 0;
}
