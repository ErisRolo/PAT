/**
* 分析：这贪心题跟模拟似的，我觉得我的思路也不算贪心但也AC了，还只用了15分钟不到。。。 
**/

#include <bits/stdc++.h>
using namespace std;

bool cmp1(int a,int b) {
	return a>b;
}

bool cmp2(int a,int b) {
	return a<b;
}

int main() {
	int c,p,d,res=0;
	vector<int> vc1,vc2,vp1,vp2;
	scanf("%d",&c);
	for(int i=0; i<c; i++) {
		scanf("%d",&d);
		if(d>0)
			vc1.push_back(d);
		else
			vc2.push_back(d);
	}
	scanf("%d",&p);
	for(int i=0; i<p; i++) {
		scanf("%d",&d);
		if(d>0)
			vp1.push_back(d);
		else
			vp2.push_back(d);
	}
	sort(vc1.begin(),vc1.end(),cmp1);
	sort(vp1.begin(),vp1.end(),cmp1);
	for(int i=0; i<vc1.size()&&i<vp1.size(); i++) {
		res+=vc1[i]*vp1[i];
	}
	sort(vc2.begin(),vc2.end(),cmp2);
	sort(vp2.begin(),vp2.end(),cmp2);
	for(int i=0; i<vc2.size()&&i<vp2.size(); i++) {
		if(vc2[i]*vp2[i]>0) {
			res+=vc2[i]*vp2[i];
		}
	}
	printf("%d\n",res);
	return 0;
}
