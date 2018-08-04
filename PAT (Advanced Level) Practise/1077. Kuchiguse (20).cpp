/**
* 分析：给出N个字符串，求最长公共后缀
*       因为求后缀不方便，所以先将字符串反转，可以使用<algorithm>下的reverse()
*       因为字符串中含空格，所以不能用cin，选择用getline
*       同时scanf读入N时要多加一个换行符，防止这个换行符被getline读到
*       做题时如果发现少输入一个字符串，很有可能是这个原因
*       思路是首先将读取的第一个字符串作为ans，后面每输入一个都和ans比较
*       遇到不同字符就截取，获得新的ans，并更新ans的长度
*       注意判断时每次遍历长度是ans和新输入str中较短的长度
**/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    string ans, str;
    int anslen, strlen, minlen;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        strlen = str.size();
        reverse(str.begin(), str.end());
        if(i == 0) {
            ans = str;
            anslen = ans.size();
            continue;
        }
        minlen = min(anslen, strlen);
        for(int j = 0; j < minlen; j++) {
            if(ans[j] != str[j]) {
                ans = ans.substr(0, j);
                anslen = ans.size();
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if(anslen == 0)
        cout << "nai";
    else
        cout << ans;
    return 0;
}
