/**
* ·ÖÎö£ºÇ©µ½Ìâ
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

map<int, string> mp;
bool ischeck[maxn];

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
    int n, k, id, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &id);
        if(i == 1)
            mp[id] = "Mystery Award";
        else if(isPrime(i))
            mp[id] = "Minion";
        else
            mp[id] = "Chocolate";
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &q);
        printf("%04d: ", q);
        if(mp.find(q) != mp.end()) {
            if(!ischeck[q]) {
                cout << mp[q] << endl;
                ischeck[q] = true;
            } else {
                cout << "Checked" << endl;
            }
        } else {
            cout << "Are you kidding?" << endl;
        }
    }
    return 0;
}
