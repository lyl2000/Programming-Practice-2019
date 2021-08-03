#include <stdio.h>
const int N = 2e5+20;
char a[N];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", a);
	int p = n-1;
	for(int i = 1; i < n; ++i){
		if(a[i-1] > a[i]){
			p = i-1; break;
		}else if(a[i-1] == a[i] && a[i-1] > a[p]){
			p = i-1;
		}
	}
	for(int i = 0; i < p; ++i) printf("%c", a[i]);
	for(int i = p+1; i < n; ++i) printf("%c", a[i]);
	printf("\n");
	return 0;
}
