/* 1112. Stucked Keyboard (20)

On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string "thiiis iiisss a teeeeeest" we know that the keys "i" and "e" might be stucked, but "s" is not even though it appears repeatedly sometimes. The original string could be "this isss a teest".

Input Specification:

Each input file contains one test case. For each case, the 1st line gives a positive integer k ( 1<k<=100 ) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and "_". It is guaranteed that the string is non-empty.

Output Specification:

For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.
Sample Input:

3
caseee1__thiiis_iiisss_a_teeeeeest

Sample Output:

ei
case1__this_isss_a_teest
 */

#include <iostream>
#include <string>

using namespace std;

int K;
string s;
bool notStucked[200] = {false};
bool isStucked[200] = {false}; // 每个字符是否stuck
bool vis[200] = {false};
//int cntStucked[200] = {0};  // 每个字符重复 K 次但次数
int main(){
	cin >> K;
	cin >> s;
	char last = s[0];
	int repeat_cnt = 1;
	for(int i = 1; i < s.size(); i++){
		if(last == s[i]){
			repeat_cnt++;
		}
		else{
			if(repeat_cnt % K == 0 && !notStucked[s[i-1]]){
				isStucked[s[i-1]] = true; // 暂时设为 true

			}
			else{
				isStucked[s[i-1]] = false; // 后面如果又出现，但不为K整除，则不是
				notStucked[s[i-1]] = true; // 确定不是 stuck 字符
			}
			repeat_cnt = 1;
		}

		last = s[i];
	}
	if((repeat_cnt % K == 0 && !notStucked[s[s.size()-1]])){
		isStucked[s[s.size()-1]] = true;

	}

	for(int i = 0; i < s.size();i++){
		if(isStucked[s[i]] && !vis[s[i]]){
			cout << s[i];
			vis[s[i]] = true;
		}
	}
	cout << endl;
	for(int i = 0; i < s.size();i++){
		if(isStucked[s[i]]){
			cout << s[i];
			i = i + K -1;
		}
		else cout << s[i];
	}
	cout << endl;

	return 0;
}