#include <stdio.h>
#include <algorithm>
#define N 25000
using namespace std;

struct Interval{
	int a,b;
	Interval(){}
	Interval(int _a,int _b):a(_a),b(_b){}
	bool operator<(const Interval& i) const{
		if(a!=i.a) return a<i.a;
		return b>i.b;
	}
}interval[N];

int f(int start,int end,int num){
	int ans=-1,min=-1;
	for(int i=start;i<end;i++){
		if(interval[i].a<=num+1&&interval[i].b>=num+1){
			if(interval[i].b-num-1>min){
				min=interval[i].b-num-1;
				ans=i;
			}
		}else if(interval[i].a>num+1) break;
	}
	return ans;
}

int main(){
	int n,t;
	while(~scanf("%d %d",&n,&t)){
		int cnt=0,a,b;
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
//			if(a<=1&&b>=1&&b<=t) interval[cnt++]=Interval(1,b);
//			else if(b>t&&a>=1&&a<=t) interval[cnt++]=Interval(a,t);
//			else if(a>=1&&b<=t) interval[cnt++]=Interval(a,b);
//			else if(a<1&&b>t) interval[cnt++]=Interval(1,t);
			if(a<=t&&b>=1) interval[cnt++]=Interval(a,b);
		}
		sort(interval,interval+cnt);
		int ans=0,index=0,end=0;
		while(end<t){
			index=f(index,cnt,end);
			if(index==-1){  //没找到，断了 
				ans=-1;
				break;
			}
			ans++;  //找到，结果+1 
			end=interval[index].b;  //更新end 
		}
		printf("%d\n",ans);
	}
	return 0;
}
