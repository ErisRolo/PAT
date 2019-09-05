/**
* 分析：此题有多种思路，DFS，Dijkstra，Dijkstra+DFS，以救助站为起点或以派遣中心为起点
*       第一标尺为距离，第二标尺为车数，第三标尺为路径边数，其中车数可直接获得，需要处理的为路径边数
*       采用Dijkstra+DFS常规思路，选查询点作为起点
*       考虑到K次查询，按照普通模板写，如果通过DFS获取路径边数，需要K次Dijkstra+K*(na+1)次DFS，时间复杂度过高
*       因此使用Dijkstra选择最优路径，Dijkstra获取最短距离和路径边数，车数直接获取，DFS只打印路径，如此只需要K次Dijkstra+K次DFS
*       最后在main函数中根据条件选择最优终点即可，此时要处理所有条件，处理完毕后DFS打印路径即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1020;
const int inf = 1000000000;

struct Node {
    int v, dis;
};

int ns, na, m, k, st, ed;
vector<Node> adj[maxn];
int car[maxn], str[maxn];

int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
struct cmp {
    bool operator() (const int &x, const int &y)const {
        return d[x] > d[y];
    }
};
priority_queue<int, vector<int>, cmp> q;
void Dijkstra(int s) {
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, inf);
    d[s] = 0;
    str[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.top();
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            if(vis[v] == false) {
                if(d[u] + adj[u][j].dis < d[v]) {
                    d[v] = d[u] + adj[u][j].dis;
                    str[v] = str[u] + 1;
                    pre[v].clear();
                    pre[v].push_back(u);
                    q.push(v);
                } else if(d[u] + adj[u][j].dis == d[v] && str[u] + 1 <= str[v]) {
                    str[v] = str[u] + 1;
                    pre[v].push_back(u);
                    q.push(v);
                }
            }
        }
    }
}

vector<int> path;
void DFS(int v) {
    if(v == st) {
        path.push_back(v);
        for(int i = 0; i < path.size(); i++) {
            if(path[i] > ns)
                printf("A-%d", path[i] - ns);
            else
                printf("%d", path[i]);
            if(i != path.size() - 1)
                printf(" ");
        }
        printf("\n%d\n", d[path[0]]);
        path.pop_back();
        return;
    }
    path.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    path.pop_back();
}

int main() {
    int a, b, t;
    string sa, sb;
    scanf("%d%d", &ns, &na);
    for(int i = 1; i <= na; i++)
        scanf("%d", &car[ns + i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        cin >> sa >> sb >> t;
        if(sa[0] == 'A') {
            if(sa.size() == 3)
                a = ns + (sa[2] - '0');
            else
                a = ns + 10;
        } else
            a = stoi(sa);
        if(sb[0] == 'A') {
            if(sb.size() == 3)
                b = ns + (sb[2] - '0');
            else
                b = ns + 10;
        } else
            b = stoi(sb);
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &st);
        Dijkstra(st);
        int ans = -1, mindis = inf, maxcar = -1, minstr = inf;
        for(int i = 1; i <= na; i++) {
            if(car[ns + i] > 0) {
                if(d[ns + i] < mindis) {
                    ans = ns + i;
                    mindis = d[ns + i];
                    maxcar = car[ns + i];
                    minstr = str[ns + i];
                } else if(d[ns + i] == mindis && car[ns + i] > maxcar) {
                    ans = ns + i;
                    maxcar = car[ns + i];
                    minstr = str[ns + i];
                } else if(d[ns + i] == mindis && car[ns + i] == maxcar && str[ns + i] <= minstr) {
                    ans = ns + i;
                    minstr = str[ns + i];
                }
            }
        }
        if(ans != -1) {
            DFS(ans);
            car[ans]--;
        } else
            printf("All Busy\n");
    }
    return 0;
}







































//**
//* 分析：Dijkstra+DFS版，将pick spot作为起点，派遣中心作为终点
//        每次查询对起点用一次dijkstra，然后对每个终点用一次DFS
//*       每个派遣中心之间比较的是距离，车数和街道数
//*       对每个派遣中心的路径比较的是街道数，所以DFS只需用街道作为第二标尺
//*       完成后最后一个点WA
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1020;
//const int inf = 1000000000;
//
//struct Node {
//	int v,dis;
//};
//
//int ns,na,m,k,st,ed;
//vector<Node> adj[maxn];
//int car[maxn];
//
//int d[maxn];
//bool vis[maxn];
//vector<int> pre[maxn];
//struct cmp {
//	bool operator() (const int &x,const int &y)const {
//		return d[x]>d[y];
//	}
//};
//priority_queue<int,vector<int>,cmp> q;
//void Dijkstra(int s) {
//	fill(vis,vis+maxn,false);
//	fill(d,d+maxn,inf);
//	d[s]=0;
//	q.push(s);
//	while(!q.empty()) {
//		int u=q.top();
//		q.pop();
//		if(vis[u])
//			continue;
//		vis[u]=true;
//		for(int j=0; j<adj[u].size(); j++) {
//			int v=adj[u][j].v;
//			if(vis[v]==false) {
//				if(d[u]+adj[u][j].dis<d[v]) {
//					d[v]=d[u]+adj[u][j].dis;
//					pre[v].clear();
//					pre[v].push_back(u);
//					q.push(v);
//				} else if(d[u]+adj[u][j].dis==d[v]) {
//					pre[v].push_back(u);
//					q.push(v);
//				}
//			}
//		}
//	}
//}
//
//int tminstr=inf,tmaxnum=-1;
//vector<int> path,temppath;
//void DFS(int v) {
//	if(v==st) {
//		temppath.push_back(v);
//		int str=temppath.size()-1,num=temppath[temppath.size()-2];
//		if(str<tminstr) {
//			path=temppath;
//			tminstr=str;
//			tmaxnum=num;
//		} else if(str==tminstr&&num>tmaxnum) {
//			path=temppath;
//			tmaxnum=num;
//		}
//		temppath.pop_back();
//		return;
//	}
//	temppath.push_back(v);
//	for(int i=0; i<pre[v].size(); i++)
//		DFS(pre[v][i]);
//	temppath.pop_back();
//}
//
//int main() {
//	int a,b,t;
//	string sa,sb;
//	scanf("%d%d",&ns,&na);
//	for(int i=1; i<=na; i++)
//		scanf("%d",&car[ns+i]);
//	scanf("%d",&m);
//	for(int i=0; i<m; i++) {
//		cin>>sa>>sb>>t;
//		if(sa[0]=='A') {
//			if(sa.size()==3)
//				a=ns+(sa[2]-'0');
//			else
//				a=ns+10;
//		} else
//			a=stoi(sa);
//		if(sb[0]=='A') {
//			if(sb.size()==3)
//				b=ns+(sb[2]-'0');
//			else
//				b=ns+10;
//		} else
//			b=stoi(sb);
//		adj[a].push_back({b,t});
//		adj[b].push_back({a,t});
//	}
//	scanf("%d",&k);
//	while(k--) {
//		scanf("%d",&st);
//		Dijkstra(st);
//		int ans=-1,mindis=inf,maxcar=-1,minstr=inf,maxnum=-1;
//		for(int i=1; i<=na; i++) {
//			if(car[ns+i]>0) {
//				tminstr=inf,tmaxnum=-1;
//				DFS(ns+i);
//				int str=tminstr,num=tmaxnum;
//				if(d[ns+i]<mindis) {
//					ans=ns+i;
//					mindis=d[ns+i];
//					maxcar=car[ns+i];
//					minstr=str;
//					maxnum=num;
//				} else if(d[ns+i]==mindis&&car[ns+i]>maxcar) {
//					ans=ns+i;
//					maxcar=car[ns+i];
//					minstr=str;
//					maxnum=num;
//				} else if(d[ns+i]==mindis&&car[ns+i]==maxcar&&str<minstr) {
//					ans=ns+i;
//					minstr=str;
//					maxnum=num;
//				} else if(d[ns+i]==mindis&&car[ns+i]==maxcar&&str==minstr&&num>maxnum) {
//					ans=ns+i;
//					maxnum=num;
//				}
//			}
//		}
//		if(ans!=-1) {
//			tminstr=inf,tmaxnum=-1; //DFS初始条件别忘
//			DFS(ans);
//			car[ans]--;
//			printf("A-%d",path[0]-ns);
//			for(int i=1; i<path.size(); i++) {
//				if(path[i]>ns)
//					printf(" A-%d",path[i]-ns);
//				else
//					printf(" %d",path[i]);
//			}
//			printf("\n%d\n",d[ans]);
//		} else
//			printf("All Busy\n");
//	}
//	return 0;
//}













































//**
//* 分析：考场模拟版本，纯DFS，26分，最后一个点TLE
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1020;
//const int inf = 1000000000;
//
//struct Node {
//    int v, dis;
//};
//
//int ns, na, m, k;
////int g[maxn][maxn];
//vector<Node> adj[maxn];
//int car[maxn]; //停的救护车数目
//
//int mindis, maxcar, minstr;
//bool vis[maxn];
//vector<int> path, temppath;
//set<int> busy;
//void DFS(int s) {
//    if(s > 1000) { //如果遍历到了派遣中心
//        if(car[s] > 0) {
//            temppath.push_back(s);
//            vis[s] = true;
//            int dis = 0, str = 0;
//            str = temppath.size() - 1;
//            for(int i = 0; i < temppath.size() - 1; i++) {
//                int id = temppath[i], nextid = temppath[i + 1];
//                int j;
//                for(j = 0; j < adj[id].size(); j++) {
//                    if(adj[id][j].v == nextid)
//                        break;
//                }
//                //dis+=g[id][nextid];
//                dis += adj[id][j].dis;
//            }
//            if(dis < mindis) {
//                mindis = dis;
//                maxcar = car[s];
//                minstr = str;
//                path = temppath;
//            } else if(dis == mindis && car[s] > maxcar) {
//                maxcar = car[s];
//                minstr = str;
//                path = temppath;
//            } else if(dis == mindis && car[s] == maxcar && str < minstr) {
//                minstr = str;
//                path = temppath;
//            }
//            temppath.pop_back();
//            vis[s] = false;
//        } else {
//            busy.insert(s);
//        }
//    }
//    temppath.push_back(s);
//    vis[s] = true;
//    for(int i = 0; i < adj[s].size(); i++) {
//        int v = adj[s][i].v;
//        if(vis[v] == false)
//            DFS(v);
//    }
//    temppath.pop_back();
//    vis[s] = false;
//}
//
//int main() {
//    //fill(g[0],g[0]+maxn*maxn,inf);
//    int a, b, d, q;
//    string sa, sb;
//    scanf("%d%d", &ns, &na);
//    for(int i = 1; i <= na; i++)
//        scanf("%d", &car[1000 + i]);
//    scanf("%d", &m);
//    for(int i = 0; i < m; i++) {
//        cin >> sa >> sb >> d;
//        if(sa[0] == 'A') {
//            if(sa.size() == 3)
//                a = 1000 + sa[2] - '0';
//            else
//                a = 1010;
//        } else
//            a = stoi(sa);
//        if(sb[0] == 'A') {
//            if(sb.size() == 3)
//                b = 1000 + sb[2] - '0';
//            else
//                b = 1010;
//        } else
//            b = stoi(sb);
//        //g[a][b]=g[b][a]=d;
//        adj[a].push_back({b, d});
//        adj[b].push_back({a, d});
//    }
//    scanf("%d", &k);
//    while(k--) {
//        scanf("%d", &q);
//        mindis = inf, maxcar = -1, minstr = inf;
//        fill(vis, vis + maxn, false);
//        temppath.clear();
//        path.clear();
//        busy.clear();
//        DFS(q);
//        if(busy.size() != na) {
//            printf("A-%d", path[path.size() - 1] - 1000);
//            for(int i = path.size() - 2; i >= 0; i--) {
//                if(path[i] > 1000)
//                    printf(" A-%d", path[i] - 1000);
//                else
//                    printf(" %d", path[i]);
//            }
//            printf("\n%d\n", mindis);
//            car[path[path.size() - 1]]--;
//        } else
//            printf("All Busy\n");
//    }
//    return 0;
//}
