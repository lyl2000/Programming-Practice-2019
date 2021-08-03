#include <stdio.h>
#include <math.h>
int main(){
	int n; scanf("%d", &n);
	double ans = 0;
	for(int i = 1; i <= n; ++i){
		double x, y; int r;
		scanf("%lf%lf%d", &x, &y, &r);
		ans += 2.0 * sqrt(x*x+y*y) / 50 + 1.5 * r;
//		printf("%lf\n", ans);
	}
	printf("%d\n", int(ceil(ans)));
	return 0;
}
