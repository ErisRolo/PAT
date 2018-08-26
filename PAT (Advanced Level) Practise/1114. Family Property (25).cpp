/**
* 分析：好难啊，连基本操作都有所改变，主要是这道题结点之间关系太复杂
*       因为最后输出是家族中最小的ID，所以在合并时，ID小的作为父节点，不用考虑实际的父子母女关系，只需把属于一个家族的结点全部加到集合中
*       建两个结构体用来简化，一个结构体用来接收数据，一个用来存放答案
*       因为答案结构体是用ID作为数组下标，所以在处理数据获得结果时需要标记，方便后续遍历操作时的处理
*       同时也要标记每一个出现的ID，用来统计人数
*       有点复杂，还是不太会，再刷一刷想一想吧，这道题思路大概差不多就是这样
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
const int maxk = 6;
const int maxid = 10000;

int n, k, cnt = 0;
int father[maxid];
bool visit[maxid]; //标记出现的所有结点，方便统计人数

struct person {
    int id, fid, mid, estate, area;
    int cid[maxk];
} people[maxn];

struct result {
    int id, people;
    double estate, area;
    bool flag; //标记是否为根结点，一个根结点代表一个答案
} ans[maxid];

void init() {
    for(int i = 0; i < maxid; i++)
        father[i] = i;
}

int findFather(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa > fb)
        father[fa] = fb;
    else if(fa < fb)
        father[fb] = fa;
}

bool cmp(result a, result b) {
    if(a.area != b.area)
        return a.area > b.area;
    else if(a.id != b.id)
        return a.id < b.id;
}

int main() {
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &people[i].id, &people[i].fid, &people[i].mid, &k);
        visit[people[i].id] = true;
        if(people[i].fid != -1) {
            visit[people[i].fid] = true;
            Union(people[i].fid, people[i].id);
        }
        if(people[i].mid != -1) {
            visit[people[i].mid] = true;
            Union(people[i].mid, people[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &people[i].cid[j]);
            visit[people[i].cid[j]] = true;
            Union(people[i].id, people[i].cid[j]);
        }
        scanf("%d %d", &people[i].estate, &people[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = findFather(people[i].id);
        ans[id].id = id;
        ans[id].estate += people[i].estate;
        ans[id].area += people[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < maxid; i++) {
        if(visit[i])
            ans[findFather(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < maxid; i++) {
        if(ans[i].flag) {
            ans[i].estate = (double)(ans[i].estate * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + maxid, cmp);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].estate, ans[i].area);
    }
    return 0;
}
