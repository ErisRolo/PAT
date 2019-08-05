/**
* 分析：还说是vector的题，还是用的map，这次6分钟AC。。。
**/

#include <bits/stdc++.h>
using namespace std;

map<int, vector<string> > mp;

int main() {
    int n, k;
    int t, course;
    char c[5];
    string s;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", c);
        s = c;
        scanf("%d", &t);
        for(int j = 0; j < t; j++) {
            scanf("%d", &course);
            mp[course].push_back(s);
        }
    }
    for(int i = 1; i <= k; i++) {
        auto it = mp.find(i);
        printf("%d %d\n", i, it->second.size());
        sort(it->second.begin(), it->second.end());
        for(int j = 0; j < it->second.size(); j++) {
            printf("%s\n", it->second[j].c_str());
        }
    }
    return 0;
}






//**
//* 分析：学会用二维数组表示m个长度为n的字符数组char[m][n]
//*       感觉这种二维数组就是整数到char数组的映射，要灵活掌握
//*       读清题意，不要被题目中name末尾的数字迷惑，那个数字没有任何作用
//**/
//
//#include <cstdio>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int maxn = 40010;
//const int maxM = 2510;
//
//char name[maxn][5]; //maxn个长度为5的char数组，name[i]表示第i个姓名，和学生名字最后一位的数字没关系，和输入顺序有关
//vector<int> courses[maxM]; //courses[i]表示选第i门课的学生编号
//
//bool cmp(int a, int b) {
//    return strcmp(name[a], name[b]) < 0; //按字典序排序
//}
//
//int main() {
//    int n, k;
//    int count, courseID;
//    scanf("%d%d", &n, &k);
//    for(int i = 0; i < n; i++) {
//        scanf("%s %d", &name[i], &count);
//        for(int j = 0; j < count; j++) {
//            scanf("%d", &courseID);
//            courses[courseID].push_back(i);
//        }
//    }
//    for(int i = 1; i <= k; i++) {
//        printf("%d %d\n", i, courses[i].size());
//        sort(courses[i].begin(), courses[i].end(), cmp);
//        for(int j = 0; j < courses[i].size(); j++)
//            printf("%s\n", name[courses[i][j]]);
//    }
//    return 0;
//}
