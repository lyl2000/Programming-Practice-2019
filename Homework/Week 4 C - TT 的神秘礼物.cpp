#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 100050;
int cat[N], n;

int find_index(int start, int P){
	int l = start+1, r = n-1, ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(cat[mid] <= cat[start]+P){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
} 

int G(int P){
	int ans = 0;
	for(int i = 0; i < n-1; ++i){
		int num = find_index(i, P);
		if(num != -1) ans += (num-i);
	}
	return ans;  //·µ»ØÃû´Î 
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i) scanf("%d", &cat[i]);
		sort(cat, cat+n);
		int ans = -1, l = 0, r = cat[n-1]-cat[0], num = n*(n-1)/2;
		while(l <= r){
			int mid = (l + r) >> 1;
//			cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<" G="<<G(mid)<<endl;
			if(G(mid)<(num+1)/2) l = mid + 1;
			else{
				ans = mid;
				r = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
