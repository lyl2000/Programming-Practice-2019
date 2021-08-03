#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int M = 25, N = 1e4+50;
int f[N], a[M], b[M][N];
vector<int> v;

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 1; i <= m; ++i) scanf("%d", &a[i]);
		for(int i = 0; i <= n; ++i) f[i] = 0;
		for(int i = 1; i <= m; ++i)
			for(int j = 0; j <= n; ++j)
				b[i][j] = 0;
		v.clear();
		
		for(int i = 1; i <= m; ++i){
			for(int j = n; j >= 0; j--){
				if(j - a[i] >= 0){
					if(f[j-a[i]]+a[i] > f[j]){
						f[j] = f[j-a[i]]+a[i];
						b[i][j] = 1;
					}
				}
			}
		}
		// »ØËÝ 
		for(int i = m, j = n; i >= 1 && j > 0; i--){
			if(b[i][j]){
//				printf("%d ", a[i]);
				v.push_back(a[i]);
				j -= a[i];
			}
		}
		for(int i = v.size()-1; i >= 0; i--) printf("%d ", v[i]);
		printf("sum:%d\n", f[n]);
	}
	return 0;
}
