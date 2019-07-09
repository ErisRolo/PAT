#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

struct GasStation {
    double price;
    double dis;
    GasStation(double _p, double _d) : price(_p), dis(_d) {}
};

int compare(GasStation a, GasStation b) {
    return a.dis < b.dis;
}

int main() {
    int cons, gasCnt;
    double cap;
    double dis;
    double price;
    double dist;
    vector<GasStation> stations;
    cin >> cap >> dis >> cons >> gasCnt;
    double maxToGo = cap * cons;
    for(int i = 0; i < gasCnt; i++) {
        scanf("%lf %lf", &price, &dist);
        stations.push_back(GasStation(price, dist));
    }
    sort(stations.begin(), stations.end(), compare);
    if(stations[0].dis > 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int cur = 0;
    double now_cap = 0;
    double sumPrice = 0;
    int curEnd = stations.size();
    double stationPrice = 0;
    double stationDis = 0;
    int hasStation = 0;
    int dest = 0;
    // 如果有多个起点加油站，选择那个最便宜的加油。
    // 事实证明题目中并没有此类不符合实际的陷阱。
    int minPrice = stations[0].price;
    for(int i = 0; i < stations.size(); i++) {
        if(stations[i].dis == 0) {
            if(minPrice > stations[i].price) {
                cur = i;
            }
        } else
            break;
    }
    while(cur < curEnd) {
        stationPrice = stations[cur].price;
        stationDis = stations[cur].dis;
        dest = -1;
        hasStation = 0;
        for(int i = cur + 1; i < stations.size(); i++) { // 首先判断当前站点之后有没有可以到达的
            if((stations[i].dis - stationDis) <= maxToGo) { // 发现有可到达的站点，再找出最近且最便宜的。
                hasStation = 1;
                // 找出最便宜的有两种情况，第一是有比当前站点便宜的，到达最近的满足条件的这样的站点。
                // 或者都比当前站点贵，则加油到能到达最便宜的那个。
                // 这两个判断是冲突的，因为有比当期便宜的时候选择的不是那个最便宜的而是最近的，都贵的时候找的是最便宜的
                // 因此先判断有没有比当前便宜的，没有再进一步找那个贵中最便宜的。
                if(stationPrice > stations[i].price) { // 找到了更便宜的，在这里中断查找，保证找到的是最近的。
                    dest = i;
                    break;
                }
            } else { // 都没有可到达的站点了。
                break;
            }
        }
        if(hasStation != 1) { // 没有可到达站点
            if((dis - stationDis) <= maxToGo) { // 能跑到终点，则加油到可以跑到终点
                double need = dis - stationDis;
                if(now_cap * cons >= need) { // 油足够到达
                    break;
                } else { // 油不够，加到能跑到终点
                    double last = (need - now_cap * cons);
                    sumPrice += (last / cons) * stationPrice;
                    break;
                }
            } else { // 跑不到终点，能跑多远跑多远
                double sumDis = stationDis + cap * cons;
                printf("The maximum travel distance = %.2lf\n", sumDis);
                return 0;
            }
        } else { // 有可以到达的站点
            if(dest != -1) { // 找到了比当前便宜且距离当前最近的加油站，加油到跑到那里，然后继续在那个站点考虑
                double need = stations[dest].dis - stationDis;
                if(need <= now_cap * cons) { // 油足够到达
                    now_cap -= need / cons;
                } else { // 油不够，补齐
                    sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    now_cap = 0; // 跑过去就没有油了
                }
                cur = dest;
            } else { // 没有便宜的，选择那个最便宜的加油跑过去。
                // ！！！先看能否到终点，能到就直接到终点，一定注意这种情况！！！
                if((dis - stationDis) <= maxToGo) {
                    double need = dis - stationDis;
                    if(now_cap * cons < need) {
                        sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    }
                    break;
                }
                int minPrice = INF;
                int minCur = -1;
                for(int i = cur + 1; i < stations.size(); i++) {
                    if((stations[i].dis - stationDis) < maxToGo) {
                        if(stations[i].price < minPrice) {
                            minPrice = stations[i].price;
                            minCur = i;
                        }
                    } else {
                        break;
                    }
                }
                cur = minCur;
                sumPrice += (cap - now_cap) * stationPrice;
                now_cap = cap - (stations[cur].dis - stationDis) / cons;
            }
        }
    }
    printf("%.2lf\n", sumPrice);
    return 0;
}
