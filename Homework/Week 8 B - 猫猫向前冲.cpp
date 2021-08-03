#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 5e2+5;
vector<int> E[N];
int n, in[N], ans[N], cnt;
priority_queue<int> q;  // ����� 

void toposort(){
	while(!q.empty()) q.pop();  // ��ʼ�� 
	for(int i = 1; i <= n; ++i){
		if(in[i] == 0) q.push(-i);  // ȡ���� ��С���� 
	}
	cnt = 0;
	while(!q.empty()){
		int u = -q.top(); q.pop();
		ans[cnt++] = u;  // �ŵ����������
		for(int i = 0, len = E[u].size(); i < len; ++i){
			int v = E[u][i]; --in[v];
			if(in[v] == 0) q.push(-v);
		} 
	}
}

int main(){
	int m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 1; i <= n; ++i){
			in[i] = 0; E[i].clear();  // ��ʼ�� 
		}
		for(int i = 1; i <= m; ++i){
			int p1, p2; scanf("%d%d", &p1, &p2);
			E[p1].push_back(p2);
			in[p2]++;  // ��ȼ� 
		}
		toposort();
		if(cnt == n){
			for(int i = 0; i < cnt-1; ++i)
				printf("%d ", ans[i]);
			printf("%d\n", ans[cnt-1]);
		}
	}
	return 0;
}
