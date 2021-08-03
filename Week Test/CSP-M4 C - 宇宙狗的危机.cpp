#include <stdio.h>
const int N = 7e2+20;
int a[N], gcd_value[N][N];
bool le[N][N], ri[N][N], dp[N][N];
/*
区间dp  dp[i][j]  [i, j]是否满足
左右子树必须划分出来 le[i][j] ri[i][j]
小区间到大区间 dp[i][j] 左 gcd[i-1][k] 右 gcd[k][j+1] i<=k<=j
*/
int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b); }
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				gcd_value[i][j] = gcd(a[i], a[j]);
				gcd_value[j][i] = gcd_value[i][j];
				le[i][j] = 0; ri[i][j] = 0; dp[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i){
			le[i][i] = 1; ri[i][i] = 1;
		}
		for(int len = 1; len <= n; ++len){  // 区间大小 
			for(int i = 0; i <= n-len+1; ++i){
				int j = i+len-1;
				for(int k = i; k <= j; ++k){
					if(le[i][k] && ri[k][j]){
						dp[i][j] = 1;
						if(i > 0 && gcd_value[i-1][k] > 1)
							ri[i-1][j] = 1;
						if(j < n-1 && gcd_value[k][j+1] > 1)
							le[i][j+1] = 1; 
					}
				}
			}
		}
		if(dp[0][n-1]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
