/**
* 分析：快乐模拟，客户进入队列时确定其服务结束时间为当前在该窗口排队的所有人的服务时间之和
**/

#include <bits/stdc++.h>
using namespace std;
const int maxk = 1010;
const int inf = 1000000000;

struct window {
    int endTime, popTime; //窗口当前队伍的最后服务时间 队首客户的服务结束时间
    queue<int> q; //队列
} w[20];

int ans[maxk], needTime[maxk]; //服务结束时间 服务需要时间

int main() {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++)
        scanf("%d", &needTime[i]);
    for(int i = 0; i < n; i++)
        w[i].popTime = w[i].endTime = 8 * 60; //初始化每个窗口时间为8:00
    int inIndex = 0; //当前第一个未入队的客户编号
    for(int i = 0; i < min(n * m, k); i++) { //循环条件是min(n*m,k) 循环入队
        w[inIndex % n].q.push(inIndex);
        w[inIndex % n].endTime += needTime[inIndex]; //窗口服务结束时间为排队客户服务时间总和
        if(inIndex < n)
            w[inIndex].popTime = needTime[inIndex]; //每个窗口的第一个客户 更新popTime
        ans[inIndex] = w[inIndex % n].endTime; //当前入队的客户的服务结束时间作为答案保存
        inIndex++;
    }
    for(; inIndex < k; inIndex++) { //处理剩余的客户
        int idx = -1, minPopTime = inf;
        for(int i = 0; i < n; i++) { //查找popTime最早的窗口
            if(w[i].popTime < minPopTime) {
                idx = i;
                minPopTime = w[i].popTime;
            }
        }
        //队首出队 客户入队 更新时间
        w[idx].q.pop();
        w[idx].q.push(inIndex);
        w[idx].endTime += needTime[inIndex];
        w[idx].popTime += needTime[w[idx].q.front()];
        ans[inIndex] = w[idx].endTime;
    }
    int query;
    for(int i = 0; i < q; i++) {
        scanf("%d", &query);
        if(ans[query - 1] - needTime[query - 1] >= 17 * 60) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", ans[query - 1] / 60, ans[query - 1] % 60);
        }
    }
    return 0;
}
