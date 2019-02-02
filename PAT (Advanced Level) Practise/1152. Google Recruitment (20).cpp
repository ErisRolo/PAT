#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

bool isprime(int n){
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;	
}

int main(){
	int l,k;
	string s,r;
	bool f = false;
	scanf("%d%d",&l,&k);
	cin>>s;
	for(int i=0;i<=l-k;i++){
		r=s.substr(i,k);
		if(isprime(atoi(r.c_str()))){
			cout<<r;
			f=true;
			break;
		}
	}
	if(f==false)
		printf("404\n");
	return 0;
} 
