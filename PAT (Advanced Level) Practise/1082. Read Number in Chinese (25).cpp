/**
* 分析：按中文发音输出9位数以内的整数，有点难，而且意义不大，看懂晴神代码算了，不耽误时间
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}; //num[0]="ling",...
string wei[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"}; //Wei[0]="Shi",...

int main() {
    string str;
    cin >> str; //按字符串方式输入数字
    int len = str.size();
    int left = 0, right = len - 1; //left与right分别指向字符串首尾元素
    if(str[0] == '-') {
        cout << "Fu";
        left++; //负数把left右移1位
    }
    while(left + 4 <= right) {
        right -= 4; //将right每次左移4位，直到left与right在同一节
    }
    while(left < len) { //循环每次处理数字的一节(4位或小于4位)
        bool flag = false; //flag==false表示没有累积的0
        bool isPrint = false; //isPrint==false表示该节没有输出过其中的位
        while(left <= right) { //从左至右处理数字中某节的每一位
            if(left > 0 && str[left] == '0') { //如果当前位为0
                flag = true;
            } else { //如果当前位不为0
                if(flag == true) { //如果存在累积的0
                    printf(" ling");
                    flag = false;
                }
                if(left > 0) { //只要不是首位（包括负号），后面的每一位前都要输出空格
                    cout << " ";
                }
                cout << num[str[left] - '0']; //输出当前位数字
                isPrint = true; //该节至少有一位被输出
                if(left != right) { //某节中除了个位外，都需要输出十百千
                    cout << " " << wei[right - left - 1];
                }
            }
            left++; //left右移1位
        }
        if(isPrint == true && right != len - 1) { //只要不是个位，就输出万或亿
            cout << " " << wei[(len - 1 - right) / 4 + 2];
        }
        right += 4; //right右移4位，输出下一节
    }
    return 0;
}
