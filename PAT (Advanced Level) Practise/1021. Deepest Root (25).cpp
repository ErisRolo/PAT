/* 1021. Deepest Root (25) 

A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int max_deepth = 1;
int f[10010]; // 父节点
int g[10010][10010]; // 节点连接关系
vector<int> result;
vector<int> tmp;

void init()
{
    for (int i = 1; i <= N; i++)
    {
        f[i] = i;
    }
}

int get_root(int x)
{
    int a = x;
    while (f[x] != x)
    {
        x = f[x];
    }
    // 压缩路径
    while (f[a] != a)
    {
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

void union_root(int a, int b)
{
    int r_a = get_root(a);
    int r_b = get_root(b);
    if (r_a != r_b)
    {
        f[r_b] = r_a;
    }
    return;
}

void dfs(int id, int pre, int deepth){
    if(deepth > max_deepth){
        max_deepth = deepth;
        tmp.clear();
        tmp.push_back(id);
    }
    else if(deepth == max_deepth){
        tmp.push_back(id);
    }
    for(int i = 1; i <= N; i++){
        if(g[id][i] && i != pre){
           dfs(i, id, deepth+1); 
        }
    }
}

int main()
{
    scanf("%d", &N);
    init();
    int a, b;
    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b] = 1;
        g[b][a] = 1;
        union_root(a, b);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (f[i] == i)
            cnt++;
    }
    if (cnt > 1)
    {
        printf("Error: %d components", cnt);
    }
    else
    {
        dfs(1, -1, 1); // 从 1 号节点深度遍历, 表示深度为1
        // result.assign(tmp.begin(), tmp.end());
        result = tmp;
        tmp.clear();
        dfs(result[0], -1, 1); // 随便找一个已知最深节点, 开始第二轮遍历
        result.insert(result.end(), tmp.begin(), tmp.end());
        sort(result.begin(), result.end());
        int last = -1;
        for(auto i = result.begin(); i != result.end(); i++){
            if(last != *i) printf("%d\n", *i); // 去重
            last = *i;
        }
    }
    return 0;
}