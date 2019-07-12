#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;

int left1[maxn], right1[maxn];
bool exist[maxn];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string x1, x2;
        cin >> x1 >> x2;
        if(x1 == "-")
            left1[i] = -1;
        else {
            left1[i] = stoi(x1);
            exist[left1[i]] = true;
        }
        if(x2 == "-")
            right1[i] = -1;
        else {
            right1[i] = stoi(x2);
            exist[right1[i]] = true;
        }
    }
    int root = 0;
    while(root < n && exist[root])
        root++;
    int cnt = 0;
    queue<int> q;
    q.push(root);
    bool ans = true;
    int lastnode = 0;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(t != -1) {
            cnt++;
            lastnode = t;
        } else {
            if(cnt != n) {
                cout << "NO " << root << endl;
            } else
                cout << "YES " << lastnode << endl;
            return 0;
        }

        q.push(left1[t]);
        q.push(right1[t]);
    }
    return 0;
}
