/**
* 分析：简单题应尽可能快地完成
*       因为要查找字符在字符串中位置相同，所以遍历时用一个变量i即可
*       注意用字符数组输出星期和用差值表示时间的技巧
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};

int main() {
    int temp;
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    for(int i = 0; i < s1.size() && i < s2.size(); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i]) {
            cout << week[s1[i] - 'A']; //输出星期
            temp = i;
            break;
        }
    }
    for(int i = temp + 1; i < s1.size() && i < s2.size(); i++) {
        if(s1[i] >= '0' && s1[i] <= '9' && s1[i] == s2[i]) {
            printf("%02d:", s1[i] - '0'); //输出00:00-09:00
            break;
        }
        if(s1[i] >= 'A' && s1[i] <= 'N' && s1[i] == s2[i]) {
            printf("%d:", s1[i] - 'A' + 10); //输出10:00-23:00
            break;
        }
    }
    for(int i = 0; i < s3.size() && i < s4.size(); i++) {
        if(s3[i] == s4[i]) {
            if((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')) {
                printf("%02d", i);
                break;
            }
        }
    }
    return 0;
}
