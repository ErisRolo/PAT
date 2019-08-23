/**
* 分析：PAT自测模拟第一道一遍直接AC的题
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

struct person {
    string name;
    int height;
} p[maxn];

bool cmp(person a, person b) {
    if(a.height != b.height)
        return a.height > b.height;
    else
        return a.name < b.name;

}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        getchar();
        cin >> p[i].name >> p[i].height;
    }
    sort(p, p + n, cmp);
    int id = 0;
    for(int i = 0; i < k; i++) {
        string order[maxn];
        int lid = id + 1, rid = id + 2;
        int num;
        if(i == 0)
            num = n - n / k * (k - 1);
        else
            num = n / k;
        int mid = num / 2 + 1;
        order[mid] = p[id].name;
        for(int j = mid - 1; j >= 1; j--) {
            order[j] = p[lid].name;
            lid += 2;
        }
        for(int j = mid + 1; j <= num; j++) {
            order[j] = p[rid].name;
            rid += 2;
        }
        for(int j = 1; j <= num; j++) {
            cout << order[j];
            if(j != num)
                cout << " ";
            else
                cout << endl;
        }
        id += num; //下一排中间的id等于上一排的人数
    }
    return 0;
}
