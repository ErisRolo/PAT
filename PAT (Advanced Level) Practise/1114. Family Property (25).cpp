#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;

struct Person{
	int id; 
	set<int> p;
	set<int> c;
	int e_cnt;
	int area;
	bool in;
}list[10000];

struct Res{
	int id;
	int cnt;
	double avg_sets;
	double avg_area;
};

vector<int> vec;

bool vis[10000] = {false}; // 是否算过
bool flag[10000] = {false}; // 是否算过

void dfs(int n, vector<int> &family){
	if(list[n].p.size() == 0 || vis[n]) return; // 不在集合中或已访问过
	vis[n] = true;  // 访问过该 id
	if(list[n].in) family.push_back(n);
	for(auto it = list[n].p.begin(); it != list[n].p.end(); it++){
		if(*it != -1) dfs(*it, family);
	}

	if(list[n].c.size() != 0){
		for(auto it = list[n].c.begin(); it != list[n].c.end(); it++){
			dfs(*it, family);
		}
	}
}

bool cmp(Res &lhs, Res &rhs){
	if(lhs.avg_area > rhs.avg_area) return true;
	else if(lhs.avg_area == rhs.avg_area && lhs.id < rhs.id) return true;
	else return false;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int id, f, m;
		scanf("%d", &id);
		list[id].id = id;
		scanf("%d %d", &f, &m);
		list[id].p.insert(f);
		list[id].p.insert(m);
		if(f!=-1) list[f].c.insert(id);
		if(m!=-1) list[m].c.insert(id);

		vec.push_back(list[id].id);
		int c_cnt, tmp;
		scanf("%d", &c_cnt);
		for(int j = 0; j < c_cnt; j++){
			scanf("%d", &tmp);
			list[id].c.insert(tmp);
			list[tmp].p.insert(id);
		}
		list[id].in = true;
		scanf("%d %d", &list[id].e_cnt, &list[id].area);		
	}
	vector<vector<int>> group; 
    
    
    for(int i = 0; i < N; i++){
        vector<int> family;
        dfs(vec[i], family);
        if(family.size() != 0) group.push_back(family);
    }
    vector<Res> ans;
    for(int i = 0; i < group.size(); i++){
        Res res;
        res.cnt = 0;
    	fill(flag, flag+10000, false);
        int min = 2147483647;
        
    	double set_sum = 0;
        double area_sum = 0;

        // 确保 group 中都是有资产的
    	for(int j = 0; j < group[i].size(); j++){
    		int id = group[i][j];
            if(id < min) min = id;

    		set_sum += list[id].e_cnt;
            area_sum += list[id].area;

    		if(!flag[id]){
    			res.cnt++;
    			flag[id] = true;  // 访问过
            }

    		for(auto it = list[id].p.begin(); it != list[id].p.end(); it++){
    			if(*it != -1){
    				if(!flag[*it]){
                        if(*it < min) min = *it;
    					res.cnt++;
    					flag[*it] = true;  // 访问过
    				}
    			}
    		}

    		for(auto it = list[id].c.begin(); it != list[id].c.end(); it++){
    			if(!flag[*it]){
                    if(*it < min) min = *it;
    				res.cnt++;
    				flag[*it] = true;  // 访问过
    			}		
    		}
        }
        
        res.id = min;
        res.avg_sets = set_sum / res.cnt;
        res.avg_area = area_sum / res.cnt;
        ans.push_back(res);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].cnt, ans[i].avg_sets, ans[i].avg_area);
    }
    
    
    
	return 0;

}