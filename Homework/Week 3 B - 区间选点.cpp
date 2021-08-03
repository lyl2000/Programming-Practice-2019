#include <stdio.h>
#include <algorithm>
#define N 100
using namespace std;

struct Interval{
	int a,b;
	Interval(){}
	Interval(int _a,int _b):a(_a),b(_b){}
	bool operator<(const Interval& i){
		return b<i.b;
	}
}interval[N];

int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		interval[i]=Interval(a,b);
	}
	sort(interval,interval+n);
	int ans=1,end=interval[0].b;
	for(int i=1;i<n;i++){
		if(interval[i].a>end){
			ans++;
			end=interval[i].b;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
