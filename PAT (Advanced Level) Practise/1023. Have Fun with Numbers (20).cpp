#include<bits/stdc++.h>
using namespace std;

int main()
{
    char num[22];
    int a[11]={0},flag=0,is=1;
    scanf("%s",num);
    for(int i=strlen(num)-1;i>=0;i--)
    {
        int t = num[i]-'0';
        a[t]++;
        t = t*2+flag;
        flag=0;
        if(t>=10)
        {
            t-=10;
            flag=1;
        }
        num[i] = t+'0';
        a[t]--;
    }
    for(int i=0;i<10;i++)
    {
        if(a[i]!=0)
        {
            is=0;
            break;
        }
    }
    if(is)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    if(flag==1)
        cout<<"1";
    for(int i=0;i<strlen(num);i++)
        cout<<num[i];
}
