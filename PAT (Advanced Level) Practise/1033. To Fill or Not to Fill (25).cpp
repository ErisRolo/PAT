/**
* 分析：写了好特么久啊！写这种题不要着急动手写，一定要想清楚每一步具体的思路
*       思维要快，这样方便迅速debug
*       看晴神六芒星分布，应该是最难的一道贪心了，虽然时间久但好歹自己想清思路AC掉了 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;

struct station {
	double price; //单价
	double distance; //到杭州的距离
} s[maxn];

bool cmp(station a,station b) {
	return a.distance<b.distance;
}

int main() {
	double c,d,a; // 油箱储量、目的距离、每单位油能跑的距离
	int n; //加油站数量
	double nowTank=0,needTank=0,cost=0;
	scanf("%lf%lf%lf%d",&c,&d,&a,&n);
	double A = c*a; //加满一次油能跑的距离
	for(int i=0; i<n; i++) {
		scanf("%lf%lf",&s[i].price,&s[i].distance);
	}
	s[n].price=0,s[n].distance=d; //把目的地当成油价为0、距离为d的加油站存进数组
	sort(s,s+n,cmp);
	if(s[0].distance==0) {
		for(int i=0; i<n; i++) {
			bool f1=false,f2=false;
			int low = i+1;
			for(int j=i+1; j<=n; j++) {
				if(s[j].distance-s[i].distance<=A) {
					f1=true;
					if(s[j].price<s[i].price) {
						f2=true;
						needTank=(s[j].distance-s[i].distance)/a;
						if(nowTank<needTank) {
							cost+=s[i].price*(needTank-nowTank);
							nowTank=needTank;
						}
						i=j-1;
						break;
					}
					if(s[j].price<s[low].price)
						low=j;
				}
			}
			if(f1&&f2) {
				nowTank-=needTank;
			} else if(f1&&!f2) {
				needTank=(s[low].distance-s[i].distance)/a;
				cost+=s[i].price*(c-nowTank);
				nowTank=c;
				i=low-1;
				nowTank-=needTank;
			} else {
				printf("The maximum travel distance = %.2f\n",s[i].distance+A);
				return 0;
			}
		}
	} else {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	printf("%.2f\n",cost);
	return 0;
}
