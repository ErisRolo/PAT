/**
* 分析：给定两个字符串，在第一个字符串中删掉第二个字符串中出现过的所有字符，想到用散列
*       注意此题不能用scanf，因为scanf读取字符串是用空格作为截断标志，无法一次读取一整行带有空格的字符串
*       又因为gets被禁用，所以使用getline替代，同时用string替代char数组，用string.size()替代strlen(char[])
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    bool hash[128] = {false};
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.size(); i++) {
        hash[s2[i]] = true;
    }
    for(int i = 0; i < s1.size(); i++) {
        if(hash[s1[i]] == false)
            printf("%c", s1[i]);
    }
    return 0;
}
