/**
* 分析：明确插入排序和堆排序的特点
*       插排是前几个数字有序且后面未排序的数字完全相同，堆排是最后几个数字有序且未排序的第一个数字为最大值
*       则可以找到从小到大第一个不再递增的数字，然后从这个是数字开始和原数列比对，如果完全相同，则为插排，否则为堆排序
*       判断之后则可以在新数列的基础上再进行一步排序即可
*       插排可用sort代替，比原数列多排一个即可
*       堆排序则要记得方法，交换堆顶和未排序的堆的最后一个元素，然后向下调整即可
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

int n, t = 2;
int a[maxn], b[maxn];

void downAdjust(int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && b[j] < b[j + 1])
            j = j + 1;
        if(b[i] < b[j]) {
            swap(b[i], b[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    while(t <= n && b[t - 1] <= b[t])
        t++;
    int index = t;
    while(t <= n && a[t] == b[t])
        t++;
    if(t == n + 1) {
        printf("Insertion Sort\n");
        sort(b + 1, b + index + 1);
        printf("%d", b[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", b[i]);
    } else {
        printf("Heap Sort\n");
        t = n;
        while(t >= 2 && b[t] >= b[t - 1])
            t--;
        swap(b[1], b[t]);
        downAdjust(1, t - 1);
        printf("%d", b[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", b[i]);
    }
    return 0;
}
