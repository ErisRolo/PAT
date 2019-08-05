/**
* 分析：distinct number的意思是不重复数字，很容易想到set，20分钟有一个点TLE
*       分析知计算nt的时候用了第二重循环，迭代器的速度很快，但是循环的速度很慢，所以改成直接计算nt
*       对比去年的代码我真的变强了
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 51;

set<int> s[maxn];

int main() {
    int n, m, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 1; j <= m; j++) {
            scanf("%d", &t);
            s[i].insert(t);
        }
    }
    int k, a, b;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d%d", &a, &b);
        double nc = 0, nt = 0;
        for(auto it = s[a].begin(); it != s[a].end(); it++) {
            if(s[b].find(*it) != s[b].end())
                nc++;
        }
        nt = s[a].size() + s[b].size() - nc;
        printf("%.1f%\n", nc / nt * 100);
    }
    return 0;
}




//**
//* 分析：考查set的使用，记住set的使用情形和相关函数即可，理清这道题的逻辑
//*       此题要读清题意，即判断两个集合的交集占并集的百分比，定义一个set数组把每组数据储存在set里即可
//*       然后注意遍历第一个集合即可，直接查找第二个集合中有无相同元素然后统计，这样可以大大降低时间复杂度
//*       还要注意输出格式以及浮点数运算乘一个.0
//**/
//
//#include <cstdio>
//#include <set>
//using namespace std;
//const int maxn = 50;
//
//int main() {
//    int n, m, k, temp, s1, s2, sameNum = 0, totalNum = 0;
//    set<int> num[maxn];
//    set<int>::iterator it;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &m);
//        for(int j = 0; j < m; j++) {
//            scanf("%d", &temp);
//            num[i].insert(temp);
//        }
//    }
//    scanf("%d", &k);
//    for(int i = 0; i < k; i++) {
//        scanf("%d %d", &s1, &s2);
//        s1 = s1 - 1;
//        s2 = s2 - 1;
//        for( it = num[s1].begin(); it != num[s1].end(); it++) {
//            if(num[s2].find(*it) != num[s2].end())
//                sameNum++;
//        }
//        totalNum = num[s1].size() + num[s2].size() - sameNum;
//        printf("%.1f%%\n", sameNum * 100.0 / totalNum);
//        sameNum = 0;
//        totalNum = 0;
//    }
//    return 0;
//}
