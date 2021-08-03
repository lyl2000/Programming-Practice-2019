#include <stdio.h>

const int N = 200000+100;
long long a[N], b[N];

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	scanf("%lld", &a[1]); b[1] = a[1];
	for(int i = 2; i <= n; ++i){  //从1到 n 
		scanf("%lld", &a[i]);
		b[i] = a[i] - a[i-1];  //差分 
	}
	for(int i = 0; i < q; ++i){  //q次操作 
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		b[l] += c;
		b[r+1] -= c;
	}
	a[1] = b[1]; printf("%lld ", a[1]);
	for(int i = 2; i <= n; ++i){
		a[i] = a[i-1] + b[i];
		printf("%lld ", a[i]);
	}
	printf("\n");
	return 0;
}
