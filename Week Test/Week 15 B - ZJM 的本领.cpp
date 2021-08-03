#include <stdio.h>
const int N = 55;
int L[N], R[N];
int main(){
	int n, x; scanf("%d%d", &n, &x);
	int start = 1, ans = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &L[i], &R[i]);
		if(start + x <= L[i]){  // 可以快进 
			start += (L[i] - start) / x * x;
		}
		ans += R[i] - start + 1;
		start = R[i] + 1;
	}
	printf("%d\n", ans);
	return 0;
}
