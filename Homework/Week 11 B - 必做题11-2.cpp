#include <stdio.h>

const int N = 22;
int n, a[N][N], b[N][N];

void rot(){
	// Ë³Ê±ÕëÐý×ª90¶È
	int m = n / 2;
	for(int i = 0; i < m; ++i){
		for(int j = i; j < n-1-i; ++j){
			int temp = a[i][j];
			a[i][j] = a[n-j-1][i];
			a[n-j-1][i] = a[n-i-1][n-j-1];
			a[n-i-1][n-j-1] = a[j][n-i-1];
			a[j][n-i-1] = temp;
		}
	}
}

bool equal(){
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i][j] != b[i][j]) return false;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &b[i][j]);
	int ans = 0;
	while(1){
		if(equal()){
			printf("%d\n", ans); return 0;
		}else{
			if(ans == 3) break;
			rot(); ans++;
		}
	}
	printf("-1\n");
	return 0;
}
