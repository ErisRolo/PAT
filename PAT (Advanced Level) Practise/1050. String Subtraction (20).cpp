/* 1050. String Subtraction (20)

Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts. */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string s;
string m;
int h[200] = {0};
int main(){
    // gets(s);
    getline(cin, s);
    getline(cin, m);
    for(int i = 0; i < s.size(); i++){
        h[s[i]] = 1;
    }
    for(int i =0; i < m.size(); i++){
        h[m[i]] = 0;
    }
    for(int i = 0; i < s.size(); i++){
        if(h[s[i]] == 1){
            printf("%c", s[i]);
        } 
    }
    return 0;
}
