#include <stdio.h>
#include <map>
using namespace std;
map<int, int> m;
// 1e7 O(n)
int main(){
	int n; 
	while(~scanf("%d", &n)){
		m.clear();
		int ans, b = (n + 1) / 2;
		for(int i = 0; i < n; ++i){
			int a; scanf("%d", &a);
			if(++m[a] >= b) ans = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
