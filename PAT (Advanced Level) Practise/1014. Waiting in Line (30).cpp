/*
* 学长做法
*/

/*
-------------------------------------------
我开始想不清思路的原因是，找不到顾客到最短队列的方法
本来觉得应该遍历队列的长度，找个最小的，再加入
错误地让顾客结束时间以队前所有顾客为基准
有点像是多个线程，是一个动态过程，这样想让代码控制非常复杂
-------------------------------------------
关键是要保持一个<每个窗口当前时间>，
每出一个顾客，更新一下窗口当前时间
这样就不必以前面的顾客为基准了，是以窗口时间为基准

并且<顾客的结束时间>是等到顾客出队列时再更新
变成了一个迭代更新过程
思路也清晰了不少
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <sstream>
using namespace std;

string intToString(int n, int t) {
    if (n - t >= 540) //结束服务的时间减服务时间，即开始服务的时间
        return "Sorry";
    stringstream ss; // 其实完全不用 sstream 的，杀鸡用牛刀
    string s;
    int h = n / 60 + 8;
    int m = n % 60;
    if (h < 10)
        ss << "0"; //补零
    ss << h << ":";
    if (m < 10)
        ss << "0";
    ss << m;
    ss >> s;
    return s;
}

const int MAX = 2147483647;

int main() {
    int N, M, K, Q; // 窗口数，每个窗口容量，顾客数，查询数
    cin >> N >> M >> K >> Q;
    vector<queue<pair<int, int>>> window(N); // N个窗口, pair 记录顾客时间和序号
    vector<int> time;                        // 顾客服务时间

    int x;
    for (int i = 0; i < K; i++) {
        // K个顾客的服务时间，这里从0开始编号
        cin >> x;
        time.push_back(x);
    }

    int id;
    for (id = 0; id < M * N && id < K; id++) {
        // 队列长度为M，窗口为N，最初的顾客入队
        window[id % N].push(make_pair(time[id], id));
    }

    vector<int> win_time(N, 0); //每个窗口的当前时间，初始化为0
    vector<int> end_time(K);    //K个顾客结束服务的时间

    int count = 0;
    int q_win;
    int q_time;
    while (count < K) {
        q_time = MAX;
        for (int i = 0; i < N; i++) {
            //检测哪个窗口最快(窗口当前时间+顾客服务时间)
            if (!window[i].empty()) {
                if (win_time[i] + window[i].front().first < q_time) {
                    q_time = win_time[i] + window[i].front().first;
                    q_win = i;
                }
            }
        }
        int tmp = window[q_win].front().first + win_time[q_win]; // 最快窗口结束的时间
        end_time[window[q_win].front().second] = tmp;            // 每次都最快窗口结束，再对顾客结束时间更新
        win_time[q_win] = tmp;                                   //更新最快窗口的当前时间

        window[q_win].pop(); // 最快窗口出队列

        if (id < K) //新顾客排队
            window[q_win].push(make_pair(time[id], id));
        id++;
        count++;
    }

    while (Q--) {
        cin >> x;
        cout << intToString(end_time[x - 1], time[x - 1]) << endl; // 查询编号是 1 开始的
    }
    return 0;
}
