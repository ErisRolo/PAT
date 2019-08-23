/**
* 分析：依次判断每位字符，转成数字后再判断范围，学会stod的使用
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int num = 0;
    double temp, ans = 0;
    string s;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> s;
        bool isnum = true, hp = false; //默认是数字，么有小数点
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == '-') //跳过负数的负号
                continue;
            if(!isdigit(s[j]) && s[j] != '.') { //不是数字也不是小数点
                isnum = false;
                break;
            }
            if(s[j] == '.') {
                if(hp) { //如果出现两个以上小数点
                    isnum = false;
                    break;
                } else {
                    hp = true;
                    if(s.size() - j - 1 > 2) { //如果小数点后超过两位
                        isnum = false;
                        break;
                    }
                }
            }
        }
        if(isnum) {
            temp = stod(s);
            if(temp >= -1000 && temp <= 1000) {
                ans += temp;
                num++;
            } else
                cout << "ERROR: " << s << " is not a legal number" << endl;
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }
    if(num == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    if(num == 1)
        printf("The average of 1 number is %.2f\n", ans);
    if(num > 1)
        printf("The average of %d numbers is %.2f\n", num, ans / num);
    return 0;
}
