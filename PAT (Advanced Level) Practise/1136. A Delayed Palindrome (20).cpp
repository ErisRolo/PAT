/**
* 分析：1000位 大整数运算
*       也可以看成判断回文字符串，字符串相加，将判断改为reverse后是否与原来相等，字符串相加和大整数相加相同
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

struct bign {
    int d[maxn];
    int len;
    bign() {
        fill(d, d + maxn, 0);
        len = 0;
    }
};

bign strtobign(string s) {
    bign a;
    for(int i = s.size() - 1; i >= 0; i--)
        a.d[a.len++] = s[i] - '0';
    return a;
}

string bigntostr(bign a) {
    string s;
    for(int i = a.len - 1; i >= 0; i--)
        s += a.d[i] + '0';
    return s;
}

bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        c.d[c.len++] = carry;
    return c;
}

bool isright(string s) {
    int k = s.size() - 1;
    for(int i = 0; i <= k; i++) {
        if(s[i] != s[k - i])
            return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    string s;
    cin >> s;
    while(isright(s) == false && cnt < 10) {
        bign a = strtobign(s);
        cout << s << " + ";
        reverse(s.begin(), s.end());
        bign b = strtobign(s);
        cout << s << " = ";
        bign c = add(a, b);
        s = bigntostr(c);
        cout << s << endl;
        cnt++;
    }
    if(isright(s))
        cout << s << " is a palindromic number." << endl;
    else
        cout << "Not found in 10 iterations." << endl;
    return 0;
}
