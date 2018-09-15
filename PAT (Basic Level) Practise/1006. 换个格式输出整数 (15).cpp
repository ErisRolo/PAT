/**
* 分析：快快快
**/

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m, d, cnt = 0;
    vector<int> v1, v2;
    scanf("%d%d", &n, &m);
    if(m > n)
        m = m % n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &d);
        cnt++;
        if(cnt <= n - m)
            v1.push_back(d);
        else
            v2.push_back(d);
    }
    for(int i = 0; i < v2.size(); i++) {
        if(m != n)
            printf("%d ", v2[i]);
        else {
            printf("%d", v2[i]);
            if(i != v2.size() - 1)
                printf(" ");
        }
    }
    for(int i = 0; i < v1.size(); i++) {
        printf("%d", v1[i]);
        if(i != v1.size() - 1)
            printf(" ");
    }
    return 0;
}
