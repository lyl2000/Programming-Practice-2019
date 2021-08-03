#include <stdio.h>
const int N = 5050;
int main(){
	int n, m; scanf("%d%d", &n, &m);
	bool d[N];
	for(int i = 1; i <= n; ++i) d[i] = 0;
	for(int i = 2; i <= m; ++i){
		for(int j = i; j <= n; j += i){
			d[j] = !d[j];
		}
	}
	bool dh = 0;
	for(int i = 1; i <= n; ++i){
		if(!d[i]){
			if(!dh){
				printf("%d", i);
				dh = !dh;
			}else{
				printf(",%d", i);
			}
		}
	}
	printf("\n");
	return 0;
}
