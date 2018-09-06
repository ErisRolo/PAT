#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string ans, temp;
int n, cnt = 0;
bool flag[10];

string inttostr(int d) {
    string str;
    while(d) {
        str += d % 10 + '0';
        d /= 10;
    }
    return str;
}

int main() {
    cin >> ans >> n;
    for(int k = 1; k < n; k++) {
        int i, j;
        temp = "";
        for( i = 0; i < ans.size(); i = j) {
            for( j = i; j < ans.size() && ans[j] == ans[i]; j++) {
                cnt++;
            }
            temp += ans[i] + inttostr(cnt);
            cnt = 0;
        }
        ans = temp;
    }
    cout << ans;
    return 0;
}
