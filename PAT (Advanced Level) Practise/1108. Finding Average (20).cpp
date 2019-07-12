#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;

bool Judge(string s, double &x) {
    int dot = 0, n1 = 0, n2 = 0;
    int i = 0;
    if(s[i] == '-')
        i++;
    for(; i < s.size(); i++) {
        if(s[i] == '.') {
            dot++;
            if(dot > 1)
                return 0;
        } else if(s[i] >= '0' && s[i] <= '9') {
            if(dot)
                n2++;
            else
                n1++;
        } else
            return 0;
    }
    if(n2 > 2)
        return 0;
    sscanf(s.c_str(), "%lf", &x);
    if(x >= -1000 && x <= 1000)
        return 1;
    return 0;
}

int main() {
    int n, cnt = 0;
    double x, ans = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(Judge(s, x)) {
            cnt++;
            ans += x;
        } else {
            cout << "ERROR: " << s << " is not a legal number\n";
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2f\n", ans);
        return 0;
    }
    printf("The average of %d numbers is ", cnt);
    if(cnt)
        printf("%.2f\n", ans / cnt);
    else
        cout << "Undefined\n";
    return 0;
}
