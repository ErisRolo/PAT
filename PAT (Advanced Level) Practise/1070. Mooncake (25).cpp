#include <bits/stdc++.h>
using namespace std;

struct node {
    float invent, price, val;
};

int cmp(node a, node b) {
    return a.val > b.val;
}

int main() {
    int N, D;
    scanf("%d%d", &N, &D);
    vector<node> arr(N);
    for(int i = 0; i < N; i++) {
        scanf("%f", &arr[i].invent);
    }
    for(int i = 0; i < N; i++) {
        scanf("%f", &arr[i].price);
        arr[i].val =  arr[i].price / arr[i].invent;
    }
    sort(arr.begin(), arr.end(), cmp);
    float res = 0;
    for(int i = 0; i < N; i++) { //不能用while(D>=0)判断，因为可能所有月饼总和小于D
        if(arr[i].invent <= D) {
            res += arr[i].price;
        } else {
            res = res + arr[i].val * D;
            break;
        }
        D -= arr[i].invent;
    }
    printf("%.2f", res);
    return 0;

}
