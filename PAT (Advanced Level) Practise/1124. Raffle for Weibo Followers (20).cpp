/**
* 分析：map映射到整型，默认值是0
*       还是太菜
**/

#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int m, n, s, flag = 0;
    string str;
    map<string, int> mp;
    scanf("%d %d %d", &m, &n, &s);
    for(int i = 1; i <= m; i++) {
        cin >> str;
        if(i == s) {
            if(mp[str] == 0) {
                mp[str] = 1;
                cout << str << endl;
                flag = 1;
                s += n;
            } else {
                s += 1;
            }
        }
    }
    if(flag == 0)
        cout << "Keep going..." << endl;
    return 0;
}
