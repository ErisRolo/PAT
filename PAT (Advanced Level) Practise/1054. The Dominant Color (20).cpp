/* 1054. The Dominant Color (20)

Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0, 224). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print the dominant color in a line.

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
int maxN, maxCount;
map<int, int> map1; // 计某个数出现几次
int main(){
    scanf("%d %d", &N, &M);
    int tmp;
    maxCount = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &tmp);
            if(map1.find(tmp)==map1.end()){
                map1[tmp] = 1;
            }
            else{
                map1[tmp]++;
            }
            if(map1[tmp] > maxCount){
                maxN = tmp;
                maxCount = map1[tmp];
            }
        }
    }

    printf("%d", maxN);
    return 0;
}

// 另一种方法

#include <cstdio>
#include <iostream>
using namespace std;

int N, M, now;
int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d", &now); // 读取第一个数
    int p = 1;         
    int tmp;
    for (int i = 1; i < N * M; i++)
    {
        scanf("%d", &tmp);
        if (p == -1)
        {
            p = 1;
            // now 总是在 p 为正的时候赋值
            now = tmp; // now 又出现第一次
        }

        if (tmp == now)
            p++;          // p 有多少+, 最后 p 为正才能说明比一半多
        else
            p--;          // p 有多少-

        if (p == 0) // p-- 一直到 0, 说明一直不是 now, now 应该改成下一个
            p = -1;
    }
    printf("%d", now);
    return 0;
}