#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 100+50;
int a[N];

int main(){
	int x, y; scanf("%d%d", &x, &y);
	int mx = 0, mn, len = 1, isBreak = 0;
	for(int i = 0; i < x; ++i){
		scanf("%d", &a[i]);
		if(a[i] > mx) mx = a[i];
	}
	mx += y;
	sort(a, a+x);
	for(int i = 1; i < x; ++i){
		int h = a[i] - a[i-1];
		y -= h * (len++);
		if(y < 0){
			isBreak = 1; break;	
		}
	}
	mn = isBreak ? a[x-1] : a[x-1]+y/x+(y%x?1:0);
	printf("%d %d\n", mn, mx);
	return 0;
}
