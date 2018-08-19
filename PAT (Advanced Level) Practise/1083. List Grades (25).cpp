/**
* 分析：8分钟AC25分到手
*       重要的事说三遍：多考这种题！多考这种题！多考这种题！
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct student {
    char name[11];
    char id[11];
    int grade;
} stu[maxn];

bool cmp(student a, student b) {
    if(a.grade != b.grade)
        return a.grade > b.grade;
}

int main() {
    int n, min, max, flag = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    sort(stu, stu + maxn, cmp);
    scanf("%d %d", &min, &max);
    for(int i = 0; i < n; i++) {
        if(stu[i].grade >= min && stu[i].grade <= max) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("NONE\n");
    return 0;
}
