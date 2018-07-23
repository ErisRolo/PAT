#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> cost; // 24段时间每分钟消费

// 要比较时间先后, 用string比较方便
struct record {
    string name;        //名字
    string time;        //时间
    string onOff;   //on 还是 off
    record(string a, string b, string c) : name(a), time(b), onOff(c) {}
    bool operator < (const record &kk)const {       //比较, 名字 > 时间 > onOff
        if (name < kk.name)
            return true;
        else if (name == kk.name) {
            if (time < kk.time)
                return true;
            else if (time == kk.time) {
                if (onOff == "on-line")
                    return true;
            }
        }
        return false;
    }
};

struct bill { //单条账单记录
    string name;
    string begin;
    string end;
    int time;
    double money;
    bill(string n, string b, string e, int t, double m) : name(n), begin(b), end(e), time(t), money(m) {}
};

// 计算金额
double countMoney(const string s1, const string s2, int &time) {
    // dd:hh:mm
    int d1 = (s1[0] - '0') * 10 + s1[1] - '0';
    int h1 = (s1[3] - '0') * 10 + s1[4] - '0';
    int m1 = (s1[6] - '0') * 10 + s1[7] - '0';
    int d2 = (s2[0] - '0') * 10 + s2[1] - '0';
    int h2 = (s2[3] - '0') * 10 + s2[4] - '0';
    int m2 = (s2[6] - '0') * 10 + s2[7] - '0';
    //天数差, hour差, minute差, 相隔的时间交给了time哦!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    time = ((d2 - d1) * 24 + h2 - h1) * 60 + m2 - m1;       //单位: 分
    double money = 0;
    double money1 = 0;
    double money2 = 0;
    // 采用 money2 - money1 方法, 非常地机智!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // 省去了一步步推算的麻烦哦!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (int i = 0; i < h1; i++)
        money1 += cost[i] * 60;
    money1 += cost[h1] * m1 + cost[24] * d1;

    for (int j = 0; j < h2; j++)
        money2 += cost[j] * 60;
    money2 += cost[h2] * m2 + cost[24] * d2;

    money = (money2 - money1) / 100;    // 美分变美元了, 耶!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return money;
}

int main() {
    int x;
    int sum = 0;
    for (int i = 0; i < 24; i++) {
        cin >> x;
        sum += x;
        cost.push_back(x);
    }
    cost.push_back(sum * 60); // cost[24]是一天的总费用
    int N;
    cin >> N;
    vector<record> people;
    string a, b, c;
    // 用到了substring哦,不需要把字符串割来割去的!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cin >> a >> b >> c;
    string billMonth = b.substr(0, 2); // 输入规定在一个月内，先提取月份
    people.push_back(record(a, b.substr(3, 8), c));
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        people.push_back(record(a, b.substr(3, 8), c));
    }
    sort(people.begin(), people.end());//按照姓名和时间排序
    vector<bill> bills;
    for (auto it = people.begin() + 1; it != people.end(); ++it) {
        if ((*it).onOff == "off-line" && (*(it - 1)).onOff == "on-line") { //配对, 这个很关键啊!!!!!!!!!!!!!!!!!!!!!!!!   题目都没读懂 ... 囧
            if ((*it).name == (*(it - 1)).name) {
                string s1 = (*(it - 1)).time;
                string s2 = (*it).time;
                int t;
                double m = countMoney(s1, s2, t);// t用引用返回
                bills.push_back(bill((*it).name, s1, s2, t, m));//压入一条记录
            }
        }
    } // 结构非常清楚, 各个struct的用途很清晰哦, GOOD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (bills.empty())
        return 0;
    string preName;
    double totalM = 0;
    for (auto it = bills.begin(); it != bills.end(); ++it) {
        if ((*it).name != preName) { //新人
            if (it != bills.begin())
                printf("Total amount: $%0.2f\n", totalM);//前一个人的总费用
            totalM = 0;
            cout << (*it).name << " " << billMonth << endl;//新人姓名和月份
        }
        preName = (*it).name;
        cout << (*it).begin << " " << (*it).end << " " << (*it).time << " ";
        printf("$%0.2f\n", (*it).money);
        totalM += (*it).money;
    }
    printf("Total amount: $%0.2f\n", totalM);//最后一个人的总费用
    return 0;
}
