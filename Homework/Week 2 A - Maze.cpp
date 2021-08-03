#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int n=5;
int a[n][n];
int dis[n][n];
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
};
point b[n][n];
queue<point> Q;
point bfs(){
	Q.push(point(0,0));
	dis[0][0]=0;
	while(!Q.empty()){
		point now=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int x=now.x+dx[i],y=now.y+dy[i];
			if(x>=0&&x<=n-1&&y>=0&&y<=n-1){
				if(dis[x][y]==-1&&!a[x][y]){
					dis[x][y]=dis[now.x][now.y]+1;
					b[x][y]=now;
					Q.push(point(x,y));
				}
			}
		}
	}
	return b[n-1][n-1];
}

void print(point p){
	if(p.x!=0||p.y!=0){
		print(b[p.x][p.y]);
	}
	cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
}
/*
0 1 0 0 0
0 1 0 1 0
0 1 0 1 0
0 0 0 1 0
0 1 0 1 0
*/
int main(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	memset(dis,-1,sizeof(dis));
	point res=bfs();
	print(res);
	cout<<"(4, 4)"<<endl;
	return 0;
} 
