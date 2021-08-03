#include <stdio.h>
/*
DP: a[i]红绿均偶数  b[i]红绿均奇数  c[i]红绿一奇一偶
a[i]  2*a[i-1]+c[i-1]            2 0 1    a[i-1] a[1] = 2
b[i]  2*b[i-1]+c[i-1]            0 2 1    b[i-1] b[1] = 0
c[i]  2*a[i-1]+2*b[i-1]+2*c[i-1] 2 2 2    c[i-1] c[1] = 2
*/
const int sz = 3;
struct Matrix{
	int b[sz+2][sz+2];
	Matrix(){
		b[0][0] = 2; b[0][1] = 0; b[0][2] = 1;
		b[1][0] = 0; b[1][1] = 2; b[1][2] = 1;
		b[2][0] = 2; b[2][1] = 2; b[2][2] = 2;
	}
	Matrix operator*(const Matrix& m){
		Matrix mat;
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j){
				mat.b[i][j] = 0;
				for(int k = 0; k < sz; ++k){
					mat.b[i][j] += (b[i][k]*m.b[k][j]);
				}
			}
		}
		return mat;
	}
	Matrix operator%(int m){
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j){
				b[i][j] %= m;
			}
		}
		return *this;
	}
	void output(){
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j){
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
	}
};
Matrix quick_pow(Matrix m, int x, int mod){
	Matrix mat;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(i == j) mat.b[i][j] = 1;
			else mat.b[i][j] = 0;
		}
	}
	while(x){
		if(x & 1) mat = mat * m % mod;
		m = m * m % mod;
		x >>= 1;
	}
	return mat;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int mod = 10007;
		Matrix m;
		if(n == 1) printf("%d\n", 2 % mod);
		else{
			Matrix mat = quick_pow(m, n-1, mod);
			int ans = mat.b[0][0]*2%mod+mat.b[0][2]*2%mod;
			printf("%d\n", ans % mod);
		}
	}
	return 0;
}
