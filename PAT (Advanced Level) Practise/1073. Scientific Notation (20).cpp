/**
* 分析：首先输出正负号，然后找到E的位置pos，同时根据此算出小数位的个数n
*       接着将原字符串分为底数和指数两部分，同时将底数字符串去掉小数点，将指数字符串转为数字exp
*       然后根据E后面的符号正负来分别输出
*       若为-，则输出为0.0···0XXXX，先输出0.，然后输出exp-1个0，最后输出去掉小数点的底数字符串
*       去掉小数点的底数字符串可用substr和s[0]拼接获得
*       若为+，则主要判断小数点的位置，根据n和exp的关系输出
*       这种题可以按照题意多写几组数据观察得出规律，字符串的题算模拟，找规律就是了，想想每一位是怎么输出的 
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, s1, s2;
    int pos, exp, n; //E的位置 指数 小数位个数
    cin >> str;
    if(str[0] == '-')
        cout << '-';
    pos = str.find("E");
    n = pos - 3;
    int len = pos - 1;
    s1 = str.substr(1, len);
    s1 = s1[0] + s1.substr(2, s1.size() - 2);
    s2 = str.substr(pos + 2, str.size() - pos - 2);
    exp = atoi(s2.c_str());
    if(str[pos + 1] == '-') {
        cout << "0.";
        for(int i = 0; i < exp - 1; i++)
            cout << "0";
        cout << s1;
    } else {
        if(exp == n) {
            cout << s1;
        }
        if(exp > n) {
            cout << s1;
            for(int i = 0; i < exp - n; i++)
                cout << "0";
        }
        if(exp < n) {
            for(int i = 0; i <= exp; i++)
                cout << s1[i];
            cout << ".";
            for(int i = exp + 1; i < s1.size(); i++)
                cout << s1[i];
        }
    }
    return 0;
}
