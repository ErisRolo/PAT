/**
* 分析：简单题，看到大神说读完题后三分钟AC，然后我也想试一下
*       我用了大概快十分钟。。。真的没法三分钟啊。。。
*       而且越是想缩短时间尽快写出来，就越慌反而写的越手忙脚乱。。。
*       在最后控制空格那耽误了点时间，明明一下子就可以写好的，就少了个else
*       考场上绝对不能慌，要紧张抓紧，但不能乱
**/

#include <cstdio>
const int maxn = 10010;

int hash[maxn];

int main() {
    int n;
    int num, sum = 0, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        if(hash[sum] == 0) {
            hash[sum]++;
            count++;
        } else {
            hash[sum]++;
        }
        sum = 0;
    }
    printf("%d\n", count);
    for(int i = 0; i < maxn; i++) {
        if(hash[i] != 0 && count != 1) {
            printf("%d ", i);
            count--;
        } else if(hash[i] != 0 && count == 1)
            printf("%d", i);
    }
    return 0;
}
