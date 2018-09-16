/**
* 分析：考虑到指数可能为负，所以不能用数组，可以用map
*       草泥马改了之后测试点2还是不对，去你妈劳资不改了，浪费时间
*       真是服了，不知道这种测试数据有什么意义
*       直接边输入边输出
*       找出来了，除了0 0的数据，其他a≠0 0的数据输出也是0 0，和指数的正负没有关系
*       真尼玛服了。。。
**/

//#include <cstdio>
//using namespace std;
//
//int main() {
//    int a, b;
//    bool isFirst = true; //是否已有过输出
//    while (scanf("%d%d", &a, &b) != EOF) {
//        if(b != 0) {
//            if(!isFirst)
//                printf(" "); //控制每组数据前面的空格
//            printf("%d %d", a * b, b - 1);
//            isFirst = false;
//        }
//    }
//    if(isFirst == true)
//        printf("0 0");
//    return 0;
//}

#include <cstdio>
#include <map>
using namespace std;

map<int, int> e;
map<int, int> ans;

int main() {
    int a, b, cnt = 0; //cnt控制输出空格
    scanf("%d%d", &a, &b);
    e[b] = a;
    //if(a == 0 && b == 0) {
    if(b == 0) {
        printf("0 0");
        return 0;
    }
    while(scanf("%d%d", &a, &b) != EOF)
        e[b] = a;
    for(int i = 1000; i >0; i--) {
        if(e[i] != 0 && i != 0) {
            ans[i - 1] = i * e[i];
            cnt++;
        }
    }
    for(int i = 999; i >= 0; i--) {
        if(ans[i] != 0) {
            printf("%d %d", ans[i], i);
            cnt--;
            if(cnt != 0)
                printf(" ");
        }
    }
    return 0;
}
