#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 1e3+20;
struct Point{
	int x, y;
	Point(){}
	Point(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (const Point& p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
}pos[N];
int n; 
ll calcu(int j){
	ll R = 0;
	for(int i = 0; i < n; ++i){
		if(i == j) continue;
		ll r = (1ll)*(pos[j].x-pos[i].x)*(pos[j].x-pos[i].x)+(1ll)*(pos[j].y-pos[i].y)*(pos[j].y-pos[i].y);
		if(r > R) R = r;
	}
	return R;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &pos[i].x, &pos[i].y);
	}
	sort(pos, pos+n);
	int x, y;
	ll R = 1e14;
	for(int i = 0; i < n; ++i){
		ll r = calcu(i);
		if(r < R){
			R = r; x = pos[i].x; y = pos[i].y;
		}
	}
	printf("%.2f %.2f\n%.2f\n", 1.0*x, 1.0*y, 1.0*R);
	return 0;
}
