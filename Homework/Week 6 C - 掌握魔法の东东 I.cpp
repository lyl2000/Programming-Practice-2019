#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 3e2+5;
struct Edge{
	int u, v, w;
	bool operator<(const Edge& e) const {
		return w < e.w;
	}
}edge[N*N];
int t[N], rk[N];

int find(int x){
	return t[x] == x ? x : t[x] = find(t[x]); 
}

bool unite(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	if(rk[x] > rk[y]){
		t[y] = x; rk[x] = (rk[y] += rk[x]);
	}else{
		t[x] = y; rk[y] = (rk[x] += rk[y]);
	}return true;
}

int main(){
	int n, cnt = 0, ans = 0; 
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i){
		t[i] = i; rk[i] = 1;
	}
	
	for(int i = 1; i <= n; ++i){
		int w; scanf("%d", &w);
		edge[cnt++] = {0, i, w};
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int p; scanf("%d", &p);
			if(i < j) edge[cnt++] = {i, j, p};
		}
	}
	
	sort(edge, edge+cnt);
	int num = 0;  //加入的边数 
	for(int i = 0; i < cnt; ++i){
		if(unite(edge[i].u, edge[i].v)){
			ans += edge[i].w;
			if(++num == n) break;  //共n+1个点 
		}
	}
	printf("%d\n", ans);
	return 0;
}
