#include <stdio.h>
int main(){
	int n, d; scanf("%d%d", &n, &d);
	int ans = 0, time = 1e6;
	for(int i = 1; i <= n; ++i){
		int a, b; scanf("%d%d", &a, &b);
		if(a == d){
			ans = i; time = d;
		}
		else if(a > d){
			if(a < time){
				ans = i; time = a;
			}
		}else{
			int t = (d-a) % b;
			if(t == 0){
				ans = i; time = d;
			}else{
				t = a + ((d-a) / b + 1) * b;
				if(t < time){
					ans = i; time = t;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
