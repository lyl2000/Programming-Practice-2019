#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 5000+50;
int a[N], b[N], dp[N], f[N][N], n, m;

int find_num(int index){
	int ans = 0;
	for(int i = 1; i < index; ++i){
		if(a[i] < a[index]){  // ÑÏ¸ñµİÔö 
			if(dp[i] > ans) ans = dp[i];
		}
	}
	return ans;
}

int LIS(){
	int ans = 1; dp[1] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i] = find_num(i) + 1;
		if(dp[i] > ans) ans = dp[i];
	}
	return ans;
}

int LCS(){
	for(int i = 0; i <= n; ++i) f[i][0] = 0;
	for(int j = 0; j <= m; ++j) f[0][j] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	}
	return f[n][m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	printf("%d %d\n", LIS(), LCS());
	return 0;
}
