/**
* 分析：由题意分析规律，可以多写几个出来
*       得出规律：只有PAT三个字母且P和T的个数均为1，开头A的个数 * 中间A的个数 = 结尾A的个数
**/

#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        int p = 0, t = 0;
        map<char, int> mp;
        for(int j = 0; j < s.size(); j++) {
            mp[s[j]]++;
            if(s[j] == 'P')
                p = j;
            if(s[j] == 'T')
                t = j;
        }
        if(mp.size() == 3 && mp['P'] == 1 && mp['T'] == 1 && mp['A'] != 0 && p * (t - p - 1) == s.size() - t - 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
