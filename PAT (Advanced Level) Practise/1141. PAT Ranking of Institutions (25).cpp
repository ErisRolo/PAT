/**
* 分析：分数分开统计，最后再除，不然有一个点WA
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct Rank {
    string name;
    int score, sa, sb, st;
    int num;
    int r;
    Rank() {
        score = 0, sa = 0, sb = 0, st = 0;
        num = 0;
    }
} R[maxn];

bool cmp(Rank a, Rank b) {
    if(a.score != b.score)
        return a.score > b.score;
    else if(a.num != b.num)
        return a.num < b.num;
    else
        return a.name < b.name;
}

map<string, int> mp; //为学校编号

int main() {
    int n, score, cnt = 0;
    string id, sch;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> id >> score >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower);
        if(mp.find(sch) == mp.end()) {
            mp[sch] = cnt;
            R[cnt].name = sch;
            cnt++;
        }
        if(id[0] == 'A')
            R[mp[sch]].sa += score;
        else if(id[0] == 'B')
            R[mp[sch]].sb += score;
        else if(id[0] == 'T')
            R[mp[sch]].st += score;
        R[mp[sch]].score += score;
        R[mp[sch]].num++;
    }
    for(int i = 0; i < cnt; i++)
        R[i].score = R[i].sb / 1.5 + R[i].sa + R[i].st * 1.5;
    sort(R, R + cnt, cmp);
    R[0].r = 1;
    for(int i = 1; i < cnt; i++) {
        if(R[i].score == R[i - 1].score)
            R[i].r = R[i - 1].r;
        else
            R[i].r = i + 1;
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
        cout << R[i].r << " " << R[i].name << " " << R[i].score << " " << R[i].num << endl;
    return 0;
}
