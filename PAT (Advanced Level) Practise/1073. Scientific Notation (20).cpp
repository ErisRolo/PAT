#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string num, ep;
    char ns, es;
    int e;
    cin >> s;
    e = s.find("E");
    num = s.substr(1, e - 1);
    ns = s[0];
    es = s[e + 1];
    ep = s.substr(e + 2);
    num.erase(1, 1);
    if(ns == '-')
        cout << ns;
    if(es == '-') {
        cout << "0.";
        for(int i = 1; i < stoi(ep); i++) {
            cout << "0";
        }
        cout << num;
    } else {
        if(stoi(ep) >= num.length() - 1) {
            cout << num;
            for(int i = 0; i < stoi(ep) - num.length() + 1; i++) {
                cout << "0";
            }
        } else {
            num.insert(stoi(ep) + 1, ".");
            cout << num;
        }
    }
    return 0;
}
