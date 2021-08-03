#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1e4+5;
long long a[N];
set<long long> cnt;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		cnt.clear();
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%lld", &a[i]);
			cnt.insert(a[i]);
		}
		if(cnt.size() > 3){
			printf("NO");
		}else{
			if(cnt.size() == 3){
				long long num[3]; int len = 0;
				for(set<long long>::iterator it=cnt.begin(); it!=cnt.end(); it++){
					num[len++] = *it;
				}
				sort(num, num+3);
				if(num[0]+num[2] == 2*num[1]){
					printf("YES");
				}else{
					printf("NO");
				}
			}else{
				printf("YES");
			}
		}
		printf("\n");
	}
	return 0;
} 
