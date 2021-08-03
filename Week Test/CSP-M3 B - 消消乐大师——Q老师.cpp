#include <stdio.h>

const int N = 32;
int a[N][N];
bool b[N][N];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
			b[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(i-1 > 0 && i+1 <= n){
				if(a[i-1][j] == a[i][j] && a[i+1][j] == a[i][j]){
					b[i-1][j] = 1; b[i][j] = 1; b[i+1][j] = 1;
				}
			}
			if(j-1 > 0 && j+1 <= m){
				if(a[i][j-1] == a[i][j] && a[i][j+1] == a[i][j]){
					b[i][j-1] = 1; b[i][j] = 1; b[i][j+1] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m-1; ++j){
			if(b[i][j]) printf("0 ");
			else printf("%d ", a[i][j]);
		}
		if(b[i][m]) printf("0");
		else printf("%d", a[i][m]);
		if(i < n) printf("\n");
	}
	return 0;
}
