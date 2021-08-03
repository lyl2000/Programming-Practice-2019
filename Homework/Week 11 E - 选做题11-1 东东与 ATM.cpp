#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e6+50;

int f[N], w[15], c[15], ww[150];

int main(){
	int cash, n;
	while(~scanf("%d%d", &cash, &n)){
		for(int i = 1; i <= n; ++i){
			scanf("%d%d", &c[i], &w[i]);
		}
		for(int i = 0; i < N; ++i) f[i] = 0;
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			int t = c[i];
			for(int k = 1; k <= t; k <<= 1){
				cnt++;
				ww[cnt] = k * w[i];
				t -= k;
			}
			if(t > 0){
				cnt++;
				ww[cnt] = t * w[i];
			}
		}
		for(int i = 1; i <= cnt; ++i){
			for(int j = cash; j >= 0; j--){
				if(j-ww[i] >= 0)
					f[j] = max(f[j], f[j-ww[i]]+ww[i]);
			}
		}
		printf("%d\n", f[cash]);
	}
	return 0;
}
