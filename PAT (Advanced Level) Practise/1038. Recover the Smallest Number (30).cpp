/**
* 分析：晴神这道题的算法思路太牛批了，30分的题20多行代码AC
*      注意需要特判全部为0的情况
*      还有因为最高8位数，所以不能读整数去前导0，直接读字符串
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

string s[maxn];

bool cmp(string a,string b) {
	return a+b<b+a;
}

int main() {
	int n;
	string str;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0; i<n; i++)
		str+=s[i];
	while(str.size()!=0&&str[0]=='0') {
		str.erase(str.begin());
	}
	if(str.size()==0)
		cout<<0;
	else
		cout<<str;
	return 0;
}
