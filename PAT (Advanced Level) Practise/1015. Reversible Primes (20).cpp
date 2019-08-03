/**
* 分析：需要熟练掌握素数判断和进制转换，至于数位翻转，用一下string和reverse即可
*       值得注意的是这道题不是单点测试，回忆一下while...EOF的写法
*       算法思路和晴神一样，但对于逆序数组的处理上不一样，原写法有一个运行时错误
*       改成晴神的更简便一些，因为经过正好得到逆序数组，无需翻转可以直接累乘得到新的十进制
**/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {
        if(n < 0)
            break;
        scanf("%d", &d);
        if(isPrime(n) == false) {
            printf("No\n");
        } else {
            //十进制转d进制
            int t[111], num = 0;
            do {
                t[num++] = n % d;
                n = n / d;
            } while(n != 0);
            //d进制转十进制
            for(int i = 0; i < num; i++) {
                n = n * d + t[i];
            }
//			string s;
//			for(int i=num-1; i>=0; i--) {
//				s+=to_string(t[i]);
//			}
//			reverse(s.begin(),s.end());
//			n=stoi(s);
//			int m=0,product=1;
//			while(n!=0) {
//				m=m+(n%10)*product;
//				n=n/10;
//				product*=d;
//			}
            if(isPrime(n) == true)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
