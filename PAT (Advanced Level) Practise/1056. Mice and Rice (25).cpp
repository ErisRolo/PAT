/**
* 分析：用队列记录老鼠们的序号，先按顺序入队，代表参加这一轮比赛
*       每轮循环（比赛）需要先计算组数，然后枚举每一组选出质量最大的
*       此过程中将每只老鼠都出队，排名初始化为组数+1，然后进行比较
*       质量最大的晋级进入下一轮，即再次入队，其他的淘汰保持排名为当前组数+1不变
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

struct mouse {
    int weight;
    int rank;
} mice[maxn];

int main() {
    int np, ng, id;
    queue<int> q;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &mice[i].weight);
    }
    for(int i = 0; i < np; i++) {
        scanf("%d", &id);
        q.push(id);
    }
    int join = np, group; //当前轮参赛数量，当前轮组数
    while(!q.empty()) {
        if(q.size() == 1) { //只剩一只老鼠时，计其排名为1，循环结束
            mice[q.front()].rank = 1;
            break;
        }
        if(join % ng == 0)
            group = join / ng;
        else
            group = join / ng + 1;
        for(int i = 0; i < group; i++) {
            int max = q.front();
            for(int j = 0; j < ng; j++) {
                //处理最后一组老鼠数不足ng的情况，当前老鼠之前参加该轮的老鼠数量超过join时退出循环
                if(i * ng + j >= join)
                    break;
                int front = q.front();
                q.pop();
                mice[front].rank = group + 1; //所有参赛老鼠排名初始化为组数+1
                if(mice[front].weight > mice[max].weight)
                    max = front;
            }
            q.push(max);
        }
        join = group; //每组晋级一只，下一轮参加的即为当前轮的组数
    }
    for(int i = 0; i < np; i++) {
        printf("%d", mice[i].rank);
        if(i != np - 1)
            printf(" ");
    }
    return 0;
}
