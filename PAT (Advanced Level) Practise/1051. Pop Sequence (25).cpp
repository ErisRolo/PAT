/**
* 分析：判断栈的出栈顺序是否为合法序列，主要思路是直接模拟一个栈的入栈出栈
*       先用一个数组存储序列，将栈清空后，从1-n分别入栈，如果栈顶元素等于序列待出栈数字就将其出栈
*       如果入栈后超过栈的大小则为非法序列，最后栈空且过程中没有超过限定大小则为合法序列
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int main() {
    int m, n, k;
    int q[maxn];
    stack<int> st;
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &q[j]);
        }
        while(!st.empty()) {
            st.pop();
        }
        bool flag = true;
        int pos = 0;
        for(int j = 1; j <= n; j++) {
            st.push(j);
            if(st.size() > m) {
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == q[pos]) {
                st.pop();
                pos++;
            }
        }
        if(st.empty() && flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
