#include <stdio.h>

const int N = 100100;
struct R{
	int index, l, r;
	long long h;
}a[N], stack[N];

int main(){
	int n;
	while(scanf("%d", &n)){
		if(n == 0) break;
		int top = 0;
		long long ans = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lld", &a[i].h);
			a[i].l = 0;
			a[i].r = n-1;
			a[i].index = i;
		}
		for(int i = 0; i < n; ++i){
			while(top > 0 && stack[top].h > a[i].h){
				a[stack[top--].index].r = i-1;
			}
			stack[++top] = a[i];
		}
		top = 0;
		for(int i = n-1; i >= 0; --i){
			while(top > 0 && stack[top].h > a[i].h){
				a[stack[top--].index].l = i+1;
			}
			stack[++top] = a[i];
		}
		for(int i = 0; i < n; ++i){
//			printf("%d %d\n", a[i].l, a[i].r);
			long long v = a[i].h*(a[i].r-a[i].l+1);
			if(v > ans) ans = v;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
