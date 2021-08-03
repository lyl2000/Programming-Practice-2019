#include <stdio.h>
const int N = 1e5+20;
int a[N];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int aa; scanf("%d", &aa);
		a[aa] = i;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
} 
