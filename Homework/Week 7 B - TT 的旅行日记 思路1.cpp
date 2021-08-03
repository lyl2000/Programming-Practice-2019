#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N = 500+5;
const int M = 1000+5;
const int K = 1000+5;
const int INF = 0x3f3f3f3f;
struct Edge{
	int v, w;
	Edge(){}
	Edge(int _v, int _w):v(_v), w(_w){}
};
vector<Edge> E[N];
struct Point{
	int p, d;
	Point(){}
	Point(int _p, int _d):p(_p), d(_d){}
	bool operator<(const Point& P) const {
		return d < P.d;
	}
};
int pre1[N], pre2[N], vis[N], dis1[N], dis2[N];
priority_queue<Point> q;
void addEdge(int u, int v, int w){
	E[u].push_back(Edge(v, w));
	E[v].push_back(Edge(u, w));
}
void dijkstra(int s, int e, int n, int *dis, int *pre){
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; ++i){
		pre[i] = 0; vis[i] = 0;
		dis[i] = INF;
	}
	dis[s] = 0; q.push(Point(s, 0));
	while(!q.empty()){
		int u = q.top().p; q.pop();
		if(vis[u]){
			if(u == e) return;
			continue;
		}
		vis[u] = 1;
		for(int i = 0, len = E[u].size(); i < len; ++i){
			int v = E[u][i].v, w = E[u][i].w;
			if(vis[v]) continue;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w; pre[v] = u;
				q.push(Point(v, -dis[v]));
			}
		}
	}
}
void output1(int s, int e, int *pre){
	if(e == s) return;
	output1(s, pre[e], pre);
	printf(" %d", e);
}
void output2(int s, int e, int *pre){
	if(e == s) return;
	printf(" %d", pre[s]);
	output2(pre[s], e, pre);
}
int main(){
	int n, s, e, t = 0;
	while(~scanf("%d%d%d", &n, &s, &e)){
		for(int i = 1; i <= n; ++i)
			while(!E[i].empty()) E[i].pop_back();
		int x, y, z;
		int m; scanf("%d", &m);  //经济线 
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &x, &y, &z);
			addEdge(x, y, z);
		}
		dijkstra(s, e, n, dis1, pre1); dijkstra(e, s, n, dis2, pre2);
		int cost = dis1[e], temp = cost, u = 0, v = 0;
		int k; scanf("%d", &k);  //商业线
		for(int i = 0; i < k; ++i){
			scanf("%d%d%d", &x, &y, &z);
			int cost1 = dis1[x] + dis2[y] + z;
			int cost2 = dis1[y] + dis2[x] + z;
			if(cost1 < cost2 && cost1 < cost){
				cost = cost1; u = x; v = y;
			}else if(cost2 < cost1 && cost2 < cost){
				cost = cost2; u = y; v = x;
			}
		}
		if(t) printf("\n");
		if(temp > cost){
			printf("%d", s); output1(s, u, pre1);
			printf(" %d", v); output2(v, e, pre2);
			printf("\n%d\n%d\n", u, cost);
		}else{
			printf("%d", s); output1(s, e, pre1);
			printf("\nTicket Not Used\n%d\n", dis1[e]);
		}
		t++;
	}
	return 0;
}
