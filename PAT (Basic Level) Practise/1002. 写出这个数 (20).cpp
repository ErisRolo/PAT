/**
* 分析：真尼玛菜，乙级题都没能一次A
**/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string chn[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    int sum = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
        sum += str[i] - '0';
    str = to_string(sum);
    for(int i = 0; i < str.size(); i++) {
        cout << chn[str[i] - '0'];
        if(i != str.size() - 1)
            cout << " ";
    }
    return 0;
}
