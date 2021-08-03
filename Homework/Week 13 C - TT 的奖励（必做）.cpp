#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5+20;
int cat[12][N], old_dp[12], new_dp[12];
int main(){
	int m;
	while(~scanf("%d", &m)){
		if(m == 0) break;
		for(int i = 0; i <= 10; ++i){
			old_dp[i] = 0; new_dp[i] = 0;
			for(int j = 1; j < N; ++j){
				cat[i][j] = 0;
			}
		}
		int t = 0;
		for(int i = 1; i <= m; ++i){
			int a, b; scanf("%d%d", &a, &b);
			cat[a][b]++;
			if(b > t) t = b;
		}
		for(int j = 1; j <= 5 && j <= t; ++j){
			int le = 5 - j, ri = 5 + j;
			new_dp[le] = old_dp[le+1] + cat[le][j];
			new_dp[ri] = old_dp[ri-1] + cat[ri][j];
			for(int i = le+1; i < ri; ++i){
				new_dp[i] = max(old_dp[i-1], max(old_dp[i], old_dp[i+1])) + cat[i][j];
			}
			for(int i = le; i <= ri; ++i) old_dp[i] = new_dp[i];
		} 
		for(int j = 6; j <= t; ++j){
			new_dp[0] = max(old_dp[0], old_dp[1]) + cat[0][j];
			for(int i = 1; i <= 9; ++i){
				new_dp[i] = max(old_dp[i-1], max(old_dp[i], old_dp[i+1])) + cat[i][j];
			}
			new_dp[10] = max(old_dp[9], old_dp[10]) + cat[10][j];
			for(int i = 0; i <= 10; ++i) old_dp[i] = new_dp[i];
		}
		int max = 0;
		for(int i = 0; i <= 10; ++i){
			if(new_dp[i] > max) max = new_dp[i];
		}
		printf("%d\n", max);
	}
	return 0;
}
