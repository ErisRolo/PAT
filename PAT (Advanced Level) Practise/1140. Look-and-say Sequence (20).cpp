/**
* 分析：按连续的字符算
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char d;
    string s;
    cin >> d >> n;
    s += d;
    for(int i = 2; i <= n; i++) {
        string temp;
        for(int j = 0; j < s.size(); j++) {
            int num = 1, k = j;
            while(s[k + 1] == s[k]) {
                num++;
                k++;
            }
            temp += s[j];
            temp += to_string(num);
            j += num - 1;
            num = 1;
        }
        s = temp;
    }
    cout << s;
    return 0;
}
