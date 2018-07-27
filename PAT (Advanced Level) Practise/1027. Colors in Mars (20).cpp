/**
* 分析：要求将三个0-168的十进制数转换为13进制数，同时前面加#，不足两位要补0
*       直接套进制转换的模板，除基取余即可，最后注意控制输出格式就好，输出格式的不同情形要考虑全
*       此题晴神宝典还有更好的方法，因为范围为[0,168]，所以整数一定可以表示为x = a * 13^1 + b * 13^0
*       对上面的整式同时整除13，可得x / 13 = a；两边同时对13取模，可得x % 13 = b
*       最后用char型数组表示数字与字符的对应关系（一定要学会这种用数组输出对应关系的技巧！！！）
*       输出a、b即可，如下
**/

#include <cstdio>

//建立0-13与'0'-'9'、'A'、'B'、'C'的关系
char radix[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main() {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#");
    printf("%c%c", radix[r / 13], radix[r % 13]);
    printf("%c%c", radix[g / 13], radix[g % 13]);
    printf("%c%c", radix[b / 13], radix[b % 13]);
    return 0;
}

/*
    一般做法，很麻烦。。。

    const int maxn = 2;

    //输出只有一位时补0并转换
    void printOne(int d) {
        if(d < 10)
            printf("0%d", d);
        else if(d == 10)
            printf("0A");
        else if(d == 11)
            printf("0B");
        else if(d == 12)
            printf("0C");
    }

    //输出两位时的转换
    void printTwo(int d) {
        if(d < 10)
            printf("%d", d);
        else if(d == 10)
            printf("A");
        else if(d == 11)
            printf("B");
        else if(d == 12)
            printf("C");
    }

    //10进制数转13进制数并输出
    void toThree (int d) {
        int D[maxn], num = 0;
        do {
            D[num++] = d  %  13; //除基取余
            d = d / 13;
        } while(d != 0);
        if(num == 1) {
            printOne(D[0]);
        } else {
            printTwo(D[1]);
            printTwo(D[0]);
        }
    }

    int main() {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        printf("#");
        toThree(r);
        toThree(g);
        toThree(b);
        return 0;
    }
*/
