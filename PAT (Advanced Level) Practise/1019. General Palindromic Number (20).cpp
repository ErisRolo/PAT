#include <cstdio>

//判断数组z所存的数是否为回文数，num为位数
bool Judge(int z[], int num) {
    for (int i = 0; i <= num / 2; i++) {
        if (z[i] != z[num - 1 - i])
            return false; //如果位置i与其对称位置num-1-i不相同
    }
    return true; //所有对称位置都相同
}

int main() {
    int n, b, z[40], num = 0; //数组z存放转换结果，num为其位数
    scanf("%d%d", &n, &b); //输入题目给定的n与b
    //将n转换为b进制，结果存在数组z中
    do {
        z[num++] = n % b; //除基取余
        n /= b;
    } while (n != 0); //当n变为0时退出循环
    bool  flag = Judge(z, num); //判断数组z保存的数是否回文
    if (flag == true)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", z[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
