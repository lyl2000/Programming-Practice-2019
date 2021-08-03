#include <stdio.h>

int main() {
	int n, a, b, ans = 1; scanf("%d%d", &n, &a);
	for(int i = 1; i < n; ++i){
		scanf("%d", &b);
		if(a != b) ans++;
		a = b;
	}
	printf("%d\n", ans);
	return 0;
}
