#include<bits/stdc++.h>
using namespace std;
vector<int> preorder,inorder;
int n,m;
map<int,int> mp;
void DFS(int PreL,int PreR,int InL,int InR,int a,int b){
    if(InL>InR)//返回条件
        return;
    int root=preorder[PreL];//开始操作
    int i;
    int posu=-1,posv=-1;//记录uv在inorder中的位置
    i=mp[root]-1;
    posu=mp[a]-1;
    posv=mp[b]-1;
    int numL=i-PreL;
    if(posu<i&&posv<i) DFS(PreL+1,PreL+numL,InL,i-1,a,b);
    else if((posu<i&&posv>i)||(posu>i&&posv<i)) cout<<"LCA of "<<a<<" and "<<b<<" is "<<root<<"."<<endl;
    else if(posu>i&&posv>i )DFS(PreL+1+numL,PreR,i+1,InR,a,b);
    else if(i==posu) cout<<a<<" is an ancestor of "<<b<<"."<<endl;
    else if(i==posv) cout<<b<<" is an ancestor of "<<a<<"."<<endl;
}
int main(){
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin>>temp;
        inorder.push_back(temp);
        mp[inorder[i]]=i+1;
    }
    for (int i = 0; i < m; i++) {
        int temp;
        cin>>temp;
        preorder.push_back(temp);
    }
    for (int i = 0; i <n ; i++) {
        int u,v;
        cin>>u>>v;
        if(mp[u]==0&&mp[v]==0)
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(mp[u]==0&&mp[v]!=0)
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(mp[u]!=0&&mp[v]==0)
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        else
            DFS(0,m-1,0,m-1,u,v);
    }
}
