#include <stdio.h>
#include <string.h>
const int N = 1050;
int main(){
	char s[N]; scanf("%s", s);
	int sz = strlen(s);
	int ans = 0;
	for(int i = 0; i < sz; ++i){
		ans += s[i]-'0';
	}
	while(ans >= 10){
		int temp = ans; ans = 0;
		while(temp){
			ans += (temp % 10);
			temp /= 10;
		}
	}
	printf("%d\n", ans);
	return 0;
}
