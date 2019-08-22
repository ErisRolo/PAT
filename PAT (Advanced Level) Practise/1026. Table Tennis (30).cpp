/**
* 分析：PAT最难模拟题，附晴神标程，战略性放弃，做关键路径去了
**/

#include <bits/stdc++.h>
using namespace std;
const int K = 110; //窗口数
const int INF = 1000000000; //无穷大

struct Player {
    int arriveTime, startTime, trainTime; //到达时间、训练开始时间及训练时长
    bool isVIP; //是否为VIP球员
} newPlayer;

vector<Player> player;

struct Table {
    int endTime, numServe; //当前占用该球桌的球员的结束时间及已训练的人数
    bool isVIP; //是否为VIP球桌
} table[K];

int convertTime(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

bool cmpArriveTime(Player a, Player b) {
    return a.arriveTime < b.arriveTime;
}

bool cmpStartTime(Player a, Player b) {
    return a.startTime < b.startTime;
}

//编号VIPi从当前VIP球员移到下一个VIP球员
int nextVIPPlayer(int VIPi) {
    VIPi++; //先将VIPi加1
    while(VIPi < player.size() && player[VIPi].isVIP == 0) { //只要当前球员不是VIP，就让VIPi后移一位
        VIPi++;
    }
    return VIPi; //返回下一个VIP球员的ID
}

//将编号为tID的球桌分配给编号为pID的球员
void allotTable(int pID, int tID) {
    if(player[pID].arriveTime <= table[tID].endTime) { //更新球员的开始时间
        player[pID].startTime = table[tID].endTime;
    } else {
        player[pID].startTime = player[pID].arriveTime;
    }
    //该球桌的训练结束时间更新为新球员的结束时间，并让服务人员加1
    table[tID].endTime = player[pID].startTime + player[pID].trainTime;
    table[tID].numServe++;
}

int main() {
    int n, k, m, VIPtable;
    scanf("%d", &n);
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(21, 0, 0);
    for(int i = 0; i < n; i++) {
        int h, m, s, trainTime, isVIP;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVIP);
        newPlayer.arriveTime = convertTime(h, m, s);
        newPlayer.startTime = edTime; //开始时间初始化为21点
        if(newPlayer.arriveTime >= edTime)
            continue;
        newPlayer.trainTime = trainTime <= 120 ? trainTime * 60 : 7200;
        newPlayer.isVIP = isVIP;
        player.push_back(newPlayer);
    }
    scanf("%d%d", &k, &m);
    for(int i = 1; i <= k; i++) {
        table[i].endTime = stTime; //当前训练时间为8点
        table[i].numServe = table[i].isVIP = 0; //初始化numServe与isVip
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &VIPtable);
        table[VIPtable].isVIP = 1;
    }
    sort(player.begin(), player.end(), cmpArriveTime);
    int i = 0, VIPi = -1; //i用来扫描所有球员，VIPi总是指向当前最前的VIP球员
    VIPi = nextVIPPlayer(VIPi); //找到第一个VIP球员的编号
    while(i < player.size()) { //当前队列最前面的球员为i
        int idx = -1, minEndTime = INF; //寻找最早能空闲的球桌
        for(int j = 1; j <= k; j++) {
            if(table[j].endTime < minEndTime) {
                minEndTime = table[j].endTime;
                idx = j;
            }
        }
        if(table[idx].endTime >= edTime) //已经关门，直接break
            break;
        if(player[i].isVIP == 1 && i < VIPi) { //如果i号是VIP球员但是VIPi>i说明i号球员已经在训练
            i++;
            continue;
        }
        //按球桌是否为VIP、球员是否为VIP进行4种情况讨论
        if(table[idx].isVIP == 1) {
            if(player[i].isVIP == 1) { //球桌是VIP，球员是VIP
                allotTable(i, idx);
                if(VIPi == i)
                    VIPi = nextVIPPlayer(VIPi);
                i++;
            } else { //球桌是VIP，球员不是VIP
                if(VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime) {
                    allotTable(VIPi, idx);
                    VIPi = nextVIPPlayer(VIPi);
                } else {
                    allotTable(i, idx);
                    i++;
                }
            }
        } else {
            if(player[i].isVIP == 0) { //球桌不是VIP，球员不是VIP
                allotTable(i, idx);
                i++;
            } else { //球桌不是VIP，球员是VIP
                int VIPidx = -1, minVIPEndTime = INF;
                for(int j = 1; j <= k; j++) {
                    if(table[j].isVIP == 1 && table[j].endTime < minVIPEndTime) {
                        minVIPEndTime = table[j].endTime;
                        VIPidx = j;
                    }
                }
                if(VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime) {
                    allotTable(i, VIPidx);
                    if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
                    i++;
                } else {
                    allotTable(i, idx);
                    if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmpStartTime);
    for(i = 0; i < player.size() && player[i].startTime < edTime; i++) {
        int t1 = player[i].arriveTime;
        int t2 = player[i].startTime;
        printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
        printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
        printf("%.0f\n", round((t2 - t1) / 60.0));
    }
    for(i = 1; i <= k; i++) {
        printf("%d", table[i].numServe);
        if(i < k) printf(" ");
    }
    return 0;
}
