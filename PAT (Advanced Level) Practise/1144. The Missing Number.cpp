/* 1131. Subway Map (30)

In the big cities, the subway systems always look so complex to the visitors. To give you some sense, the following figure shows the map of Beijing subway. Now you are supposed to help people with your computer skills! Given the starting position of your user, your task is to find the quickest way to his/her destination.


Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=100), the number of subway lines. Then N lines follow, with the i-th (i = 1, ..., N) line describes the i-th subway line in the format:

M S[1] S[2] ... S[M]

where M (<= 100) is the number of stops, and S[i]'s (i = 1, ... M) are the indices of the stations (the indices are 4-digit numbers from 0000 to 9999) along the line. It is guaranteed that the stations are given in the correct order -- that is, the train travels between S[i] and S[i+1] (i = 1, ..., M-1) without any stop.

Note: It is possible to have loops, but not self-loop (no train starts from S and stops at S without passing through another station). Each station interval belongs to a unique subway line. Although the lines may cross each other at some stations (so called"transfer stations"), no station can be the conjunction of more than 5 lines.

After the description of the subway, another positive integer K (<= 10) is given. Then K lines follow, each gives a query from your user: the two indices as the starting station and the destination, respectively.

The following figure shows the sample map.


Note: It is guaranteed that all the stations are reachable, and all the queries consist of legal station numbers.

Output Specification:

For each query, first print in a line the minimum number of stops. Then you are supposed to show the optimal path in a friendly format as the following:

Take Line#X1 from S1 to S2.
Take Line#X2 from S2 to S3.
......
where Xi's are the line numbers and Si's are the station indices. Note: Besides the starting and ending stations, only the transfer stations shall be printed.

If the quickest path is not unique, output the one with the minimum number of transfers, which is guaranteed to be unique.

Sample Input:
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
Sample Output:
2
Take Line#3 from 3011 to 3013.
10
Take Line#4 from 6666 to 1306.
Take Line#3 from 1306 to 2302.
Take Line#2 from 2302 to 2001.
6
Take Line#2 from 2004 to 1204.
Take Line#1 from 1204 to 1306.
Take Line#3 from 1306 to 3001. */

#include <cstdio>
#include <vector>
 
using namespace std;
 
// MAX 表示边界，path 是用作 dfs 的临时路径，finalPath 是更新之后的最终路径
// subway 是地铁图
// minCnt 是经过站的最少次数，minTranf 是换乘的最少次数，line 是图中两点的地铁线号，isVisited 是 dfs 用的标记
const int MAX = 10010;
vector<int> path, finalPath;
vector<vector<int> > subway(MAX);
int minCnt = MAX, minTranf = MAX, line[MAX][MAX], isVisited[MAX];
 
// 打印换乘路径
void printTrace() {
    printf("%d\n", minCnt);
    int sourceIndex = 0, preLine = line[finalPath[0]][finalPath[1]];
    for (int i = 1; i < finalPath.size(); i++) {
        int tempLine = line[finalPath[i - 1]][finalPath[i]];
        if (tempLine != preLine) {
            printf("Take Line#%d from %04d to %04d.\n", preLine, finalPath[sourceIndex], finalPath[i - 1]);
            sourceIndex = i - 1;
            preLine = tempLine;
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, finalPath[sourceIndex], finalPath[finalPath.size() - 1]);
}
 
// 获取换乘的次数
int getTransf(vector<int> a) {
    int cnt = 0, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        int tempLine = line[a[i - 1]][a[i]];
        if (preLine != tempLine) {
            cnt++;
            preLine = tempLine;
        }
    }
    return cnt;
}
 
// 深搜所有的路径，找到目的点的时候，记录将满足题目限制的路径
void dfs(int current, int dest, int cnt) {
    if (dest == current) {
        int tempMinTransf = getTransf(path);
        if (cnt < minCnt || (cnt == minCnt && tempMinTransf < minTranf)) {
            minCnt = cnt;
            finalPath = path;
            minTranf = tempMinTransf;
        }
        return;
    }
    for (int i = 0; i < subway[current].size(); i++) {
        int temp = subway[current][i];
        if (!isVisited[temp]) {    // 未访问
            isVisited[temp] = true;
            path.push_back(temp);
            dfs(temp, dest, cnt + 1); // dfs
            path.pop_back();          // 每次 dfs 后立马要弹出并设未访问 ！！！！！！！！！！！！！！！！！！！！！！！！！！
                                      // 为什么我之前都是循环之后再处理的？？？？？？？？？？？？？？？？？？？？？？？？？？？？
                                      // 因为他是加入再递归， 并且push是在dfs跟前，因此pop要在dfs之后
                                      // 你可以改写为自己熟悉的方式试试
            isVisited[temp] = false;
        }
    }
}
 
int main() {
    int n = 0, k = 0, m = 0, pre = 0, temp = 0, source = 0, dest = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            line[temp][pre] = line[pre][temp] = i; // 每两个站点间也要设置路线
            subway[pre].push_back(temp);           // 邻接表
            subway[temp].push_back(pre);
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &source, &dest);
        minCnt = MAX;                    // 最少站数
        isVisited[source] = true;        // 设置起点为访问过
        path.push_back(source);          // 把起点先放入
        dfs(source, dest, 0);            // dfs
        printTrace();                   
        path.clear();
        isVisited[source] = false;       
        finalPath.clear();
    }
    return 0;
}