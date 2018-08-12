/**
* 分析：map和结构体排序，得了19分，有一个6分的得分点没拿到
*       不深究了，这个时间深究逻辑意义不大，各种函数的用法会了就行
*       注意一个整数四舍五入的小技巧，+0.5然后转换成整型
*       附赠柳神的代码
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node {
    string name;
    int gp, gm, gf, g;
};

bool cmp(node a, node b) {
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}

map<string, int> idx;

int main() {
    int p, m, n, score, cnt = 1;
    cin >> p >> m >> n;
    vector<node> v, ans;
    string s;
    for (int i = 0; i < p; i++) {
        cin >> s >> score;
        if (score >= 200) {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> s >> score;
        if (idx[s] != 0)
            v[idx[s] - 1].gm = score;
    }
    for (int i = 0; i < n; i++) {
        cin >> s >> score;
        if (idx[s] != 0) {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf)
                v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].g >= 60)
            ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    return 0;
}
/*

#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;

struct Rank {
    string id;
    int gp, gm, gf, g;
} ranks[maxn];

bool cmp(Rank a, Rank b) {
    if(a.g != b.g)
        return a.g > b.g;
    else
        return a.id < b.id;
}

int main() {
    int p, n, m, count = 0;
    string id;
    int score, gp, gm, gf, g;
    map<string, int> gps, gms, gfs, gs;
    map<string, int>::iterator itp, itm, itf, itg;
    scanf("%d %d %d", &p, &n, &m);
    for(int i = 0; i < p; i++) {
        cin >> id;
        cin >> score;
        gps[id] = score;
    }
    for(int i = 0; i < n; i++) {
        cin >> id;
        cin >> score;
        gms[id] = score;
    }
    for(int i = 0; i < m; i++) {
        cin >> id;
        cin >> score;
        gfs[id] = score;
    }
    for(itp = gps.begin(); itp != gps.end(); itp++) {
        gp = itp->second;
        if(gp >= 200) {
            itm = gms.find(itp->first);
            if(itm == gms.end()) {
                gms[itp->first] = -1;
                gm = 0;
            } else {
                gm = itm->second;
            }
            itf = gfs.find(itp->first);
            if(itf == gfs.end())
                continue;
            else
                gf = itf->second;
            if(gm == 0 || gf > gm)
                g = gf;
            else
                g =  int(gm * 0.4 + gf * 0.6 + 0.5);
            if(g >= 60 && g <= 100) {
                gs[itp->first] = g;
                ranks[count].id = itp->first;
                ranks[count].gp = gp;
                if(gm == 0)
                    ranks[count].gm = -1;
                else
                    ranks[count].gm = gm;
                ranks[count].gf = gf;
                ranks[count].g = g;
                count++;
            }
        }
    }
    sort(ranks, ranks + count, cmp);
    for(int i = 0; i < count; i++) {
        cout << ranks[i].id << " "
             << ranks[i].gp << " "
             << ranks[i].gm << " "
             << ranks[i].gf << " "
             << ranks[i].g << endl;
    }
    return 0;
}

*/
