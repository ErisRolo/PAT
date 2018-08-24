/* 1106. Lowest Price in Supply Chain (25) 

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    vector<int> child;
    int height;
}list[100001];

int level[100001] = {0};
int max_h = -1;
int n;
double p, r;

void levelOrder(int root){
    queue<int> q;
    list[root].height = 0;
    q.push(root);   
    while(!q.empty()){
        int now = q.front();
        q.pop();
        max_h = max(max_h, list[now].height);
        if(list[now].child.size() == 0){
            // 是叶节点
            level[list[now].height]++; // 叶节点对应高度的个数+1
        }
        for(int i = 0; i < list[now].child.size(); i++){
            int c = list[now].child[i];
            list[c].height = list[now].height+1;
            q.push(c);
        }
    }
}

double cal(double p, double r, int t){
    for(int i = 0; i < t; i++){
        p = p * (1 + r / 100);
    }
    return p;
}
int main(){
    scanf("%d %lf %lf", &n, &p, &r);
    int tmp_n, tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp_n);
        for(int j = 0; j < tmp_n; j++){
            scanf("%d", &tmp);
            list[i].child.push_back(tmp);
        }
    }
    int root = 0;
    levelOrder(root);
    int min_height = -1;
    for(int i = 0; i <= max_h; i++){
        if(level[i] != 0){
            min_height = i;
            break;
        }
    }
    // printf("min_height is %d", min_height);
    printf("%.4lf %d\n", cal(p, r, min_height), level[min_height]);
    return 0;
}