/**
* 分析：因为数据量小，只有169，所以采用打表，对数据进行预处理
*       这题的难点在于预处理数据时对输出格式的控制，按我之前的写法只能得16分，有两个得分点不知道错在哪
*       改成晴神的写法后通过，注意学习晴神预处理数据的方式
*       记住cctype下isdigit的使用，可以用来判断是否为数字
*       感觉这题主要考字符串处理和打表而不是map。。。
**/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

string unitdigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}; //个位数字
string tendigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; //十位数字

string numtostr[170]; //整型到字符串的映射，即数字转换为火星文
map<string, int> strtonum; //字符串到整型的映射，即火星文转换为数字

//晴神的写法
void init() {
    for(int i = 0; i < 13; i++) {
        //个位为[0,12]，十位为0
        numtostr[i] = unitdigit[i];
        strtonum[unitdigit[i]] = i;
        //十位为[0,12]，个位为0
        numtostr[i * 13] = tendigit[i];
        strtonum[tendigit[i]] = i * 13;
    }
    //十位
    for(int i = 1; i < 13; i++) {
        //个位
        for(int j = 1; j < 13; j++) {
            string str = tendigit[i] + " " + unitdigit[j]; //火星文
            numtostr[i * 13 + j] = str; //数字->火星文
            strtonum[str] = i * 13 + j; //火星文->数字
        }
    }
}

////打表，预处理数据
//void init() {
//    //处理整型到字符串的转换
//    for(int i = 0; i < 170; i++) {
//        if(i >= 0 && i <= 12) {
//            numtostr[i] = unitdigit[i];
//        } else if(i % 13 != 0) {
//            numtostr[i] = tendigit[i / 13];
//            numtostr[i] += " " + unitdigit[i % 13];
//        } else {
//            numtostr[i] = tendigit[i / 13];
//        }
//    }
//    //处理字符串到整型的转换
//    for(int i = 0; i < 170; i++) {
//        if(i >= 0 && i <= 12) {
//            strtonum[unitdigit[i]] = i;
//        } else if(i % 13 != 0) {
//            strtonum[tendigit[i / 13] + " " + unitdigit[i % 13]] = i;
//        } else {
//            strtonum[tendigit[i / 13]] = i;
//        }
//    }
//}

int main() {
    init();
    int n;
    string str;
    scanf("%d\n", &n);
    while(n--) {
        getline(cin, str);
        if(isdigit(str[0])) {
            int num = 0;
            for(int i = 0; i < str.size(); i++) {
                num = num * 10 + str[i] - '0';
            }
            cout << numtostr[num] << endl;
        } else {
            cout << strtonum[str] << endl;
        }
    }
    return 0;
}
