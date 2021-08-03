#include <stdio.h>

const int N = 1e5+50;
int n, a[N];

int getLen(int le, int ri){
	int i = le, j = ri;
	if(a[le] == a[ri]) return 0;
	while(i >= 0 && j < n && a[i] == a[le] && a[j] == a[ri]){
		i--; j++;
	}
	return j - i - 1;
}

int main(){
	int ans = 0; scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n-1; ++i){
		int len = getLen(i, i+1);
		if(len > ans) ans = len;
	}
	printf("%d\n", ans);
	return 0;
}
