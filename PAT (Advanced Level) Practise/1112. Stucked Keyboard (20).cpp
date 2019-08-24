/**
* 分析：逻辑复杂，容易漏细节，第二个测试点改了半天还是不对，后来发现可能是先判断不是坏键后面又是坏键的情况
*       所以应该判断所有的连续出现次数而不是最大或者最小，这样的话出版代码的算法就没法改了，得直接大换思路了，因此放弃
*       不如改成判断不坏的键，坏键需要判断多处，比如前面判断是坏键，后面又出现不坏的情况，不坏的只要有一处不坏就能保证不是坏键
*       另外统计，不要总想着和前一个字符去比较，这样还要记录，可以直接判断后面k-1个
**/

#include <bits/stdc++.h>
using namespace std;

bool isgood[128];
bool haspush[128];
vector<char> v;

int main() {
    int k;
    string s;
    cin >> k >> s;
    for(int i = 0; i < s.size(); i++) {
        int j = i + 1;
        while(s[j] == s[i] && j < s.size())
            j++;
        if((j - i) % k != 0)
            isgood[s[i]] = true;
        i = j - 1;
    }
    for(int i = 0; i < s.size(); i++) {
        if(isgood[s[i]] == false && haspush[s[i]] == false) {
            v.push_back(s[i]);
            haspush[s[i]] = true;
        }
    }
    for(auto i : v)
        cout << i;
    cout << endl;
    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
        if(isgood[s[i]] == false)
            i += k - 1;
    }
    return 0;
}






//int temp[256],minlen[256];
//bool isfalse[256];
//vector<char> v;
//
//int main() {
//	int k;
//	string s,ans;
//	cin>>k>>s;
//	for(int i=0; i<s.size(); i++)
//		minlen[s[i]]=1010;
//	bool flag=false;
//	for(int i=1; i<s.size(); i++) {
//		if(s[i]==s[i-1]) { //当前字符与前一个相同
//			if(flag==false) { //第一次连续，即出现两次的时候
//				flag=true; //设为正在处理连续字符
//				temp[s[i]]=2; //已经出现的连续次数为2
//			} else
//				temp[s[i]]++; //继续连续继续统计
//			if(i==s.size()-1)
//				minlen[s[i]]=min(temp[s[i]],minlen[s[i]]); //对最后一个字符特判
//		} else { //如果当前字符与前一个不同
//			if(flag) { //如果前一个字符是连续字符 更新其最小值
//				minlen[s[i-1]]=min(temp[s[i-1]],minlen[s[i-1]]);
//				flag=false; //标记没有连续字符
//			} else
//				minlen[s[i-1]]=1; //如果前一个字符不是连续字符 将其连续出现最小次数更新为1
//			if(i==s.size()-1)
//				minlen[s[i]]=1; //对最后一个字符特判
//		}
//	}
//	for(int i=0; i<s.size(); i++) {
//		if(minlen[s[i]]%k==0&&isfalse[s[i]]==false) { //minlen为k的倍数的即为坏键，isfalse保证只统计一次
//			v.push_back(s[i]);
//			isfalse[s[i]]=true;
//		}
//	}
//	for(auto i:v)
//		printf("%c",i);
//	printf("\n");
//	int num=0;
//	for(int i=0; i<s.size(); i++) {
//		ans+=s[i];
//		if(isfalse[s[i]]) {
//			num++;
//			if(num==k) {
//				ans=ans.substr(0,ans.size()-(k-1));
//				num=0;
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
