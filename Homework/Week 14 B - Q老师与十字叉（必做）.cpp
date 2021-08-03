#include <stdio.h>
const int N = 4e5+20;
const int M = 5e4+20;
char gezi[N];
int hang[M], lie[M];
int main(){
	int q; scanf("%d", &q);
	while(q--){
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) hang[i] = 0;
		for(int j = 1; j <= m; ++j) lie[j] = 0;
		for(int i = 1; i <= n; ++i){
			getchar();
			for(int j = 1; j <= m; ++j){
				scanf("%c", &gezi[i*m+j]);
				if(gezi[i*m+j] == '*'){
					hang[i]++; lie[j]++;
				}
			}
		}
		int ans = 1e9;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				int cost = m-hang[i]+n-lie[j];
				if(gezi[i*m+j] == '.') cost--;
				if(cost < ans) ans = cost;
				if(cost == 0) break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
