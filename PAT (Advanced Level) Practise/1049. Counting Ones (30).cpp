/**
* 分析：三分钟22分血赚，有两个点TLE，剩下8分肯定不能用现在的算法
*       根据晴神的算法，首先要掌握分割数位，从低到高分出当前位和当前位左边的数和右边的数
*       然后根据当前位分情况讨论，这里可以先写一个大一点的数找规律，即当前位为0为1位大于1的数时分别有多少种情况
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 1, ans = 0;
    int left, now, right;
    scanf("%d", &n);
    while(n / a != 0) {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if(now == 0) {
            ans += left * a;
        } else if(now == 1) {
            ans += left * a + 1 + right;
        } else {
            ans += (left + 1) * a;
        }
        a *= 10;
    }
    printf("%d\n", ans);
    return 0;
}








//int main() {
//	int n,cnt=0;
//	scanf("%d",&n);
//	for(int i=1; i<=n; i++) {
//		string s = to_string(i);
//		for(int i=0; i<s.size(); i++) {
//			if(s[i]=='1')
//				cnt++;
//		}
//	}
//	printf("%d",cnt);
//	return 0;
//}
