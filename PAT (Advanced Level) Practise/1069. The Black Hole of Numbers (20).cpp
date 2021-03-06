/**
* 分析：数字转字符串，对一个字符串单独排序，字符串转数字，设个初值，随便操作
*       注意整数转换字符串不足四位会丢0，需要手动补齐
**/

#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    int n, min, max, ans;
    string s, s1, s2;
    scanf("%d", &n);
    ans = n;
    //对输入6174进行特判
    if(ans == 6174) {
        printf("7641 - 1467 = 6174\n");
    }
    while(ans != 6174 && ans != 0) {
        s = to_string(ans);
        if(s.size() == 1)
            s += "000";
        if(s.size() == 2)
            s += "00";
        if(s.size() == 3)
            s += "0";
        sort(s.begin(), s.end());
        s1 = s;
        sort(s.begin(), s.end(), cmp);
        s2 = s;
        min = stoi(s1);
        max = stoi(s2);
        ans = max - min;
        printf("%04d - %04d = %04d\n", max, min, ans);
    }
    return 0;
}
