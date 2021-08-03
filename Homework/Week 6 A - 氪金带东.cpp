#include <stdio.h>
#include <vector>
using namespace std;

const int N = 1e4+10;
struct Edge{
	int u, v;
	long long w;
	Edge(){}
	Edge(int _u, int _v, long long _w):u(_u), v(_v), w(_w){}
};
vector<Edge> E[N];
long long vis[N], length, lens[N];
int leaf[3], index;  //2个叶子的索引 

void addEdge(int u, int v, long long w){
	E[u].push_back(Edge(u, v, w));
	E[v].push_back(Edge(v, u, w));
}

void dfs(int u, long long len){
	if(len > length){
		length = len;
		leaf[index] = u;  //跟新最远叶结点 
	}
	for(int i = 0, n = E[u].size(); i < n; ++i){
		if(vis[E[u][i].v] == -1){
			vis[E[u][i].v] = len + E[u][i].w;
			dfs(E[u][i].v, len + E[u][i].w);
		}
	}
} 

int main(){
	int n; 
	while(~scanf("%d", &n)){
		for(int i = 0; i < N; ++i){
			while(!E[i].empty()) E[i].pop_back();
		}
		for(int i = 2; i < n + 1; ++i){
			int v; long long w;
			scanf("%d %lld",&v, &w);
			addEdge(i, v, w);
		}
		for(int i = 1; i <= n; ++i) vis[i] = -1;
		index = 0; length = 0;
		vis[2] = 0; dfs(2, 0);  //找离u最远的叶子结点 
		
		for(int i = 1; i <= n; ++i) vis[i] = -1;
		index = 1; length = 0;
		vis[leaf[0]] = 0; dfs(leaf[0], 0);
		
		for(int i = 1; i <= n; ++i){
			lens[i] = vis[i];
			vis[i] = -1;
		}
		 
		index = 2; length = 0;
		vis[leaf[1]] = 0; dfs(leaf[1], 0);
		
		for(int i = 1; i <= n; ++i){
//			printf("%d %d\n", vis[i], lens[i]);
			printf("%lld\n", vis[i] > lens[i] ? vis[i] : lens[i]);
		}
	}
	return 0;
} 
