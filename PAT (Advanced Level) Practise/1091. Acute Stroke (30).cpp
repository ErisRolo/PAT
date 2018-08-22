/**
* 分析：BFS，这题除了要掌握BFS的操作流程，感觉最关键的是认识单词读懂题意。。。
*       另外这题就是要你用BFS，用DFS会爆栈
*       注意三维01矩阵不能设为bool型，增量数组声明不要偷懒写个小写字母。。。
**/

#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int x, y, z;
};

int m, n, l, t;
int matrix[1287][129][61];
bool inq[1287][129][61] = {false};

int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
        return false;
    if(matrix[x][y][z] == 0 || inq[x][y][z] == true)
        return false;
    return true;
}

int BFS(int x, int y, int z) {
    int res = 0;
    queue<node> q;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    q.push(temp);
    inq[x][y][z] = true;
    while(!q.empty()) {
        node front = q.front();
        q.pop();
        res++;
        for(int i = 0; i < 6; i++) {
            int nx = front.x + X[i];
            int ny = front.y + Y[i];
            int nz = front.z + Z[i];
            if(judge(nx, ny, nz)) {
                temp.x = nx, temp.y = ny, temp.z = nz;
                q.push(temp);
                inq[nx][ny][nz] = true;
            }
        }
    }
    if(res >= t)
        return res;
    else
        return 0;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for(int z = 0; z < l; z++)
        for(int x = 0; x < m; x++)
            for(int y = 0; y < n; y++)
                scanf("%d", &matrix[x][y][z]);
    int ans = 0;
    for(int z = 0; z < l; z++) {
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(matrix[x][y][z] == 1 && inq[x][y][z] == false)
                    ans += BFS(x, y, z);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
