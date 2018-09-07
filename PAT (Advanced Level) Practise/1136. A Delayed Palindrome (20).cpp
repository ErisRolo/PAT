/**
* 分析：考查大整数运算和字符串处理，要熟练使用reverse等STL函数
**/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool judge(string s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int cnt = 0;
    bool flag = false;
    string s, ns, ans;
    cin >> s;
    int temp, carry = 0;
    while(cnt < 10) {
        if(judge(s) == false) {
            cnt++;
            ns = s;
            reverse(ns.begin(), ns.end());
            for(int i = 0; i < s.size(); i++) {
                temp = (s[i] - '0') + (ns[i] - '0') + carry;
                carry = 0;
                if(temp >= 10) {
                    temp -= 10;
                    carry = 1;
                }
                ans += (char)(temp + '0');
            }
            if(carry == 1) {
                ans += '1';
                carry = 0;
            }
            reverse(ans.begin(), ans.end());
            cout << s << " + " << ns << " = " << ans << endl;
            s = ans;
            ans = "";
        } else {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << s << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";
    return 0;
}
