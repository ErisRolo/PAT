/* 1103. Integer Factorization (30)

The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, P;
// int max_di = 1;
// int res[20] = {0};

vector<int> path;
vector<int> result;

int max_n = -1;

vector<int> v;
void dfs(int sum, int cnt, int now){
    if(cnt > K || sum < 0) return;
    if(sum == 0 && cnt == K){
        int tmp_sum = 0;
        for(int i = 0; i < path.size(); i++){
            tmp_sum += path[i];
        }
        if(tmp_sum > max_n){
            result = path; 
            max_n = tmp_sum;
        }
        return;
    }
    if(now >= 1){
        path.push_back(now);
        dfs(sum-v[now], cnt+1, now);
        path.pop_back();
        dfs(sum, cnt, now-1);
    }
}

int main(){
    scanf("%d %d %d", &N, &K, &P);
    // while(pow(max_di, P) < N){
    //     max_di++;
    // }
    // for(int j = 1; j <= 20; j++){
    //     res[j] = int(pow(j, P));
    //     if(res[j] > N){
    //         max_di = j-1;
    //         break;
    //     }
    // }

    int tmp = 0, index = 1;
    while(tmp <= N){
        v.push_back(tmp);
        tmp = pow(index,P);
        index++; 
    }

    dfs(N, 0, v.size()-1);

    if(result.empty()){
        printf("Impossible\n");
        return 0;
    }
    printf("%d = ", N);
    for(int i = 0; i < result.size(); i++){
        if(i != 0) printf(" + ");
        printf("%d^%d", result[i], P);
    }
    return 0;
}