/**
* 分析：STL真好用，真香
**/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int cnt = 0;
    string s, temp;
    string str[100];
    getline(cin, s);
    s += " "; //不然最后一个单词读不进去
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ')
            temp += s[i];
        else {
            str[cnt++] = temp;
            temp.clear();
        }
    }
    for(int i = cnt - 1; i > 0; i--)
        cout << str[i] << " ";
    cout << str[0];
    return 0;
}

