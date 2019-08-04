/**
* 分析：判断回文串，因为所给范围10^10，所以为高精度运算，还是要熟练要快
*       不过这题就25分，可以只用字符串操作，看看网上的简便算法
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

struct bign {
    int d[maxn];
    int len;
    bign() {
        fill(d, d + maxn, 0);
        len = 0;
    }
};

bign strToBign(string s) {
    bign n;
    for(int i = s.size() - 1; i >= 0; i--)
        n.d[n.len++] = s[i] - '0';
    return n;
}

bign addBign(bign a, bign b) {
    bign c;
    int i, carry = 0;
    for( i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        carry = temp / 10;
        c.d[c.len++] = temp % 10;
    }
    if(carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

void print(bign n) {
    for(int i = n.len - 1; i >= 0; i--)
        printf("%d", n.d[i]);
}

bool judge(bign n) {
    for(int i = 0; i < n.len / 2; i++) {
        if(n.d[i] != n.d[n.len - 1 - i])
            return false;
    }
    return true;
}

int main() {
    string s;
    int k, step = 0;
    cin >> s >> k;
    bign a = strToBign(s);
    while(judge(a) == false && step < k) {
        bign b, c;
        b.len = a.len;
        for(int i = 0; i < a.len; i++)
            b.d[i] = a.d[a.len - 1 - i];
        c = addBign(a, b);
        a = c;
        step++;
    }
    print(a);
    printf("\n%d", step);
    return 0;
}
