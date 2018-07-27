/* 1027. Colors in Mars (20) 

People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input

Each input file contains one test case which occupies a line containing the three decimal color values.

Output

For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input
15 43 71
Sample Output
#123456 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<char> get_result(int n){
    vector<char> vec;
    if(n == 0) vec.push_back('0');
    while(n != 0){
        int x = n % 13;
        if(x <10 ) vec.push_back(x+'0');
        else vec.push_back(x - 10 +'A');
        n /= 13; 
    }
    return vec;
}

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    vector<char> vr = get_result(r);
    vector<char> vg = get_result(g);
    vector<char> vb = get_result(b);
    cout << "#";
    if(vr.size() < 2) cout << "0" << vr[0];
    else cout << vr[1] << vr[0];

    if(vg.size() < 2) cout << "0" << vg[0];
    else cout << vg[1] << vg[0];

    if(vb.size() < 2) cout << "0" << vb[0];
    else cout << vb[1] << vb[0];
    return 0;
}