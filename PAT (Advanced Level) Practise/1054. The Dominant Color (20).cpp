/**
* 分析：使用普通的数组会使内存超限，因此用map映射解决
*       熟悉map的各个函数即可
**/

#include <cstdio>
#include <map>
using namespace std;

int main() {
    int m, n, col, maxCnt = 0;
    map<int, int> count;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &col);
            if(count.find(col) != count.end())
                count[col]++;
            else
                count[col] = 1;
        }
    }
    for(map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
        if(it->second > maxCnt) {
            maxCnt = it->second;
            col = it->first;
        }
    }
    printf("%d\n", col);
    return 0;
}
