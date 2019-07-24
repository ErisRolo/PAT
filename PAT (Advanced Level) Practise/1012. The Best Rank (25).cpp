/**
* 分析：排序，处理逻辑过于复杂，而且只得了22分，有一个段错误，不太好找不找了
*       参考柳神和晴神宝典的解法，学会数组在排序中的使用，逻辑不太好掌握的话也要学会简化代码
*       更新：去掉cmp中的if(a!=b)，可解决段错误，不知道为啥，问下晴神
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;

struct student {
	int id;
	int c, m, e, a;
	int rc, rm, re, ra;
} stu[maxn];

bool cmpc(student a, student b) {
	return a.c > b.c;
}

bool cmpm(student a, student b) {
	return a.m > b.m;
}

bool cmpe(student a, student b) {
	return a.e > b.e;
}

bool cmpa(student a, student b) {
	return a.a > b.a;
}

int main() {
	int n, m;
	int query, flag = -1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
		stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3.0 + 0.5;
	}
	sort(stu, stu + n, cmpc);
	stu[0].rc = 1;
	for(int i = 1; i < n; i++) {
		if(stu[i].c != stu[i - 1].c)
			stu[i].rc = i + 1;
		else
			stu[i].rc = stu[i - 1].rc;
	}
	sort(stu, stu + n, cmpm);
	stu[0].rm = 1;
	for(int i = 1; i < n; i++) {
		if(stu[i].m != stu[i - 1].m)
			stu[i].rm = i + 1;
		else
			stu[i].rm = stu[i - 1].rm;
	}
	sort(stu, stu + n, cmpe);
	stu[0].re = 1;
	for(int i = 1; i < n; i++) {
		if(stu[i].e != stu[i - 1].e)
			stu[i].re = i + 1;
		else
			stu[i].re = stu[i - 1].re;
	}
	sort(stu, stu + n, cmpa);
	stu[0].ra = 1;
	for(int i = 1; i < n; i++) {
		if(stu[i].a != stu[i - 1].a)
			stu[i].ra = i + 1;
		else
			stu[i].ra = stu[i - 1].ra;
	}
	while(m--) {
		scanf("%d", &query);
		for(int i = 0; i < n; i++) {
			if(stu[i].id == query) {
				flag = i;
				break;
			}
		}
		if(flag != -1) {
			if(stu[flag].ra <= stu[flag].rc
			        && stu[flag].ra <= stu[flag].rm
			        && stu[flag].ra <= stu[flag].re)
				printf("%d A\n", stu[flag].ra);
			else if(stu[flag].rc <= stu[flag].rm
			        && stu[flag].rc <= stu[flag].re)
				printf("%d C\n", stu[flag].rc);
			else if(stu[flag].rm <= stu[flag].re)
				printf("%d M\n", stu[flag].rm);
			else
				printf("%d E\n", stu[flag].re);
			flag = -1;
		} else {
			printf("N/A\n");
		}
	}
	return 0;
}
