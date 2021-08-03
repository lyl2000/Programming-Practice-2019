#include <list>
#include <stdio.h>
using namespace std;
#define N 16
#define rep(i,s,t) for(int i=s;i<=t;i++)

list<int> nums;
int num[N],ans;

void backtrack(int start,int n,int k,int s){
	if(nums.size()==k&&s==0){
		ans++;
		return;
	}else if(nums.size()>k||s<0||start>=n){
		return;
	}else{
		rep(i,start,n-1){
			nums.push_back(num[i]);
			backtrack(i+1,n,k,s-num[i]);
			nums.pop_back();
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,s;
		while(!nums.empty()) nums.pop_back();
		ans=0;
		scanf("%d %d %d",&n,&k,&s);
		rep(i,0,n-1){
			scanf("%d",&num[i]);
		}
		backtrack(0,n,k,s);
		printf("%d\n",ans);
	}
	return 0;
}
