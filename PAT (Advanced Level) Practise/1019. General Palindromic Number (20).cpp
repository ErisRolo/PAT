/**
* 分析：将十进制数N转换为b进制数，判断转换后的数是不是回文数并输出
*       很简单，除基取余，循环判断即可（判断条件只判断一半就好可以提高效率），不赘述
**/

#include <cstdio>

int main() {
    int N, b;
    int n[40], num = 0;
    bool flag = true;
    scanf("%d %d", &N, &b);
    do {
        n[num++] = N % b;
        N /= b;
    } while(N != 0);
    for(int i = 0; i < num / 2; i++) {
        if(n[i] != n[num - i - 1]) {
            flag = false;
            break;
        }
    }
    if(flag == true)
        printf("Yes\n");
    else
        printf("No\n");
    for(int i = num - 1; i > 0; i--)
        printf("%d ", n[i]);
    printf("%d", n[0]);
    return 0;
}
