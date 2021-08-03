#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1010;
bool b[N];
struct DDL{
	int d,p;  //���� ���� 
	bool operator<(const DDL& ddl){
		if(p!=ddl.p) return p>ddl.p;
		return d<ddl.d;
	}
}a[N];

int main(){
	int t; cin>>t;
	while(t--){
		int n, ans = 0; cin>>n;
		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; ++i) cin>>a[i].d;
		for(int i = 0; i < n; ++i) cin>>a[i].p;
		sort(a, a+n);
		for(int i = 0; i < n; ++i){
			int day = a[i].d;
			bool done = 0;
			while(day > 0){  //0���� 
				if(!b[day]){  //�Ž���һ�� 
					b[day] = 1;
					done = 1;
					break;
				}
				day--;
			}
			if(!done) ans += a[i].p;  //û����� 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
