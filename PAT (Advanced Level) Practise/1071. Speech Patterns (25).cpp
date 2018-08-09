/**
* 分析：主要是注意一点，res为空时map也会统计其次数
*       出现连续的无效字符时，res[]的次数就会增加
*       因此需要加一个判断，当前单词非空时才统计次数
*       还要注意对字符串末尾进行特判，到了末尾即使是有效数字也要将当前的res统计进map
*       最后就是学习cctype文件下isalnum的使用，可以节省大量代码量
**/

#include <cstdio>
#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string str, res;
    map<string, int> mp;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        if(isalnum(str[i])) {
            str[i] = tolower(str[i]);
            res += str[i];
        }
        if(!isalnum(str[i]) || i == str.size() - 1) {
            if(res.size() != 0)
                mp[res]++;
            res = "";
        }
    }
    int maxn = 0;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second > maxn) {
            maxn = it->second;
            res = it->first;
        }
    }
    cout << res << " " << maxn << endl;
    return 0;
}
