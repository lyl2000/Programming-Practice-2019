#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4010;
int a[N], b[N], c[N], d[N];
int ab[N*N];

int find_index(int num, int len, bool last){
//找num在ab[0,len)数组中第一次或最后一次last出现的位置 
	int l = 0, r = len-1, ans = -1;  //找不到返回-1 
	while(l <= r){
		int mid = (l + r) >> 1;
		if(ab[mid] == num){
			ans = mid;
			if(!last) r = mid - 1;
			else l = mid + 1;
		}
		else if(ab[mid] < num) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main(){
	int n, ans = 0; cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			ab[i*n+j] = a[i] + b[j];
			
	sort(ab, ab+n*n);
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int last = find_index(-(c[i]+d[j]), n*n, 1);
			if(last != -1) ans += last-find_index(-(c[i]+d[j]), n*n, 0)+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
