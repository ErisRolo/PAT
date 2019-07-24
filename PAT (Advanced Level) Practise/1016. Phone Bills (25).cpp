/**
* 分析：第一次独立写下来，太慢了，一个小时了。。。 
*       主要掌握时间统计的方法 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

struct Record {
	char name[21];
	int month,day,hour,minute;
	int flag; // 1:on-line 2:off-line
} rec[maxn];

bool cmp(Record r1,Record r2) {
	if(strcmp(r1.name,r2.name)!=0)
		return strcmp(r1.name,r2.name)<0;
	else if(r1.month!=r2.month)
		return r1.month<r2.month;
	else if(r1.day!=r2.day)
		return r1.day<r2.day;
	else if(r1.hour!=r2.hour)
		return r1.hour<r2.hour;
	else
		return r1.minute<r2.minute;

}

int toll[24];

int main() {
	for(int i=0; i<24; i++) {
		scanf("%d",&toll[i]);
	}
	int n;
	char word[9];
	bool first = true;
	double total=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].month,&rec[i].day,&rec[i].hour,&rec[i].minute,word);
		if(strcmp(word,"on-line")==0)
			rec[i].flag=1;
		else if(strcmp(word,"off-line")==0)
			rec[i].flag=2;
	}
	sort(rec,rec+n,cmp);
	for(int i=0; i<n; i++) {
		if(strcmp(rec[i].name,rec[i+1].name)==0 && rec[i].flag==1 && rec[i+1].flag==2) {
			if(first) {
				printf("%s %02d\n",rec[i].name,rec[i].month);
				first = false;
			}
			Record temp = rec[i];
			int time=0;
			double money=0;
			while(temp.day<rec[i+1].day || temp.hour<rec[i+1].hour || temp.minute<rec[i+1].minute) {
				temp.minute++;
				time++;
				money+=toll[temp.hour];
				if(temp.minute==60) {
					temp.minute=0;
					temp.hour++;
				}
				if(temp.hour==24) {
					temp.hour=0;
					temp.day++;
				}
			}
			money/=100.0;
			total+=money;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",rec[i].day,rec[i].hour,rec[i].minute,rec[i+1].day,rec[i+1].hour,rec[i+1].minute,time,money);
		}
		if(strcmp(rec[i].name,rec[i+1].name)!=0 && total!=0) {
			printf("Total amount: $%.2f\n",total);
			first=true;
			total=0;
		}

	}
	return 0;
}
