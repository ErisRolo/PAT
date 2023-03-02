/**
 * 分析：题目给定范围是[-2^63,2^63]，而long long型数据的范围为[-2^63,2^63)
 *       两个整数相加可能会溢出（正溢出或负溢出），直接判断大小会出错
 *       分析知，A>0,B>0,A+B<0时为正溢出，A<0,B<0,A+B>=0时为负溢出（应该直接记住就行）
 *       没有溢出的情况直接判断即可
 *       注意A+B需要存放到long long型变量中才可与C进行比较，不可以在if的条件中直接相加与C比较
 *       否则会造成后面的数据错误（虽然我也不知道为啥会错，甚至变量就没用，记住就好，long long型比较的问题）
 *       或者直接用python，不受以上任何问题影响
 **/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int T;
    LL A, B, C, res;
    bool flag;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        res = A + B;
        if ((A > 0 && B > 0 && A + B < 0))
            flag = true;
        else if (A < 0 && B < 0 && A + B >= 0)
            flag = false;
        else if (A + B > C)
            flag = true;
        else
            flag = false;
        if (flag)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}