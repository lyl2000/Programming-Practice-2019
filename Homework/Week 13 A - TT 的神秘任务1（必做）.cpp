#include <stdio.h>
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, k; scanf("%d%d", &n, &k);
		if(n < k) printf("NO\n");
		else if(n == k){
			printf("YES\n");
			for(int i = 1; i < n; ++i) printf("1 ");
			printf("1\n");
		}else{
			if((n % 2 && k % 2) || (!(n % 2) && !(k % 2))){
				printf("YES\n");
				for(int i = 1; i < k; ++i) printf("1 ");
				printf("%d\n", n-k+1);
			}else if(n % 2 && !(k % 2)){
				printf("NO\n");
			}else{
				if(n <= (k-1)*2) printf("NO\n");
				else{
					printf("YES\n");
					for(int i = 1; i < k; ++i) printf("2 ");
					printf("%d\n", n-(k-1)*2);
				}
				
			}
		}
	}
	return 0;
}
