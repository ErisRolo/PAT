#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
struct stu {
    int id, GE, GI, Grade, rank;
    vector<int> vSchool;
};
struct sch {
    int nowNum, maxNum, lastRank;
    vector<int> stuID;
};
bool cmp1(stu a, stu b) {
    return a.Grade != b.Grade ? a.Grade > b.Grade : a.GE > b.GE;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    vector<stu> student(n);
    vector<sch> school(m);
    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        school[i] = {0, temp, -1};
    }
    for(int i = 0; i < n; i++) {
        student[i].vSchool.resize(k);
        student[i].id = i;
        scanf("%d%d", &student[i].GE, &student[i].GI);
        student[i].Grade = (student[i].GE + student[i].GI) / 2;
        for(int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            student[i].vSchool[j] = temp;
        }
    }
    sort(student.begin(), student.end(), cmp1);
    student[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(student[i].Grade == student[i - 1].Grade && student[i].GE == student[i - 1].GE)
            student[i].rank = student[i-1].rank;
        else
            student[i].rank = student[i-1].rank + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int schoolID = student[i].vSchool[j];
            int myRank = student[i].rank;
            int myID = student[i].id;
            if(school[schoolID].nowNum < school[schoolID].maxNum || school[schoolID].lastRank == myRank) {
                school[schoolID].nowNum++;
                school[schoolID].lastRank = myRank;
                school[schoolID].stuID.push_back(myID);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        sort(school[i].stuID.begin(), school[i].stuID.end());
        for(int j = 0; j < school[i].stuID.size(); j++) {
            if(j != 0) printf(" ");
            printf("%d", school[i].stuID[j]);
        }
        printf("\n");
    }
    return 0;
}
