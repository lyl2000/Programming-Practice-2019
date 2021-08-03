#include <stdio.h>

const int N = 500+5;
bool TT[N][N];

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, m, ans = 0; scanf("%d %d", &n, &m);
		
		for(int i = 0; i < m; ++i){
			int a, b; scanf("%d %d", &a, &b);
			TT[a][b] = 1;
		}
		
		for(int k = 1; k <= n; ++k){
			for(int i = 1; i <= n; ++i){
				if(TT[i][k]){
					for(int j = 1; j <= n; ++j){
						TT[i][j] = TT[i][j] | TT[i][k]&TT[k][j];
					}
				}
			}
		}
		
		for(int i = 1; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(!TT[i][j]&&!TT[j][i]) ans++; 
				TT[i][j] = 0; TT[j][i] = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
