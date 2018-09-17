/**
* 分析：搞不懂让我们做Java Web课设还要求框架有什么意义
**/

#include <cstdio>
#include <iostream>
using namespace std;

string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int i;
    for(i = 0; i < s1.size() && i < s2.size(); i++) {
        if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
            break;

    }
    cout << week[s1[i] - 'A'];
    i++;
    for(; i < s1.size() && i < s2.size(); i++) {
        if(s1[i] == s2[i] && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')))
            break;
    }
    if(s1[i] >= '0' && s1[i] <= '9')
        cout << "0" << s1[i] - '0' << ":";
    else
        cout << s1[i] - 'A' + 10 << ":";
    for(i = 0; i < s3.size() && i < s4.size(); i++) {
        if(s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')))
            break;
    }
    if(i < 10)
        cout << "0" << i;
    else
        cout << i;
    return 0;
}
