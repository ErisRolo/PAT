/**
* 分析：打印图形，根据题目里的限制条件推公式即可
*       然后套公式算三个位置的字符个数，根据个数打印
*       如果不清楚怎么打印就先输出三个位置的数据看一下
*       公式要写对，不要按自己的理解凑公式，按题目来
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 81;

int main() {
    char str[maxn];
    cin >> str;
    int N = strlen(str);
    int n1, n2, n3;
    n1 = (N + 2) / 3;
    n3 = n1;
    n2 = N + 2 - n1 - n3;
    //printf("%d %d %d", n1, n2, n3);
    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]);
        for(int j = 0; j < n2 - 2; j++)
            printf(" ");
        printf("%c\n", str[N - i - 1]);
    }
    for(int i = 0; i < n2; i++)
        printf("%c", str[n1 + i - 1]);
    return 0;
}
