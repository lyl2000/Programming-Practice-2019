#include <stdio.h>
#define ll long long 
const int N = 3e5+50;

int main(){
	// ��ȷ�Ľⷨ���Ҳ���delisious���Ӵ�
	int n; scanf("%d", &n);
	char s[N]; scanf("%s", s);
	ll ans = (1ll * n) * (n-1) / 2;  // ���еĿ��ܵ��Ӵ�
	// printf("%d\n", ans);
	// AABBB  ABBAAA 6 
	int p = 0;
	for(int i = 1; i < n; ++i){
		// AB..B BA..A A..AB B..BA
		if(s[i] != s[i-1]){
			ans -= (i - p);
			p = i;
		}
	}
	p = n - 1;
	for(int i = n-2; i >= 0; i--){
		if(s[i] != s[i+1]){
			ans -= (p - i);
			ans++;  // �� AABBB�е�AB������� �ӻ��� 
			p = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
