#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, Q;
int f[10010]; // 父节点


int findFater(int x){
    int a = x;
    while(f[x] != x){
        x = f[x];
    }
    while(f[a] != a){
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

set<int> num_set; // 所有数字集合

bool visit[10010] = {false}; // 该数是否出现过

vector<int> vec; // 暂存一棵树上的数字

int main(){

    scanf("%d", &N);

    for(int m = 0; m < N; m++){
        int k, tmp;
        vec.clear();
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &tmp);
            vec.push_back(tmp);
            num_set.insert(tmp);
        }

        set<int> fset; // 父节点的集合
        for(int i = 0; i < vec.size(); i++){
            if(visit[vec[i]]){   // 数字出现过, 则获得父节点集合
                int fu = findFater(vec[i]);
                fset.insert(fu);
            }
        }
        if(fset.size() > 0){ // 有一个或多个数字(根)出现过
            // 关联集合, 其他根节点设为第一个根节点的子节点
            for(auto it = fset.begin(); it != fset.end(); it++){
                f[*it] = *(fset.begin());
            }
            // 关联集合
            for(int i = 0; i < vec.size(); i++){
                f[vec[i]] = *(fset.begin());
                visit[vec[i]] = true; // 最后把 visit 设为 true
            }
        }
        else{ // 数字都没出现过, 则设其父节点为第一个数
           for(int i = 0; i < vec.size(); i++){
                f[vec[i]] = vec[0];
                visit[vec[i]] = true; // 最后把 visit 设为 true
           }
        }
    }

    int cnt = 0; // 根节点数目
    for(auto it = num_set.begin(); it!=num_set.end(); it++){
        if(f[*it] == *it) cnt++;
    }
    printf("%d %d\n", cnt, num_set.size());
    scanf("%d", &Q);
    int a, b;
    for(int i = 0; i < Q; i++){
        scanf("%d %d", &a, &b);
        int f_a = findFater(a);
        int f_b = findFater(b);
        if(f_a == f_b) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
