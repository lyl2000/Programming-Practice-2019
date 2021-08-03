#include <iostream>
#include <map>
using namespace std;
struct Point{
	int x, y;
	Point(int _x, int _y):x(_x), y(_y){}
	bool operator<(const Point& p) const{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
};
struct Line{
	int x, y, d, len;
	Line(int _x, int _y, int _d, int _len)
		:x(_x), y(_y), d(_d), len(_len){}
	bool operator<(const Line& l) const{
		if(x!=l.x) return x<l.x;
		if(y!=l.y) return y<l.y;
		if(d!=l.d) return d<l.d;
		return len<l.len;
	}
};
const int N = 35;
int a[N], ans=0, n;
map<Point, bool> isFound;
map<Line, bool> isSame;
const int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
const int next_dir[8][2]={{1,7},{2,0},{3,1},{4,2},{5,3},{6,4},{7,5},{0,6}};

void dfs(int x, int y, int d, int len){
	if(len==n) return;
	if(isSame[Line(x, y, d, len)]) return;
	isSame[Line(x, y, d, len)]=1;
	int dx=dir[d][0], dy=dir[d][1];
	for(int i=0; i<a[len]; ++i){
		x+=dx; y+=dy;
		if(!isFound[Point(x, y)]){
			isFound[Point(x, y)]=1;
			ans++;
		}
	}
	dfs(x, y, next_dir[d][0], len+1);
	dfs(x, y, next_dir[d][1], len+1);
}

int main(){
	cin>>n;
	for(int i=0; i<n; ++i) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
