// 不需要用到队列

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cust {
    int arrive;    //到达时间
    int process;   //处理时间
    int start;     //开始处理时间
    int leave;     //结束处理时
    bool operator < (const cust &a)const {//重载<操作符，用于排序
        return arrive < a.arrive;
    }
};
int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<cust> CUST(N);
    int h, m, s, pro;
    // 把时间都化为秒哦, 这样能够方便计算呢!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (int i = 0; i < N; i++) { //化为秒
        scanf("%d:%d:%d %d", &h, &m, &s, &pro);
        CUST[i].arrive = (h * 60 + m) * 60 + s;
        CUST[i].process = pro * 60;
    }
    sort(CUST.begin(), CUST.end());//按照重载后的<操作符排序

    vector<int> window(K, 8 * 60 * 60); //窗口初始时间
    int quickTime;
    int quickWindow;
    for (int i = 0; i < N; i++) { //选择窗口的条件: 每次选择等待时间最短的窗口!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        quickTime = 2147483647;
        for (int j = 0; j < K; j++) {
            if (window[j] < quickTime) {
                quickTime = window[j];
                quickWindow = j;
            }
        }
        CUST[i].start = max(window[quickWindow], CUST[i].arrive);//需要等待和无需等待两种情况
        CUST[i].leave = CUST[i].start + CUST[i].process;
        window[quickWindow] = CUST[i].leave;
    }
    double sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (CUST[i].arrive <= 17 * 60 * 60) {//17点前来的
            sum += CUST[i].start - CUST[i].arrive;
            count++;
        }
    }
    if (sum > 0)
        printf("%.1f", sum / 60 / count);
    else
        printf("0.0");
    return 0;
}
