/**
* 分析：看似简单题，十分简单。。。但是会有各种坑
*       题目里说的是整除而不是结果正好为len/2，所以要用取余
*       除数可能为0，所以会有浮点错误
*       判断条件中不等于0要写在算术式前面
**/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    string s, s1, s2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length();
        s1 = s.substr(0, len / 2);
        s2 = s.substr(len / 2, len / 2);
        int num = stoi(s), a = stoi(s1), b = stoi(s2);
        if((a * b) != 0 && num % (a * b) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
