#include <stdio.h>
#include <queue>
using namespace std;

const int N = 35;
char m[N][N][N];
bool isF[N][N][N];  // 是否走过 
struct Unit{
	int l, r, c, t;
	Unit(){}
	Unit(int _l, int _r, int _c, int _t):l(_l), r(_r), c(_c), t(_t){}
	bool operator < (const Unit& u) const {
		if(l != u.l) return l < u.l;
		if(r != u.r) return r < u.r;
		return c < u.c;
	}
}s, e;
queue<Unit> q;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};
int l, r, c;
// BFS 
int findPath(Unit s){
	q.push(s); isF[s.l][s.r][s.c] = true;
	while(!q.empty()){
		Unit cur = q.front(); q.pop();
		for(int i = 0; i < 6; ++i){
			int x = cur.l+dx[i], y = cur.r+dy[i], z = cur.c+dz[i];
			Unit tmp(x, y, z, cur.t + 1);
			if(x >= 0 && x < l && y >= 0 && y < r && z >= 0 && z < c && !isF[x][y][z]){
				if(m[x][y][z] == 'E') return cur.t + 1;
				if(m[x][y][z] == '.'){
					q.push(tmp);
				}
				isF[x][y][z] = true;
			}
		}
	}
	
	return -1;  // 没有路径 
}

int main(){
	while(scanf("%d%d%d", &l, &r, &c)){
		if(l == 0 && r == 0 && c == 0) break;
		while(!q.empty()) q.pop();  // 初始化
		getchar();
		for(int i = 0; i < l; ++i){
			for(int j = 0; j < r; ++j){
				for(int k = 0; k < c; ++k){
					scanf("%c", &m[i][j][k]);
					isF[i][j][k] = false;
					if(m[i][j][k] == 'S') s = Unit(i, j, k, 0);
				}
				getchar();
			}
			getchar();
		}
		
		int ans = findPath(s);
		if(ans == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}

/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

*/
