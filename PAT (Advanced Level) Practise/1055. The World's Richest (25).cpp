/**
* 分析：排序简单题，十五分钟一次AC直接25分
*       跪求考试全是这种难度的。。。
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct rich {
    char name[9];
    int age;
    int worth;
} r[maxn];

bool cmp(rich a, rich b) {
    int s = strcmp(a.name, b.name);
    if(a.worth != b.worth)
        return a.worth > b.worth;
    else if(a.age != b.age)
        return a.age < b.age;
    else if(s != 0)
        return s < 0;
}

int main() {
    int n, k;
    int num, min, max;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", r[i].name, &r[i].age, &r[i].worth);
    sort(r, r + n, cmp);
    for(int i = 1; i <= k; i++) {
        scanf("%d %d %d", &num, &min, &max);
        printf("Case #%d:\n", i);
        int temp = num;
        for(int j = 0; j < n && temp != 0; j++) {
            if(r[j].age >= min && r[j].age <= max) {
                printf("%s %d %d\n", r[j].name, r[j].age, r[j].worth);
                temp--;
            }
        }
        if(temp == num)
            printf("None\n");
    }
    return 0;
}
