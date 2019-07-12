#include <bits/stdc++.h>
using namespace std;
const int N = 10000;

int a[N], n, b;

//判断素数
bool is_p(int a) {
    if(a == 1)
        return false;
    for(int i = 2 ; i <= sqrt(a) ; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    //信息输入
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &b);
        if(i == 1)
            a[b] = 1;
        else if(is_p(i))
            a[b] = 2;
        else
            a[b] = 3;
    }
    //查询操作
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &b);
        if(a[b] == 1) {
            printf("%04d: Mystery Award\n", b);
            a[b] = -1;
            continue;
        }
        if(a[b] == 2) {
            printf("%04d: Minion\n", b);
            a[b] = -1;
            continue;
        }
        if(a[b] == 3) {
            printf("%04d: Chocolate\n", b);
            a[b] = -1;
            continue;
        }
        if(a[b] == 0) {
            printf("%04d: Are you kidding?\n", b);
            continue;
        }
        if(a[b] == -1) {
            printf("%04d: Checked\n", b);
            a[b] = -1;
            continue;
        }

    }
    return 0;
}
