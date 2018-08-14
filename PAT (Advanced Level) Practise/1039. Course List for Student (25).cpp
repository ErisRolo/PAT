/**
* 分析：37分钟，6个测试点通过了4个却只有8分，一个格式错误一个运行超时
*       感觉自己脑子笨，，逻辑有问题。。。
*       看了题解，发现逻辑差不多，正常思路是：读取每门课的所有选课学生，然后将课程编号加入选择这门课的学生中去
*       只是这道题数据量大，使用cin、cout和map、string都会导致超时
*       要用hash把学生姓名转换为int型存储到vector里
*       此题年代久远，参考价值不大。。。
*       不过要通过这道题学会vector的操作，尤其是二维数组
**/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010; //总人数
const int M = 26 * 26 * 26 * 10 + 1; //由姓名散列成的数字上界
vector<int> selectCourse[M]; //每个学生选择的课程编号

int getID(char name[]) {
    int id = 0;
    for(int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++) {
        int course, x;
        scanf("%d%d", &course, &x);
        for(int j = 0; j < x; j++) {
            scanf("%s", name);
            int id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end()); //默认从小到大排序
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0; j < selectCourse[id].size(); j++)
            printf(" %d", selectCourse[id][j]);
        printf("\n"); //最后一行可以输出换行符
    }
    return 0;
}

/*

struct Class {
    int id;
    int count;
    vector<string> stu;
};

struct Student {
    string name;
    int count;
    vector<int> cls;
};

int main() {
    int n, k, temp;
    int id, count;
    string name;
    scanf("%d %d", &n, &k);
    temp = k;
    Class cls[k];
    Student stu[n];
    while(temp--) {
        scanf("%d %d", &id, &count);
        cls[id - 1].id = id;
        cls[id - 1].count = count;
        while(count--) {
            cin >> name;
            cls[id - 1].stu.push_back(name);
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> name;
        stu[i].name = name;
        stu[i].count = 0;
        for(int j = 0; j < k; j++) {
            for(vector<string>::iterator it = cls[j].stu.begin(); it != cls[j].stu.end(); it++) {
                if(*it == name) {
                    stu[i].cls.push_back(cls[j].id);
                    stu[i].count++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].count << " ";
        for(vector<int>::iterator it = stu[i].cls.begin(); it != stu[i].cls.end(); it++) {
            if(it != stu[i].cls.end() - 1)
                cout << *it << " ";
            else
                cout << *it;
        }
        if(i != n - 1)
            cout << endl;
    }
    return 0;
}

*/
