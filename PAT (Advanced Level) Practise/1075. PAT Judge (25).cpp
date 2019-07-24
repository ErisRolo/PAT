/**
* 分析：虽然自己做出来了，但做得很慢,在考场上根本没意义
*       以后真的不能自己死抠，还有思考要快，不要不慌不忙地debug
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

struct User {
	int id;
	int score[6]= {-1,-1,-1,-1,-1,-1}; // k<=5
	int total;
	int rank;
	int solve;
	bool flag;
} user[maxn];

bool cmp(User a,User b) {
	if(a.total!=b.total)
		return a.total>b.total;
	else if(a.solve!=b.solve)
		return a.solve>b.solve;
	else
		return a.id<b.id;
}

int grade[6] = {0};

int main() {
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1; i<=n; i++)
		user[i].id=i;
	for(int i=1; i<=k; i++)
		scanf("%d",&grade[i]);
	int id,num,score;
	for(int i=0; i<m; i++) {
		scanf("%d %d %d",&id,&num,&score);
		if(score!=-1)
			user[id].flag=true;
		if(score==-1 && user[id].score[num]==-1)
			user[id].score[num]=0;
		if(score>user[id].score[num]) {
			user[id].score[num]=score;
			if(score==grade[num])
				user[id].solve++;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			if(user[i].score[j]!=-1)
				user[i].total+=user[i].score[j];
		}
	}
	sort(user+1,user+n+1,cmp);
	user[1].rank=1;
	for(int i=2; i<=n; i++) {
		if(user[i].total==user[i-1].total)
			user[i].rank=user[i-1].rank;
		else
			user[i].rank=i;
	}
	for(int i=1; i<=n; i++) {
		if(user[i].flag) {
			printf("%d %05d %d ",user[i].rank,user[i].id,user[i].total);
			for(int j=1; j<=k; j++) {
				if(user[i].score[j]!=-1)
					printf("%d",user[i].score[j]);
				else
					printf("-");
				if(j!=k)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
	return 0;
}
