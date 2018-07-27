/**
* 分析：A+B=C,货币进制转换，直接翻译的，又写麻烦了，不用结构体。。。
*       直接用三个大小为3的一维数组就行，这样获得结果也可以直接取余，不用temp暂存数据
*       这题简单怎么做都行不深究了意义不大。。。
**/

#include <cstdio>

struct current {
    int galleon;
    int sickle;
    int knut;
};

int main() {
    current coin;
    int galleon, sickle, knut;
    scanf("%d.%d.%d", &galleon, &sickle, &knut);
    coin.galleon = galleon;
    coin.sickle = sickle;
    coin.knut = knut;
    scanf("%d.%d.%d", &galleon, &sickle, &knut);
    coin.knut += knut;
    if(coin.knut >= 29) {
        int temp = coin.knut;
        coin.knut = coin.knut % 29;
        coin.sickle += temp / 29;
    }
    coin.sickle += sickle;
    if(coin.sickle >= 17) {
        int temp = coin.sickle;
        coin.sickle = coin.sickle % 17;
        coin.galleon += temp / 17;
    }
    coin.galleon += galleon;
    printf("%d.%d.%d", coin.galleon, coin.sickle, coin.knut);
    return 0;
}
