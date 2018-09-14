/**
* 分析：查找题，用尼玛的排序
**/

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, score, mins = 101, maxs = -1;
    string name, id, maxn, maxid, minn, minid;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name >> id >> score;
        if(score > maxs) {
            maxs = score;
            maxn = name;
            maxid = id;
        }
        if(score < mins) {
            mins = score;
            minn = name;
            minid = id;
        }
    }
    cout << maxn << " " << maxid << endl << minn << " " << minid;
    return 0;
}



//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//const int maxn = 10000;
//
//struct student {
//    string name;
//    string id;
//    int score;
//} stu[maxn];
//
//bool cmp(student a, student b) {
//    if(a.score != b.score)
//        return a.score > b.score;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++)
//        cin >> stu[i].name >> stu[i].id >> stu[i].score;
//    sort(stu, stu + maxn, cmp);
//    cout << stu[0].name << " " << stu[0].id << endl;
//    cout << stu[n - 1].name << " " << stu[n - 1].id;
//    return 0;
//}
