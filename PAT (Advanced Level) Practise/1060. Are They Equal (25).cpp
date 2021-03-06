/**
* 分析：数据上界是10^100，果断字符串，几分钟随便暴力写了写有17分
*       最大的坑点是数据可能有无效的前导0，还有小数点位置的处理，多写几组乱七八糟的数据能看出
*       坑点还是挺多的，注意是比较转换成科学计数法之后的大小，而不是比较大小再转换，不要理解错题意
*       要一开始就想一个比较完善的处理数据的算法，要分情况讨论，0.xxx和xxx.xxx，分别获取到底数有效部分和指数
*       最后还要对0特判
*       真的比去年强一些了，去年战略性放弃的题，今年自己看一下也能独立敲出来甚至还有所改进，9月PAT加油！
**/

#include <bits/stdc++.h>
using namespace std;

string deal(string s, int n, int &e) { //待处理数据 有效位数 指数
    string res;
    while(s[0] == '0' && s.size() > 0) {
        s.erase(s.begin());
    }
    if(s[0] == '.') {
        s.erase(s.begin());
        while(s[0] == '0' && s.size() > 0) {
            s.erase(s.begin());
            e--;
        }
    } else {
        if(s.find(".") != -1) {
            e = s.find("."); //返回的小数点的位置，既是迭代器下标，也是指数
            s.erase(s.begin() + e); //注意str.find()返回是位置下标，不是迭代器
        } else {
            e = s.size(); //如果没有小数点，指数即为整数长度
        }
    }
    if(s.size() > n) {
        res = s.substr(0, n);
    } else {
        res = s;
        for(int i = 0; i < n - s.size(); i++)
            res += "0";
    }
    if(s.size() == 0)
        e = 0; //对0特判，0的指数应为0
    return res;
}


int main() {
    int n;
    string a, b;
    int e1 = 0, e2 = 0;
    cin >> n >> a >> b;
    a = deal(a, n, e1);
    b = deal(b, n, e2);
    if(a == b && e1 == e2)
        cout << "YES 0." << a << "*10^" << e1;
    else
        cout << "NO 0." << a << "*10^" << e1 << " 0." << b << "*10^" << e2;
    return 0;
}
