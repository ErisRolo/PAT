/**
* 分析：学习set插入结构体和运算符重载的定义格式，以及不能直接修改set内的元素，需要删除并重新插入
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;

struct node {
    int id, cnt;
    bool operator < (const node &a)const {
        return cnt != a.cnt ? cnt > a.cnt : id < a.id;
    }
};

set<node> st;
int cnt[maxn]; //记录次数

int main() {
    int n, k, q;
    scanf("%d%d", &n, &k);
    scanf("%d", &q);
    st.insert({q, 1}); //处理第一个输入
    cnt[q] = 1;
    for(int i = 1; i < n; i++) {
        scanf("%d", &q);
        printf("%d:", q);
        int num = 0;
        for(auto it = st.begin(); it != st.end() && num < k; it++) {
            printf(" %d", it->id);
            num++;
        }
        printf("\n");
        if(cnt[q] > 0) //如果已存在 删除
            st.erase({q, cnt[q]});
        cnt[q]++;
        st.insert({q, cnt[q]});
    }
    return 0;
}
