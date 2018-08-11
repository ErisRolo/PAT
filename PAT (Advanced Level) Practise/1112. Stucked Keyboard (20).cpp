/**
* 分析：这题，，不想说啥了。。
*       还以为能训练map，结果是逻辑题。。。
*       不过关于元素声明学到了点东西，可以了。。。
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool isStucked[128];
bool isNotStucked[128];
bool isVisit[128];

int main() {
    int k, count = 1;
    string str;
    cin >> k ;
    cin >> str;
    char stucked = str[0];
    for(int i = 1; i < str.size(); i++) {
        if(str[i] == stucked) {
            count++;
        } else {
            //要想着用是不是k的倍数来判断，而不是是不是比k大，因为只有每次输出都是k的整数倍的才是坏键
            if(count % k == 0 ) {
                isStucked[str[i - 1]] = true; //暂时设为true
            } else {
                isStucked[str[i - 1]] = false; //不能被k整除
                isNotStucked[str[i - 1]] = true; //只要确定不是坏键，后续输出k的倍数也不能说是坏键
            }
            count = 1;
            stucked = str[i];
        }
    }
    //对最后一个字符特判，防止出现没有统计完次数的情况
    if(count % k == 0 && isNotStucked[str[str.size() - 1]] == false) {
        isStucked[str[str.size() - 1]] = true;
    }
    for(int i = 0; i < str.size(); i++) {
        if(isStucked[str[i]] == true && isVisit[str[i]] == false) {
            cout << str[i];
            isVisit[str[i]] = true;
        }
    }
    cout << endl;
    for(int i = 0; i < str.size(); i++) {
        cout << str[i];
        if(isStucked[str[i]] == true)
            i = i + k - 1;
    }
    return 0;
}
