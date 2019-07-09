#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
const ll INF = 0x3f3f3f3f;
const double eps=1e-4;
const int T=3;

string str;
int k;

string add(string a,string b) {
    char ans[N]= {0};
    ans[N-1]='\0';
    int len=N-2;
    for(int i=a.length()-1; i>=0; i--,len--) {
        int tmp=ans[len]+a[i]-'0'+b[i]-'0';
        if(tmp>9) {
            ans[len]=tmp%10+'0';
            ans[len-1]++;
        } else {
            ans[len]=tmp+'0';
        }
    }
    if(ans[len]>0) {
        ans[len]+='0';
        len--;
    }
    return string(ans+len+1);
}

int main() {
    cin>>str>>k;
    bool flag=0;
    for(int i=0; i<k; i++) {
        string s=str;
        reverse(s.begin(),s.end());
        if(s!=str) {
            str=add(str,s);
        } else {
            flag=1;
            cout<<str<<"\n"<<i<<endl;
            break;
        }
    }
    if(!flag) {
        cout<<str<<"\n"<<k<<endl;
    }
    return 0;
}
