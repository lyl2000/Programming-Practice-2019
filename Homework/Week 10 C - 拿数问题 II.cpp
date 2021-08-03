#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long

const int N = 1e5+50;
ll a[N], b[N];
ll dp[N], max_num = 0;

int main(){
	int n; scanf("%d", &n);
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		if (max_num < a[i]) max_num = a[i];
		b[a[i]] += a[i]; 
	}
	dp[0] = 0; dp[1] = b[1];
	for(int i = 2; i <= max_num; ++i){
		dp[i] = max(dp[i-1], dp[i-2]+b[i]);
	}
	printf("%lld\n", dp[max_num]);
//	ll ans = 0;
//	int n; scanf("%d", &n);
//	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
//	dp[1] = a[1];
//	for(int i = 2; i <= n; ++i){
//		bool skip = 0;
//		for(int j = i-1; j >= 1; --j){
//			if(a[j] != a[i] - 1 && a[j] != a[i] + 1){
//				dp[i] = dp[j] + a[i]; skip = 1; break;
//			}
//		}
//		if(!skip) dp[i] = a[i];
//	}
//	for(int i = 1; i <= n; ++i){
//		if(dp[i] > ans) ans = dp[i];
//	}
//	printf("%lld\n", ans);
//	return 0;
} 
