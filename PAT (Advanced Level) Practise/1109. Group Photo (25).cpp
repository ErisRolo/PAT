#include <bits/stdc++.h>
using namespace std;

int n, k;

struct student {
    string name;
    int ht;
} stu[10010];

string stmp[10010] = { "" };
int u = 0;

bool cmp(student a, student b) {
    if (a.ht != b.ht)
        return a.ht > b.ht;
    else
        return a.name < b.name;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].ht;
    }
    sort(stu, stu + n, cmp);
    for (int j = 0; j < k; j++) {
        if (j == 0) {
            int pvt = (n / k + n % k) / 2;
            int round = 0;
            stmp[pvt] = stu[u++].name;
            while (2 * round + 1 < (n / k + n % k)) {
                round++;
                int left = pvt - round, right = pvt + round;
                if (left >= 0)
                    stmp[left] = stu[u++].name;
                if (right < (n / k + n % k))
                    stmp[right] = stu[u++].name;
            }
            for (int v = 0; v < (n / k + n % k); v++) {
                if (v == 0)
                    cout << stmp[v];
                else
                    cout << " " << stmp[v];
            }
            cout << endl;
        } else {
            int pvt = (n / k) / 2;
            int round = 0;
            stmp[pvt] = stu[u++].name;
            while (2 * round + 1 < (n / k)) {
                round++;
                int left = pvt - round, right = pvt + round;
                if (left >= 0)
                    stmp[left] = stu[u++].name;
                if (right < (n / k))
                    stmp[right] = stu[u++].name;
            }
            for (int v = 0; v < (n / k); v++) {
                if (v == 0)
                    cout << stmp[v];
                else
                    cout << " " << stmp[v];
            }
            cout << endl;
        }
    }
    return 0;
}
