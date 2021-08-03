#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
/*
DP:dp[i][j]  max(dp[i-1][k]+f[k][j])  N*M*M  1e9
dp[2][i] = max(f[k][i])
dp[i][1]  f[1][1]  f[2][1]     f[M][1]   dp[i-1][1]


dp[i][M]  f[1][M]  f[2][M]     f[M][M]   dp[i-1][M]
*/
const int M = 1e2+20;
const int N = 1e5+20;
ll f[M][M], dp2[M], dpn[M];
int n, m;
struct Matrix{
	ll a[M][M];
	Matrix(){
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= m; ++j){
				a[i][j] = f[j][i];
			}
		}	
	}
	Matrix operator*(const Matrix& mat){
		Matrix ans;
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= m; ++j){
				ans.a[i][j] = 0;
				for(int k = 1; k <= m; ++k){
					ans.a[i][j] = max(ans.a[i][j], a[i][k]+mat.a[k][j]);
				}
			}
		}
		return ans;
	}
	void output(){
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= m; ++j){
				printf("%lld ", a[i][j]);
			}
			printf("\n");
		}
	}
};
Matrix quick_pow(Matrix mat, int x){
	Matrix ans;
	bool f = 1;
	while(x){
		if(x & 1){
			if(f){
				ans = mat; f = 0;
			}
			else ans = ans * mat;
		}
		mat = mat * mat;
		x >>= 1;
	}
	return ans;
}
int main(){
	while(~scanf("%d%d", &n, &m)){
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%lld", &f[i][j]);
		for(int j = 1; j <= m; ++j){
			dp2[j] = 0;
			for(int i = 1; i <= m; ++i){
				if(f[j][i] > dp2[j]) dp2[j] = f[j][i];
			}
		}
		Matrix mat;
		ll ans = 0;
		if(n == 2){
			for(int i = 1; i <= m; ++i){
				if(dp2[i] > ans) ans = dp2[i];
			}
			printf("%lld\n", ans);
		}else{
			Matrix b = quick_pow(mat, n-2);
//			b.output();
			for(int i = 1; i <= m; ++i){
				dpn[i] = 0;
				for(int j = 1; j <= m; ++j){
					dpn[i] = max(dpn[i], b.a[j][i]+dp2[j]);
				}
			}
			for(int i = 1; i <= m; ++i){
				ans = max(ans, dpn[i]);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
