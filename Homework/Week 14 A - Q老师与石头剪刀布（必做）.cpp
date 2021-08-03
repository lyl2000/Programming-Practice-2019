#include <stdio.h>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;
map<char, int> zh, cnt;
char seq[120];
int main(){
	int t; scanf("%d", &t);
	while(t--){
		zh.clear();
		int n; scanf("%d", &n);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		getchar();
		for(int i = 0; i < n; ++i){
			scanf("%c", &seq[i]);
			zh[seq[i]]++;
		}
		int ans = 0;
		int _a = 0, _b = 0, _c = 0;
//		printf("a=%d, b=%d, c=%d, aa=%d, bb=%d, cc=%d\n", a, b, c, zh['R'], zh['P'], zh['S']);
		if(a <= zh['S']){
			ans += a;
		}else{
			ans += zh['S']; _a = a - zh['S'];
		}
		if(b <= zh['R']){
			ans += b;
		}else{
			ans += zh['R']; _b = b - zh['R'];
		}
		if(c <= zh['P']){
			ans += c;
		}else{
			ans += zh['P']; _c = c - zh['P'];
		}
		if(n%2==1 && ans<=n/2 || n%2==0 && ans<n/2) printf("NO\n");
		else{
			printf("YES\n");  // ÄÜÓ® 
			for(int i = 0; i < n; ++i){
				if(seq[i] == 'R'){
					if(b > 0){
						b--; printf("P");
					}else{
						if(_a > 0){
							_a--; printf("R");
						}else if(_c > 0){
							_c--; printf("S");
						}
					}
				}
				if(seq[i] == 'P'){
					if(c > 0){
						c--; printf("S");
					}else{
						if(_a > 0){
							_a--; printf("R");
						}else if(_b > 0){
							_b--; printf("P");
						}
					}
				}
				if(seq[i] == 'S'){
					if(a > 0){
						a--; printf("R");
					}else{
						if(_b > 0){
							_b--; printf("P");
						}else if(_c  > 0){
							_c--; printf("S");
						}
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
