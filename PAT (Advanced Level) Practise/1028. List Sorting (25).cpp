/**
* 分析：排序简单题，不到十分钟一次AC直接25分
*       希望考试多出这种题，多多益善嘻嘻嘻
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct student {
    int id;
    char name[9];
    int grade;
} stu[maxn];

bool cmp1(student a, student b) {
    if(a.id != b.id)
        return a.id < b.id;
}

bool cmp2(student a, student b) {
    int s = strcmp(a.name, b.name);
    if(s != 0)
        return s < 0;
    else if(a.id != b.id)
        return a.id < b.id;
}

bool cmp3(student a, student b) {
    if(a.grade != b.grade)
        return a.grade < b.grade;
    else if(a.id != b.id)
        return a.id < b.id;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
    switch(c) {
    case 1:
        sort(stu, stu + n, cmp1);
        break;
    case 2:
        sort(stu, stu + n, cmp2);
        break;
    case 3:
        sort(stu, stu + n, cmp3);
        break;
    default:
        break;
    }
    for(int i = 0; i < n; i++)
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    return 0;
}
