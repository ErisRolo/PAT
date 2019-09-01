/**
* 分析：狼人杀，确定有两个狼人，有两个说谎者，其中一个是狼人
*       思路就是暴力枚举，假设i j是狼人（而不是假设为说谎者，题目要求输出的是狼人，看题目提示）
*       根据输入判断每个人是否说谎，遍历完成后，若说谎者为一个好人一个狼人即为所求
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;

int n, d[maxn], liewolves; //说谎的狼人数
vector<int> liar; //说谎者

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for(int i = 1; i <= n; i++) { //假设 i j为狼人
        for(int j = i + 1; j <= n; j++) {
            liewolves = 0;
            liar.clear();
            for(int k = 1; k <= n; k++) { //遍历每一个人
                if(d[k] < 0 && abs(d[k]) != i && abs(d[k]) != j) { //如果其指出某人是狼人但与假设狼人不符，则为说谎者
                    liar.push_back(k);
                    if(k == i || k == j)
                        liewolves++;
                } else if(d[k] > 0 && (d[k] == i || d[k] == j)) { //如果其指出某人是普通人类但为假设狼人，也为说谎者
                    liar.push_back(k);
                    if(k == i || k == j)
                        liewolves++;
                }
            }
            if(liar.size() == 2 && liewolves == 1) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
