#include <stdio.h>
const int N = 120;
int a[N], b[N];
int ab(int A, int B){
	if(A == 0){
		if(B == 0) return 0;
		else if(B == 2) return 1;
		else if(B == 5) return -1;
	}else if(A == 2){
		if(B == 0) return -1;
		else if(B == 2) return 0;
		else if(B == 5) return 1;
	}else if(A == 5){
		if(B == 0) return 1;
		else if(B == 2) return -1;
		else if(B == 5) return 0;
	}
}
int main(){
	int n, na, nb;
	scanf("%d%d%d", &n, &na, &nb);
	for(int i = 0; i < na; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < nb; ++i) scanf("%d", &b[i]);
	int A = 0, B = 0;
	for(int i = 0; i < n; ++i){
		int c = ab(a[i % na], b[i % nb]);
		if(c > 0) A++;
		else if(c < 0) B++;
	}
	if(A > B) printf("A\n");
	else if(A == B) printf("draw\n");
	else printf("B\n");
	return 0;
}
