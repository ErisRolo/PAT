#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct stu {
    int ID;
    int C;
    int M;
    int E;
    int A;
    int bestRank;
    char bestItem;
    stu(int id, int c, int m, int e) : ID(id), C(c), M(m), E(e) {
        A = (c + m + e) / 3;
    }
};

bool compA(stu s1, stu s2) {
    return s1.A > s2.A;
}

bool compC(stu s1, stu s2) {
    return s1.C > s2.C;
}

bool compM(stu s1, stu s2) {
    return s1.M > s2.M;
}

bool compE(stu s1, stu s2) {
    return s1.E > s2.E;
}

int main() {
    int N, M;
    cin >> N >> M;
    if (N == 0) {
        int x;
        while (M--) {
            cin >> x;
            cout << "N/A" << endl;
        }
        return 0;
    }
    int id, c, m, e;
    vector<stu> students;
    for (int i = 0; i < N; i++) {
        cin >> id >> c >> m >> e;
        students.push_back(stu(id, c, m, e));
    }
    sort(students.begin(), students.end(), compA);
    int rankA = 1;
    students[0].bestRank = 1;
    students[0].bestItem = 'A';
    for (int i = 1; i < N; i++) {
        if (students[i].A < students[i - 1].A)
            rankA = i + 1;//没有并列，若并列，rankA不更新
        students[i].bestRank = rankA;
        students[i].bestItem = 'A';
    }
    sort(students.begin(), students.end(), compC);
    int rankC = 1;
    if (students[0].bestRank != 1) {
        students[0].bestRank = 1;
        students[0].bestItem = 'C';
    }
    for (int i = 1; i < N; i++) {
        if (students[i].C < students[i - 1].C)
            rankC = i + 1;
        if (rankC < students[i].bestRank) {
            students[i].bestRank = rankC;
            students[i].bestItem = 'C';
        }
    }
    sort(students.begin(), students.end(), compM);
    int rankM = 1;
    if (students[0].bestRank != 1) {
        students[0].bestRank = 1;
        students[0].bestItem = 'M';
    }
    for (int i = 1; i < N; i++) {
        if (students[i].M < students[i - 1].M)
            rankM = i + 1;
        if (rankM < students[i].bestRank) {
            students[i].bestRank = rankM;
            students[i].bestItem = 'M';
        }
    }
    sort(students.begin(), students.end(), compE);
    int rankE = 1;
    if (students[0].bestRank != 1) {
        students[0].bestRank = 1;
        students[0].bestItem = 'E';
    }
    for (int i = 1; i < N; i++) {
        if (students[i].E < students[i - 1].E)
            rankE = i + 1;
        if (rankE < students[i].bestRank) {
            students[i].bestRank = rankE;
            students[i].bestItem = 'E';
        }
    }
    map<int, int > map;//用于查询
    for (int i = 0; i < N; i++) {
        map[students[i].ID] = i; // 保存 ID 对应列表的 index
    }
    int x;
    while (M--) {
        cin >> x;
        if (map.find(x) == map.end())
            cout << "N/A" << endl;
        else
            cout << students[map[x]].bestRank << " " << students[map[x]].bestItem << endl;
    }
    return 0;
}
