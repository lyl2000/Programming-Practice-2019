#include <stdio.h>
#include <string.h>
bool occur[15];
const int N = 20;
char s[N];
int n, k;
bool isOk(){
	for(int j = 0; j < 10; ++j) occur[j] = false;
	int len = strlen(s), cnt = 0;
	for(int j = 0; j < len; ++j){
		if(!occur[s[j]-'0']){
			cnt++; occur[s[j]-'0'] = true;
		}
		if(cnt >= k) return false;
	}
	return true;
}
int main(){
	int ans = 0; scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		if(k > 10) ans++;
		if(isOk()) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
