/**
* 分析：用连续子列和作为数组存储，则a[1]-a[3]的和可以用s[3]-s[0]来表示
*      显然是递增的，递增有序数列容易想到二分,根据题意，是找第一个大于等于m的右端点
*      关键在于计算upper_bound()的第三个参数，即s[right]-s[left-1]>=m，所以第三个参数为s[left-1]+m
*      第一轮循环找出最接近的值，第二轮循环将每个等于这个值的数列输出，这个值要初始化为一个极大值，且不能用min()函数，因为最后s[n]-s[n]=0
*      注意每轮循环都只用一重+一次二分，不然会超时，这道题多做几遍
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];
int s[maxn];

int main() {
	int n,m,sum=100000010;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
		s[i]=d[i]+s[i-1];
	}
	for(int i=1; i<=n; i++) {
		int pos = lower_bound(s+i,s+n+1,s[i-1]+m)-s; //二分查找s[i]-s[n]，第一个d[i]+...+d[n]=s[n]-s[i-1]≥m的值
//		sum=min(sum,s[pos]);
		if(s[pos]-s[i-1]==m) {
			sum=s[pos]-s[i-1];
			break;
		} else if(s[pos]-s[i-1]<sum && pos<=n) {
			sum=s[pos]-s[i-1];
		}
	}
	for(int i=1; i<=n; i++) {
		int pos = lower_bound(s+i,s+n+1,s[i-1]+sum)-s;
		if(s[pos]-s[i-1]==sum)
			printf("%d-%d\n",i,pos);
	}
	return 0;
}
