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
            cout << week[s1[i] - 'A'];
            temp = i;
            break;
        }
    }
    for(int i = temp + 1; i < s1.size() && i < s2.size(); i++) {
        if(s1[i] >= '0' && s1[i] <= '9' && s1[i] == s2[i]) {
            printf("%02d:", s1[i] - '0');
            break;
        }
        if(s1[i] >= 'A' && s1[i] <= 'N' && s1[i] == s2[i]) {
            printf("%d:", s1[i] - 'A' + 10);
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
