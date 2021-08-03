#include <stdio.h>
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, k; scanf("%d%d", &n, &k);
		if(k%(n-1)) printf("%d\n", k/(n-1)*n+k%(n-1));
		else printf("%d\n", k/(n-1)*n+k%(n-1)-1);
	}
	return 0;
}
