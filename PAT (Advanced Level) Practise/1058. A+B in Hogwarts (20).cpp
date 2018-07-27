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
