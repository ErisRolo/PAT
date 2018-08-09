/**
* 分析：给出一行数列，找出未出现的最小的正整数
*       因为输入有负数，不容易控制数组大小
*       所以用map而不是hash，否则会导致运行时错误
**/

#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, m;
    map<int, int> mp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        mp[m] = 1;
    }
    m = 1;
    while(m) {
        if(mp.find(m) == mp.end())
            break;
        else
            m++;
    }
    printf("%d\n", m);
    return 0;
}

//int main() {
//    int n, m;
//    int hash[200001];
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &m);
//        hash[m]++;
//    }
//    int p = 1;
//    while(p) {
//        if(hash[p] == 0)
//            break;
//        else
//            p++;
//    }
//    printf("%d\n", p);
//    return 0;
//}
