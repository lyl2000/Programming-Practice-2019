#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 200+5;
struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};
vector<Edge> E[N];
int a[N], dis[N], cnt[N], pre[N];
bool inq[N], isNeg[N];
queue<int> q, neg;

void addEdge(int u, int v, int w){
	E[u].push_back(Edge(u, v, w));  //有向 
}

void negRing(int s){
	if(isNeg[s]) return;
	isNeg[s] = 1; neg.push(s);
	while(!neg.empty()){
		int u = neg.front(); neg.pop();
		for(int i = 0, len = E[u].size(); i < len; ++i){
			Edge e = E[u][i]; int v = e.v;
			if(isNeg[v]) continue;
			isNeg[v] = 1; neg.push(v);
		}
	}
}

void SPFA(int s, int n){
	for(int i = 1; i <= n; ++i){
		dis[i] = INF; inq[i] = 0; pre[i] = 0;
		cnt[i] = 0; isNeg[i] = 0;
	}
	dis[s] = 0; inq[s] = 1; q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop(); inq[u] = 0;
		for(int i = 0, len = E[u].size(); i < len; ++i/*Edge e : E[u]*/){
			Edge e = E[u][i]; int v = e.v;
			if(dis[v] > dis[u] + e.w){
				cnt[v] = cnt[u] + 1;
				if(cnt[v] >= n){
					negRing(v); continue; //打上标记
				}
				dis[v] = dis[u] + e.w;
				pre[v] = u;
				if(!inq[v]){
					q.push(v); inq[v] = 1;
				}
			}
		}
	}
}

int main(){
	int t; scanf("%d", &t);
	for(int k = 1; k <= t; ++k){
		for(int i = 0; i < N; ++i)
			while(!E[i].empty()) E[i].pop_back();
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int m; scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			int A, B; scanf("%d %d", &A, &B);
			addEdge(A, B, pow(a[B]-a[A], 3));
		}
		SPFA(1, n);
		int q; scanf("%d", &q);
		printf("Case %d:\n", k);
		for(int i = 1; i <= q; ++i){
			int p; scanf("%d", &p);
			if(isNeg[p] || !isNeg[p]&&dis[p]<3 || !pre[p]) printf("?\n");
			else printf("%d\n", dis[p]);
		}
	}
	return 0;
} 
