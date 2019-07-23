/**
* 分析：首先判断是否输出正负，然后对每一位分别判断，要习惯这种找规律的方法 
*       如果非0则必读出数字，根据位置判断是否输出数位，其中若输出千百十则前面一个数必不为0，所以判断语句的位置要准确
*       如果为0则根据下一位来判断，当前位不是最后一位且下一位非0则输出
*       用一个vector存储结果，可以方便处理空格
*       别忘了要对单独一个0进行特判
**/
#include <bits/stdc++.h>
using namespace std;

string num[10]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> ans;

int main() {
	string s;
	cin>>s;
	if(s=="0")
		cout<<"ling";
	if(s[0]=='-') {
		cout<<"Fu ";
		s= s.substr(1,s.size()-1);
	}
	for(int i=0; i<s.size(); i++) {
		int d = s[i]-'0';
		if(d!=0) {
			ans.push_back(num[d]);
			if(s.size()-i==8 || s.size()-i==4)
				ans.push_back("Qian");
			if(s.size()-i==7 || s.size()-i==3)
				ans.push_back("Bai");
			if(s.size()-i==6 || s.size()-i==2)
				ans.push_back("Shi");
		} else {
			if(i!=s.size()-1&&s[i+1]!='0')
				ans.push_back(num[0]);
		}
		if(s.size()-i==9)
			ans.push_back("Yi");
		if(s.size()-i==5)
			ans.push_back("Wan");
	}
	for(vector<string>::iterator it = ans.begin(); it!=ans.end(); it++) {
		cout<<*it;
		if(it!=ans.end()-1)
			cout<<" ";
	}
	return 0;
}
