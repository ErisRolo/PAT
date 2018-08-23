/* 1102. Invert a Binary Tree (25)


The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;

struct Node{
    int left;
    int right;
}list[20];

bool vis[20] = {false}; 

void level(int root){
    queue<int> q;
    q.push(root);
    int n = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(n == 0) printf("%d", now);
        else printf(" %d", now);
        n++;
        if(list[now].right!=-1) q.push(list[now].right);
        if(list[now].left!=-1) q.push(list[now].left);
    }
    printf("\n");
}

bool flag = true;
void in(int root){
    if(root == -1) return;
    in(list[root].right);
    if(flag){
        printf("%d", root);
        flag = false;
    } 
    else printf(" %d", root);
    in(list[root].left);
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char a, b;
        cin >> a >> b;
        if(a == '-') list[i].left = -1;
        else{
            list[i].left = a - '0';
            vis[list[i].left] = true;
        } 
        if(b == '-') list[i].right = -1;
        else{
            list[i].right = b - '0';
            vis[list[i].right] = true;
        } 
    }
    int root = -1;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            root = i;
            break;
        }
    }
    level(root);
    in(root);
    printf("\n");
    return 0;
}