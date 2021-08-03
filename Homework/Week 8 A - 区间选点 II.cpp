#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 5e4+50;
const int inf = 1e8;  // 0x3f3f3f3f
int sum[N];  // b <= 50000  [0,i)�����ڵĵ��� ��Ϊ���� 
struct Edge{
	int v, w;
	Edge(){}
	Edge(int _v, int _w):v(_v), w(_w){}
};
vector<Edge> E[N];
queue<int> inq;
int dis[N], vis[N], n;

void addEdge(int a, int b, int c){
	E[a].push_back(Edge(b, c));
}

void spfa(int s){
	for(int i = 0; i <= n; ++i){
		dis[i] = -inf; vis[i] = 0;  // ��ʼ�� 
	}
	inq.push(s); dis[s] = 0; vis[s] = 1;
	while(!inq.empty()){
		int u = inq.front(); inq.pop(); vis[u] = 0;
		for(int i = 0, len = E[u].size(); i < len; ++i){
			int v = E[u][i].v, w = E[u][i].w;
			if(dis[v] < dis[u] + w){  // �· 
				dis[v] = dis[u] + w;
				if(!vis[v]){
					inq.push(v); vis[v] = 1;  // ��ֹ�ظ� 
				}
			}
		}
	}
}

int main(){
	int m, max_b = 0; scanf("%d", &m);  // m������ 
	for(int i = 1; i <= m; ++i){
		int a, b, c;  //[a,b+1)=[a,b]��������c���� 
		scanf("%d%d%d", &a, &b, &c);
		if(b+1 > max_b) max_b = b+1;  //���� max_b ���� 
		addEdge(a, b+1, c);  // ��ֹ-1���� 
	}
	n = max_b;
	for(int i = 1; i <= n; ++i){
		addEdge(i, i-1, -1); addEdge(i-1, i, 0);
	}
	spfa(0);
//	for(int i = 0; i <= n; ++i){
//		for(int j = 0; j < E[i].size(); ++j)
//			printf("%d %d %d   ", i, E[i][j].v, E[i][j].w);
//		printf("\n");
//	}
	printf("%d\n", dis[max_b]);
	return 0;
}
