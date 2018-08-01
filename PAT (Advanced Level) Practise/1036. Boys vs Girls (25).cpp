/**
* 分析：要求输出成绩最高的女生的信息和成绩最低的男生的信息，以及他们的成绩差值
*       首先将所有人按从女到男，成绩从高到低排序，则第一个就是成绩最高的女生，最后一个就是成绩最低的男生
*       循环统计性别数量来分成三种情况：全女、全男、有男有女，按不同的情况输出即可
*       此题注意输出格式，认真审题，要仔细！！！
**/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct student {
    char name[11];
    char gender; //F or M
    char id[11];
    int score;
};

//按从女到男，成绩从高到低的顺序排列
bool cmp(student stu1, student stu2) {
    if(stu1.gender != stu2.gender)
        return stu1.gender < stu2.gender;
    else if(stu1.score != stu2.score)
        return stu1.score > stu2.score;
}

int main() {
    int N, fName, fId, mName, mId;
    int gender = 0;
    scanf("%d", &N);
    student stu[N];
    for(int i = 0; i < N; i++) {
        scanf("%s %c %s %d", stu[i].name, &stu[i].gender, stu[i].id, &stu[i].score);
    }
    for(int i = 0; i < N; i++) {
        if(stu[i].gender == 'F')
            gender++;
    }
    if(gender == N)
        printf("%s %s\nAbsent\nNA", stu[0].name, stu[0].id); //全为女性
    else if(gender == 0)
        printf("Absent\n%s %s\nNA", stu[N - 1].name, stu[N - 1].id); //全为男性
    else {
        sort(stu, stu + N, cmp);
        printf("%s %s\n%s %s\n%d", stu[0].name, stu[0].id,
               stu[N - 1].name, stu[N - 1].id,
               stu[0].score - stu[N - 1].score);
    }
    return 0;
}
