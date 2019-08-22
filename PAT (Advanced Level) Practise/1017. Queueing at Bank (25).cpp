/**
* 分析：快乐模拟，给出到达时间和处理时间，计算平均等待时间，其实这道题过程还是比较清晰的
*       题目里说超过17:00未被服务的客户不被计算在客户中，然而没有处理这一逻辑
*       如minEndTime算出17:01，仍会计算其等待时间
*       估计题目想说的意思仅是17:00未到达的客户不被计算
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxk = 110;
const int inf = 1000000000;

struct customer {
    int t, p; //到达时间 处理时间
};

bool cmp(customer a, customer b) {
    return a.t < b.t;
}

vector<customer> c; //有效客户队列
int endTime[maxk]; //endTime[i]：i号窗口当前客户的服务结束时间

int main() {
    int n, k, ans = 0;
    int h, m, s, p;
    int early = 8 * 3600, late = 17 * 3600;
    scanf("%d%d", &n, &k);
    fill(endTime, endTime + k, early); //每个窗口的服务结束时间初始化为营业时间
    for(int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int t = h * 3600 + m * 60 + s;
        if(p > 60)
            p = 60;
        p *= 60;
        if(t <= late) {
            customer temp;
            temp.t = t, temp.p = p;
            c.push_back(temp);
        }
    }
    sort(c.begin(), c.end(), cmp);
    for(int i = 0; i < c.size(); i++) { //计算每个客户的等待时间
        int idx = -1, minEndTime = inf; //查找当前最早服务结束的窗口 并记录时间
        for(int j = 0; j < k; j++) {
            if(endTime[j] < minEndTime) {
                minEndTime = endTime[j];
                idx = j;
            }
        }
        if(c[i].t >= minEndTime) { //如果到达时间晚于最早服务结束时间，直接分配窗口，更新服务结束时间
            endTime[idx] = c[i].t + c[i].p;
        } else {
            ans += minEndTime - c[i].t;
            //endTime[idx]=c[i].t+(minEndTime-c[i].t)+c[i].p;
            endTime[idx] += c[i].p;
        }
    }
    if(c.size() == 0)
        printf("0.0");
    else
        printf("%.1f", ans / 60.0 / c.size());
    return 0;
}
