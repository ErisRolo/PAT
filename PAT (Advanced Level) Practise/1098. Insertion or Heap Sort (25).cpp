/**
* 分析：要求模拟插入排序和堆排序过程，要能快速写出两个排序算法
*       因为要用堆排序，所以不方便再用vector，技巧在于插入排序可以用sort代替
*       本题与A1089类似，可以想想还有哪些排序算法可以组合一起考，准备一下押押题
*       同时以后此类题统一做法，都用数组，多写一个判断，然后两个临时数组直接去模拟排序过程
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n;
int a[maxn], b[maxn], t[maxn], heap[maxn];

bool isEqual(int a[], int b[]) {
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if(heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        t[i] = a[i];
        heap[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    //插入排序
    bool f1 = false;
    for(int i = 2; i <= n; i++) {
        sort(t + 1, t + i + 1); //左闭右开
        //每完成一趟排序进行一次比较
        if(f1) { //因为输出的是下一轮排序结果，所以把输出写在排序上面
            for(int k = 1; k <= n; k++) {
                printf("%d", t[k]);
                if(k != n)
                    printf(" ");
            }
            break;
        }
        if(isEqual(t, b)) {
            printf("Insertion Sort\n");
            f1 = true;
        }
    }
    //堆排序
    bool f2 = false;
    for(int i = n / 2; i >= 1; i--) { //建堆
        downAdjust(i, n);
    }
    for(int i = n; i > 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
        if(f2) {
            for(int k = 1; k <= n; k++) {
                printf("%d", heap[k]);
                if(k != n)
                    printf(" ");
            }
            break;
        }
        if(isEqual(heap, b)) {
            printf("Heap Sort\n");
            f2 = true;
        }
    }
    return 0;
}









//**
//* 分析：明确插入排序和堆排序的特点
//*       插排是前几个数字有序且后面未排序的数字完全相同，堆排是最后几个数字有序且未排序的第一个数字为最大值
//*       则可以找到从小到大第一个不再递增的数字，然后从这个是数字开始和原数列比对，如果完全相同，则为插排，否则为堆排序
//*       判断之后则可以在新数列的基础上再进行一步排序即可
//*       插排可用sort代替，比原数列多排一个即可
//*       堆排序则要记得方法，交换堆顶和未排序的堆的最后一个元素，然后向下调整即可
//**/
//
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 110;
//
//int n, t = 2;
//int a[maxn], b[maxn];
//
//void downAdjust(int low, int high) {
//    int i = 1, j = i * 2;
//    while(j <= high) {
//        if(j + 1 <= high && b[j] < b[j + 1])
//            j = j + 1;
//        if(b[i] < b[j]) {
//            swap(b[i], b[j]);
//            i = j;
//            j = i * 2;
//        } else {
//            break;
//        }
//    }
//}
//
//int main() {
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++)
//        scanf("%d", &a[i]);
//    for(int i = 1; i <= n; i++)
//        scanf("%d", &b[i]);
//    while(t <= n && b[t - 1] <= b[t])
//        t++;
//    int index = t;
//    while(t <= n && a[t] == b[t])
//        t++;
//    if(t == n + 1) {
//        printf("Insertion Sort\n");
//        sort(b + 1, b + index + 1);
//        printf("%d", b[1]);
//        for(int i = 2; i <= n; i++)
//            printf(" %d", b[i]);
//    } else {
//        printf("Heap Sort\n");
//        t = n;
//        while(t >= 2 && b[t] >= b[t - 1])
//            t--;
//        swap(b[1], b[t]);
//        downAdjust(1, t - 1);
//        printf("%d", b[1]);
//        for(int i = 2; i <= n; i++)
//            printf(" %d", b[i]);
//    }
//    return 0;
//}
