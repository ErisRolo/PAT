/* 1105. Spiral Matrix (25)

This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 104. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int a[1000][1000];
vector<int> vec;
int N; 
int m = -1 , n = -1;

bool cmp(int a, int b){
    return a > b;
}
int main(){
    scanf("%d", &N);
    n = int(sqrt(N));
    while(N % n != 0){
        n--;
    }
    m = N / n;
    // m（大） * n（小）
    int tmp;
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    if(vec.size() == 1){
        printf("%d\n", vec[0]);
        return 0;
    }
    sort(vec.begin(), vec.end(), cmp);
    int i = 0; 
    int j = 0;
    int k = 0;
    int U = 0, D = m - 1 , L = 0, R = n - 1;

    while(k!=vec.size()){
        // 最后 j = n-1
        while(j < R && k!=vec.size()){ // 往右
            a[i][j] = vec[k];
            j++;
            k++;
        }
        // 最后 i = m-1
        while(i < D && k!=vec.size()){
            a[i][j] = vec[k];
            i++;
            k++;
        }
        // 最后 j = 0
        while(j > L && k!=vec.size()){
            a[i][j] = vec[k];
            j--;
            k++;
        }
        // i = m-1, j = 0
        while(i > U && k!=vec.size()){
            a[i][j] = vec[k];
            i--;
            k++;
        }
        U++, D--, L++, R--;
        i++, j++; // 移到内层左上角
        if(k == vec.size()-1){
            a[i][j] = vec[k];
            k++;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j == 0) printf("%d", a[i][j]);
            else printf(" %d", a[i][j]);
            if(j == n-1) printf("\n");
        }
    }

    return 0;
}