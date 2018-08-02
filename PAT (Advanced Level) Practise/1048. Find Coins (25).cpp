/**
* 分析：一般做法会超时
*       晴神宝典要求用散列法、二分查找及two pointers方法分别实现一次。。。
*       散列法注意数组大小并不需要开到10^5，因为数据不会超过10^3
*       还要注意i == m-i的情况
*       不知道为啥hash数组必须写在main函数外面，不然会有一个错误，少得2分。。。
**/

#include <cstdio>
const int maxM = 1001;

int hash[maxM];

int main() {
    int N, M, temp, flag;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp );
        hash[temp]++;
    }
    for(int i = 1; i < M; i++) {
        if(hash[i] && hash[M - i] ) {
            if(i == M - i && hash[i] > 1) {
                printf("%d %d\n", i, M - i);
                break;
            } else if(i != M - i) {
                printf("%d %d\n", i, M - i);
                break;
            }
        }
        flag = i;
    }
    if(flag == M - 1)
        printf("No Solution\n");
    return 0;
}

/*
    一般做法会超时

    int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        int V[N + 1], V1, V2, flag;
        for(int i = 0; i < N; i++) {
            scanf("%d", &V[i]);
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(V[i] + V[j] == M) {
                    V1 = V[i];
                    V2 = V[j];
                    break;
                    break;
                }
            }
        }
        if(flag == N - 1)
            printf("No Solution");
        else
            printf("%d %d", V1, V2);
        return 0;
    }
*/
