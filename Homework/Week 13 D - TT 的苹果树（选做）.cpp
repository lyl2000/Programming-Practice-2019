#include <stdio.h>
#include <vector>
#define max(x, y) x>y?x:y
using namespace std;
const int N = 6e3+20;
int w[N], vis[N], dp[N][2], n;
vector<int> g[N];
void dfs(int v) {
	vis[v] = 1;
	for(int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if(vis[u] == 0) dfs(u);
		dp[v][0] += max(dp[u][0], dp[u][1]);
		dp[v][1] += dp[u][0];
	}
	dp[v][1] += w[v];
}
int main(){
	while(~scanf("%d%d", &n, &w[1])){
		if(n == 0 && w[1] == 0) break;
		for(int i = 2; i <= n; ++i) scanf("%d", &w[i]);
		for(int i = 1; i < n; ++i){
			vis[i] = 0; dp[i][0] = 0; dp[i][1] = 0;
			int l, k; scanf("%d%d", &l, &k);
			g[k].push_back(l);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(vis[i] == 0) dfs(i);
			int tmp = max(dp[i][0], dp[i][1]);
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
