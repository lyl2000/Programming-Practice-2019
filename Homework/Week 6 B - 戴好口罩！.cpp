#include <stdio.h>

const int N = 3e4 + 5;
int stu[N], rank[N];

int find(int x){ return stu[x] == x ? x : stu[x] = find(stu[x]); }
bool unite(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	if(rank[x] > rank[y]){
		stu[y] = x; rank[x] = (rank[y] += rank[x]);
	}else{
		stu[x] = y; rank[y] = (rank[x] += rank[y]);
	}return true;
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m)){
		if(n == 0 && m == 0) break;
		
		for(int i = 0; i < n; ++i){
			stu[i] = i; rank[i] = 1;
		}
		
		int num, index0, index, ans = 0;
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &num, &index0);
			for(int j = 1; j < num; ++j){
				scanf("%d", &index);
				unite(index0, index);
			}
		}
		
		for(int i = 0; i < n; ++i){
			if(find(i) == find(0)) ans++;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
