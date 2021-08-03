#include <stdio.h>
#define max(x, y) x>y?x:y
const int N = 1e5+20;
const int inf = 1e8;
int a[2 * N], sum[2 * N], q[2 * N];
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for(int i = 1; i <= k; ++i) a[n + i] = a[i];  // 变环为链
		sum[0] = 0;
		for(int i = 1; i <= n + k; ++i) sum[i] = sum[i - 1] + a[i];  // 前缀和
		int start = 0, end = 0, le = 0, ri = 0, ans = -inf;
//		q[++end] = 0;
		for(int i = 1; i < n + k; ++i) {
			while(start < end && q[start + 1] < i - k) start++;
			while(start < end && sum[q[end]] > sum[i]) end--;  // 递增队列，队列首始终是最小值
			q[++end] = i;
			if(end - start > 1) {
				if(sum[i] - sum[q[start + 1]] > ans) {
					ans = sum[i] - sum[q[start + 1]];
					le = q[start + 1] + 1; ri = i;
				}
			} else if(end - start == 1) {  // 只有它自己 
				if(sum[i] - sum[i - 1] > ans) {
					ans = sum[i] - sum[i - 1];
					le = i; ri = i;
				}
			}
		}
		printf("%d %d %d\n", ans, le, ri > n ? ri-n : ri);
	}
	return 0;
} 
