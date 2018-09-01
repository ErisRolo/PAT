/**
* �������Һ�ˢ���˲�Ȼ�治֪������Ҫʲô�ⶼ��ģ����ȥ��
*       PATҲ��������ͼ�۵��⣬������������ͼ�����ʽ��⣬���ֵ����ɷ��Ӿͺ�
*       ����������ܶ��ٻ�·���������⣬��ͼ��˼�����жϵ��߼�����
*       �жϵ������ǣ���·���������ڶ�������+1����ʼ����յ���ͬ
*       ������ʼ����յ���ͬһ������������Σ����ඥ��س����ҽ�����һ��
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 210;

int n, m, k, t;
int g[maxn][maxn];
int flag = true;
int times[maxn];
vector<int> query;

bool isConnect(int a, int b) {
    if(g[a][b] == 1)
        return true;
    else
        return false;
}

int main() {
    int v1, v2;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    int v;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        flag = true;
        fill(times, times + maxn, 0);
        query.clear();
        scanf("%d", &t);
        for(int j = 0; j < t; j++) {
            scanf("%d", &v);
            times[v]++;
            query.push_back(v);
        }
        if(query.size() != n + 1) {
            flag = false;
        } else if(query[0] == query[query.size() - 1]) {
            for(int q = 1; q < query.size() - 1; q++) {
                if(times[query[q]] > 1) {
                    flag = false;
                    break;
                }
            }
            for(int q = 1; q < query.size(); q++) {
                if(isConnect(query[q - 1], query[q]) == false) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }
        if(flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}