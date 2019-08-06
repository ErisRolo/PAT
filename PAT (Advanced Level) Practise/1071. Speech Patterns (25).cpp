/**
* 分析：注意isalnum()的使用，判断是否为数字或字母，还有记得大写要转成小写，tolower函数的使用
*       一开始写的O(n^2)的算法不好，还有两个WA，是思路有问题，直接遍历一遍就好
*       新算法的坑点在于，每次临时字符串清空后，遇到的下一个字符仍是非法字符，则会统计一个空字符串的次数
*       因此只有单词非空时才统计次数
**/

#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    int max = 0;
    string s, res;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            res += s[i];
        }
        if(!isalnum(s[i]) || i == s.size() - 1) {
            if(res != "")
                mp[res]++;
            res = ""; //这里导致的单词可能为空
        }
    }

//	for(int i=0; i<s.size(); i++) {
//		if(isalnum(s[i])) {
//			if(s[i]>='A'&&s[i]<='Z')
//				s[i]=tolower(s[i]); //先大写转小写
//			for(int j=i+1; j<s.size(); j++) {
//				if(!isalnum(s[j])) {
//					string temp = s.substr(i,j-i);
//					mp[temp]++;
//					i=j;
//					break;
//				}
//			}
//		}
//	}

    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it->second > max) {
            max = it->second;
            res = it->first;
        }
    }
    cout << res << " " << max << endl;
    return 0;
}
