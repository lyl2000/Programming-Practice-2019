#include <stdio.h>
#define ll long long
int n;
ll k;
ll f(ll num){
	int le = 0, ri = n;
	ll ans = 0;
	while(le <= ri){
		int mid = (le + ri) / 2;
		if((long long)(1+mid)*mid/2 < num){
			ans = mid;
			le = mid + 1;
		}else{
			ri = mid - 1;
		}
	}
	return ans;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		ll n1 = f(k);
		ll n2 = k - (1+n1)*n1/2;
//		printf("%d %d\n", n1, n2);
		for(int i = 0; i < n; ++i){
			if(i+n1+2 == n || i+n2 == n) printf("b");
			else printf("a");
		}
		printf("\n");
	}
	return 0;
}
