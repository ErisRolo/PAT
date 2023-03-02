#include <bits/stdc++.h>
using namespace std;

int ord[55];
string a[55], b[55];

int main() {
    for (int i = 1; i <= 13; i++) {
        a[i] = "S" + to_string(i);
        a[i + 13] = "H" + to_string(i);
        a[i + 26] = "C" + to_string(i);
        a[i + 39] = "D" + to_string(i);
    }
    a[53] = "J1";
    a[54] = "J2";
    int k, t;
    scanf("%d", &k);
    for (int i = 1; i <= 54; i++)
        scanf("%d", &ord[i]);
    for (int i = 1; i <= 54; i++) {
        t = ord[i];
        for (int j = 0; j < k - 1; j++)
            t = ord[t];
        b[t] = a[i];
    }
    for (int i = 1; i <= 54; i++) {
        cout << b[i];
        if (i != 54)
            cout << " ";
    }
    system("pause");
    return 0;
}

// /**
// * 分析：因为题目直接给出了交换后的顺序，所以可以用两个数组start和end分别保存交换前后的顺序
// *       用一个order数组记录顺序，然后按重复次数赋值即可
// *       注意数组下标要使用1-54，方便和顺序一一对应，虽然0没有用但数组要开55个
// *       学习用字符数组输出数字前的字符的技巧，整除用来分组，取余用来输出数据
// *       注意输出前后数据要减1加1，使数据分到正确的分组，也避免整除时取余结果为0不能输出13
// *       实在理解不了就麻烦点分组判断输出，整除13的单独输出，但不要忘了输出符号
// *       结尾不能有空格，但不要用printf("%c", 8)，会判错，逻辑里加空格就好
// **/

// #include <cstdio>
// char c[5] = {'S', 'H', 'C', 'D', 'J'};

// int main() {
//     int K, start[55], end[55], order[55];
//     scanf("%d", &K); //repeat times
//     for(int i = 1; i <= 54; i++)
//         start[i] = i;
//     for(int i = 1; i <= 54; i++) {
//         scanf("%d", &order[i]);
//     }
//     for(int i = 0; i < K; i++) {
//         for(int j = 1; j <= 54; j++)
//             end[order[j]] = start[j];
//         for(int k = 1; k <= 54; k++)
//             start[k] = end[k]; //将排序后的结果作为下一次排序前的顺序
//     }
//     for(int i = 1; i <= 54; i++) {
//         end[i]--; //因为字符数组下标是0-4，减1使整除数据分到正确的分组
//         printf("%c%d", c[end[i] / 13], end[i] % 13 + 1); //前面减1后面输出加上
//         if(i != 54)
//             printf(" ");
//     }
//     //printf("%c", 8); //ASCII码为8的是backspace，用来删除末尾空格
//     return 0;
// }
