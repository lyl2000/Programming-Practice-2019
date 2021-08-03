#include <stdio.h>
/*
f(x)=x  x<10
f(x)      a0 a1 a2 a3 a4 a5 a6 a7 a8 a9  f(x-1)
f(x-1)     1  0  0  0  0  0  0  0  0  0  f(x-2)

       =

f(x-9)     0  0  0  0  0  0  0  0  1  0  f(x-10)
*/
struct Matrix{
	int b[15][15];
	Matrix(){}
	Matrix(int *c){
		for(int i = 0; i < 10; ++i){
			b[0][i] = c[i];
		}
		for(int i = 1; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				if(i-1 == j) b[i][j] = 1;
				else b[i][j] = 0;
			}
		}
	}
	Matrix operator*(const Matrix& m){
		Matrix mat;
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				mat.b[i][j] = 0;
				for(int k = 0; k < 10; ++k){
					mat.b[i][j] += (b[i][k]*m.b[k][j]);
				}
			}
		}
		return mat;
	}
	Matrix operator%(int m){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				b[i][j] %= m;
			}
		}
		return *this;
	}
	void output(){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
	}
};
Matrix quick_pow(Matrix m, int x, int mod){
	Matrix mat;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
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
int a[15];
int main(){
	int k, m;
	while(~scanf("%d%d", &k, &m)){
		for(int i = 0; i < 10; ++i) scanf("%d", &a[i]);
		Matrix mat(a);
//		mat.output();
		if(k < 10) printf("%d\n", k % m);
		else{
			Matrix d = quick_pow(mat, k-9, m);
//			d.output();
			int ans = 0;
			for(int i = 0; i < 10; ++i){
				ans += d.b[0][i]*(9-i);
			}
			printf("%d\n", ans % m);
		}
	}
	return 0;
}
