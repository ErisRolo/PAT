/**
* 分析：思路正确，实现不对，原算法还有两个TLE只有19分
*      参考晴神标程重新写
*      学会用数组存位置的思想，一定要记得用，还有用预处理变量控制循环条件，以及swap()的使用
*      循环找不在本位数时，适当剪枝，不然会有两个测试点TLE，估计我原答案也是那里的问题 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int pos[maxn];

int main() {
	int n,temp,left=0,cnt=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&temp);
		pos[temp]=i;
		if(pos[temp]!=temp && temp!=0)
			left++;
	}
	int k=1; //不然会超时
	while(left>0) {
		if(pos[0]==0) {
			while(k<n) {
				if(pos[i]!=i) {
					swap(pos[0],pos[i]);
					cnt++;
					break;
				}
				k++;
			}
		}
		swap(pos[0],pos[pos[0]]);
		cnt++;
		left--;
	}
	printf("%d\n",cnt);
	return 0;
}





//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 100010;
//
//int d[maxn];
//
//int main() {
//	int n,pos0,post,left=0,cnt=0;
//	scanf("%d",&n);
//	for(int i=0; i<n; i++) {
//		scanf("%d",&d[i]);
//		if(d[i]==0)
//			pos0=i; //记录0的位置
//		if(d[i]!=i && d[i]!=0)
//			left++;
//	}
//	while(left>0) {
//		if(pos0==0) {
//			for(int i=0; i<n; i++) {
//				if(d[i]!=i) {
//					d[0]=d[i];
//					d[i]=0;
//					pos0=i;
//					cnt++;
//					break;
//				}
//			}
//		}
//		if(d[pos0]!=pos0) {
//			for(int i=0; i<n; i++) {
//				if(d[i]==pos0) {
//					post=i;
//				}
//			}
//			d[pos0]=pos0;
//			d[post]=0;
//			pos0=post;
//			cnt++;
//			left--;
//		}
//	}
//	printf("%d\n",cnt);
//	return 0;
//}
