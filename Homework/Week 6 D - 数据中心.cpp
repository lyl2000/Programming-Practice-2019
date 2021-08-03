#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 5e4+5, M = 1e5+5;
struct Edge{
	int v, u, t;
	bool operator<(const Edge& e) const {
		return t < e.t;
	}
}edge[M];
int p[N], rk[N];

int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]); 
}

bool unite(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	if(rk[x] > rk[y]){
		p[y] = x; rk[x] = (rk[y] += rk[x]);
	}else{
		p[x] = y; rk[y] = (rk[x] += rk[y]);
	}return true;
}

int main(){
	int n, m, root, num = 0, ans = 0;
	scanf("%d %d %d", &n, &m, &root);
	for(int i = 1; i <= n; ++i){
		p[i] = i; rk[i] = 1; 
	}
	for(int i = 0; i < m; ++i)
		scanf("%d %d %d", &edge[i].v, &edge[i].u, &edge[i].t);
	sort(edge, edge+m);
	for(int i = 0; i < m; ++i){
		if(unite(edge[i].v, edge[i].u)){
			ans = ans > edge[i].t ? ans : edge[i].t;
			if(++num == n-1) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
