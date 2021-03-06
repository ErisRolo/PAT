/**
* 分析：属于那种序列每一位的值都可以通过左右两侧的结果计算出来的题，递推找规律，计算A两侧P和T的个数
*       直接暴力遍历统计PAT个数的话会有3个TLE，只有15分
*       改成遍历时用数组记录每个位置左边P的个数和右边T的个数
*       注意题目要求对结果取余，取余运算一定是运算过程中就进行的，不能只对最后一个结果取余
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int p[maxn], t[maxn]; //每个位置左边P的个数和右边T的个数，包括当前位

int main() {
    int cnt = 0;
    string s;
    cin >> s;
    if(s[0] == 'P')
        p[0] = 1;
    for(int i = 1; i < s.size(); i++) {
        p[i] = p[i - 1];
        if(s[i] == 'P')
            p[i]++;
    }
    if(s[s.size() - 1] == 'T')
        t[s.size() - 1] = 1;
    for(int i = s.size() - 2; i >= 0; i--) {
        t[i] = t[i + 1];
        if(s[i] == 'T')
            t[i]++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A')
            cnt = (cnt + p[i] * t[i]) % 1000000007;
    }
    printf("%d", cnt);
    return 0;
}
