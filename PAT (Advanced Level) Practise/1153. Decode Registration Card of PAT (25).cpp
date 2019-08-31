/**
* 分析：大排序的输入输出一定要尽量用printf和scanf，慎用cin和cout
*       如果TLE，尝试把用到的静态数组换成vector或者vector换成静态数组
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int n, m, score, type, cnt, sum;
string s, item;
bool flag;
unordered_map<string, int> mp;

struct card {
    string level, site, date, testee, num;
    int score;
} c[maxn];

struct sitenum {
    string site;
    int num;
};

bool cmp1(card a, card b) {
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.num < b.num;
}

bool cmp3(sitenum a, sitenum b) {
    if(a.num != b.num)
        return a.num > b.num;
    else
        return a.site < b.site;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        cin >> s;
        scanf("%d", &score);
        c[i].level = s[0];
        c[i].site = s.substr(1, 3);
        c[i].date = s.substr(4, 6);
        c[i].num = s;
        c[i].score = score;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &type);
        cin >> item;
        printf("Case %d: %d %s\n", i, type, item.c_str());
        flag = false;
        if(type == 1) {
            sort(c, c + n, cmp1);
            for(int j = 0; j < n; j++) {
                if(c[j].level == item) {
                    printf("%s %d\n", c[j].num.c_str(), c[j].score);
                    flag = true;
                }
            }
            if(!flag)
                printf("NA\n");
        } else if(type == 2) {
            cnt = 0, sum = 0;
            for(int j = 0; j < n; j++) {
                if(c[j].site == item) {
                    cnt++;
                    sum += c[j].score;
                    flag = true;
                }
            }
            if(flag)
                printf("%d %d\n", cnt, sum);
            else
                printf("NA\n");
        } else if(type == 3) {
            cnt = 0;
            mp.clear();
            vector<sitenum> sn;
            for(int j = 0; j < n; j++) {
                if(c[j].date == item) {
                    flag = true;
                    if(mp.find(c[j].site) == mp.end()) {
                        mp[c[j].site] = cnt;
                        sn.push_back({c[j].site, 1});
                        cnt++;
                    } else
                        sn[mp[c[j].site]].num++;
                }
            }
            if(flag) {
                sort(sn.begin(), sn.end(), cmp3);
                for(int j = 0; j < cnt; j++)
                    printf("%s %d\n", sn[j].site.c_str(), sn[j].num);
            } else
                printf("NA\n");
        }
    }
    return 0;
}
