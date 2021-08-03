#include <iostream>
using namespace std;
const int N=100005;
int a[N];
int main(){
	int n,cnt=0,res=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			if(cnt) res=0;
		}else{
			if(cnt){
				a[i]-=cnt;
				cnt=0;
			}
			if(a[i]%2){
				cnt++;
			}
		}
	}
	if(cnt) res=0;
	cout<<(res?"YES":"NO")<<endl;
	return 0;
}
