#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct pNode {
    char id[20];
    int hh, mm, ss;
} temp, ans1, ans2; //ans1存放最早签到时间，ans2存放最晚签到时间

//node1的时间大于node2的时间则返回true
bool great(pNode node1, pNode node2) {
    if (node1.hh != node2.hh)
        return node1.hh > node2.hh;
    if (node1.mm != node2.mm)
        return node1.mm > node2.mm;
    return node1.ss > node2.ss;
}

int main() {
    int n;
    scanf("%d", &n);
    ans1.hh = 24, ans1.mm = 60, ans1.ss = 60; //把初始签到时间设为最大
    ans2.hh = 0, ans2.mm = 0, ans2.ss = 0; //把初始签离时间设为最小
    for (int i = 0; i < n; i++) {
        //先读入签到时间
        scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm, &temp.ss);
        if (great(temp, ans1) == false)
            ans1 = temp; //ans1取更小的签到时间
        //temp再作为签离时间读入
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if (great(temp, ans2) == true)
            ans2 = temp; //ans2取更大的签离时间
    }
    printf("%s %s\n", ans1.id, ans2.id);
    return 0;
}
