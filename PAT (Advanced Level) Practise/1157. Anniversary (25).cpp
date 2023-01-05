#include <bits/stdc++.h>
using namespace std;

unordered_set<string> sa, sb, sc, st;

int main() {
    int n, m;
    string s, t, res = "";
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        sa.insert(s);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (sa.find(s) != sa.end())
            sb.insert(s);
        else
            sc.insert(s);
    }
    printf("%d\n", sb.size());
    if (sb.size() != 0)
        st = sb;
    else
        st = sc;
    for (auto it = st.begin(); it != st.end(); it++) {
        t = *it;
        if (res == "")
            res = t;
        else if (t.substr(6, 8) < res.substr(6, 8))
            res = t;
    }
    cout << res;
    return 0;
}
