#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M, L, A[105], lie, lie_wolf, lie2, is_wolf[105];
vector<int> ans, relate[105];

void dfs(int index) {
    if (lie > L)
        return;
    if (ans.size() == M) {
        lie2 = lie_wolf = 0;
        for (int i = 1; i <= N; ++i) {
            if ((A[i] > 0 && is_wolf[abs(A[i])] == 1) || (A[i] < 0 && is_wolf[abs(A[i])] == 0)) {
                ++lie2;
                if (is_wolf[i])
                    ++lie_wolf;
            }
        }
        if (lie_wolf > 0 && lie_wolf < M && lie2 == L) {
            for (int i = 0; i < M; ++i) {
                if (i != M - 1)
                    printf("%d ", ans[i]);
                else
                    printf("%d\n", ans[i]);
            }
            exit(0);
        }
        return;
    }
    for (int k = index; k > 0; --k) {
        if (k + ans.size() < M)
            break;
        ans.push_back(k);
        is_wolf[k] = 1;
        for (auto x : relate[k])
            lie += x > 0 ? 1 : 0;
        dfs(k - 1);
        ans.pop_back();
        is_wolf[k] = 0;
        for (auto x : relate[k])
            lie += x > 0 ? -1 : 0;
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &L);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", A + i);
        int f = A[i] > 0 ? 1 : -1;
        relate[f * A[i]].push_back(f * i); //+代表认为是人，-狼
    }
    dfs(N);
    printf("No Solution\n");
}
