/**
* 分析：排序 map
*       去年没找到的错误今年模拟的时候A了，一个段错误，直接把数组翻倍就A了
*       因为参加每个考试的人可能不一样，10000并不是最大人数
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;

map<string, int> id;
map<int, string> name;

struct Stu {
    int id;
    int gp = -1, gm = -1, gf = -1, g;
} stu[maxn];

bool cmp(Stu a, Stu b) {
    if(a.g != b.g)
        return a.g > b.g;
    else
        return name[a.id] < name[b.id];
}

int main() {
    int p, m, n, t, cnt = 0;
    string s;
    scanf("%d%d%d", &p, &m, &n);
    for(int i = 0; i < p; i++) {
        cin >> s >> t;
        if(id.find(s) == id.end()) {
            id[s] = cnt;
            name[cnt] = s;
            stu[cnt].id = cnt;
            cnt++;
        }
        int j = id[s];
        stu[j].gp = t;
    }
    for(int i = 0; i < m; i++) { //有段错误
        cin >> s >> t;
        if(id.find(s) == id.end()) {
            id[s] = cnt;
            name[cnt] = s;
            stu[cnt].id = cnt;
            cnt++;
        }
        int j = id[s];
        stu[j].gm = t;
    }
    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        if(id.find(s) == id.end()) {
            id[s] = cnt;
            name[cnt] = s;
            stu[cnt].id = cnt;
            cnt++;
        }
        int j = id[s];
        stu[j].gf = t;
    }
    //cout<<"cnt="<<cnt<<endl;
    for(int i = 0; i < cnt; i++) {
        if(stu[i].gm > stu[i].gf)
            stu[i].g = (int)round(stu[i].gm * 0.4 + stu[i].gf * 0.6);
        else
            stu[i].g = stu[i].gf;
        //cout<<name[stu[i].id]<<" "<<stu[i].gp<<" "<<stu[i].gm<<" "<<stu[i].gf<<" "<<stu[i].g<<endl;;
    }
    sort(stu, stu + cnt, cmp);
    for(int i = 0; i < cnt; i++) {
        if(stu[i].gp >= 200 && stu[i].g >= 60) {
            printf("%s %d %d %d %d\n", name[stu[i].id].c_str(), stu[i].gp, stu[i].gm, stu[i].gf, stu[i].g);
        }
    }
    return 0;
}












//**
//* 分析：map和结构体排序，得了19分，有一个6分的得分点没拿到
//*       不深究了，这个时间深究逻辑意义不大，各种函数的用法会了就行
//*       注意一个整数四舍五入的小技巧，+0.5然后转换成整型
//**/
//
//#include <cstdio>
//#include <iostream>
//#include <map>
//#include <algorithm>
//using namespace std;
//const int maxn = 10010;
//
//struct Rank {
//    string id;
//    int gp, gm, gf, g;
//} ranks[maxn];
//
//bool cmp(Rank a, Rank b) {
//    if(a.g != b.g)
//        return a.g > b.g;
//    else
//        return a.id < b.id;
//}
//
//int main() {
//    int p, n, m, count = 0;
//    string id;
//    int score, gp, gm, gf, g;
//    map<string, int> gps, gms, gfs, gs;
//    map<string, int>::iterator itp, itm, itf, itg;
//    scanf("%d %d %d", &p, &n, &m);
//    for(int i = 0; i < p; i++) {
//        cin >> id;
//        cin >> score;
//        gps[id] = score;
//    }
//    for(int i = 0; i < n; i++) {
//        cin >> id;
//        cin >> score;
//        gms[id] = score;
//    }
//    for(int i = 0; i < m; i++) {
//        cin >> id;
//        cin >> score;
//        gfs[id] = score;
//    }
//    for(itp = gps.begin(); itp != gps.end(); itp++) {
//        gp = itp->second;
//        if(gp >= 200) {
//            itm = gms.find(itp->first);
//            if(itm == gms.end()) {
//                gms[itp->first] = -1;
//                gm = 0;
//            } else {
//                gm = itm->second;
//            }
//            itf = gfs.find(itp->first);
//            if(itf == gfs.end())
//                continue;
//            else
//                gf = itf->second;
//            if(gm == 0 || gf > gm)
//                g = gf;
//            else
//                g =  int(gm * 0.4 + gf * 0.6 + 0.5);
//            if(g >= 60 && g <= 100) {
//                gs[itp->first] = g;
//                ranks[count].id = itp->first;
//                ranks[count].gp = gp;
//                if(gm == 0)
//                    ranks[count].gm = -1;
//                else
//                    ranks[count].gm = gm;
//                ranks[count].gf = gf;
//                ranks[count].g = g;
//                count++;
//            }
//        }
//    }
//    sort(ranks, ranks + count, cmp);
//    for(int i = 0; i < count; i++) {
//        cout << ranks[i].id << " "
//             << ranks[i].gp << " "
//             << ranks[i].gm << " "
//             << ranks[i].gf << " "
//             << ranks[i].g << endl;
//    }
//    return 0;
//}
