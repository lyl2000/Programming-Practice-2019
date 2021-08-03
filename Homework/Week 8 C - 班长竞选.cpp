#include <stdio.h>
#include <vector>
using namespace std;

const int N = 5e3 + 50;
vector<int> E1[N], E2[N], E3[N], cc;  // E2��ͼ E3������ͼ 
int n, vis[N], c[N], dfn[N], SCC[N];
int dcnt, scnt, in[N], vis2[N], sum;

void dfs1(int u){
	vis[u] = 1;
	for(int i = 0, len = E1[u].size(); i < len; ++i){
		int v = E1[u][i];
		if(!vis[v]) dfs1(v);
	}
	dfn[++dcnt] = u;  // ������ ��¼���� ������� 
}

void dfs2(int u){
	c[u] = scnt; SCC[scnt]++;  // ǿ��ͨ�����ڵ��� 
	for(int i = 0, len = E2[u].size(); i < len; ++i){
		int v = E2[u][i];  // ��ͼ
		if(c[v] == 0) dfs2(v); 
	}
}

void dfs3(int u){
	vis2[u] = 1; sum += SCC[u];
	for(int i = 0, len = E3[u].size(); i < len; ++i){
		int v = E3[u][i];
		if(!vis2[v]) dfs3(v);
	}
}

void Kosaraju(){
	dcnt = 0; scnt = 0;  // dfs�������scc���� 
	for(int i = 0; i < n; ++i){
		c[i] = 0; vis[i] = 0;  // ��ʼ�� c: scc��� 
	}
	for(int i = 1; i <= n; ++i) SCC[i] = 0;
	for(int i = 0; i < n; ++i){
		if(!vis[i]) dfs1(i);
	}
	for(int i = n; i >= 1; --i){  // ����� 
		if(!c[dfn[i]]){
			scnt++; dfs2(dfn[i]);
		} 
	}
}

bool incc(int u){
	for(int i = 0, len = cc.size(); i < len; ++i){
		if(c[u] == cc[i]) return true;
	}
	return false;
}

int main(){
	int T; scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int m; scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){  // ��� 0 ~ n-1 
			E1[i].clear(); E2[i].clear(); E3[i].clear();
		}
		for(int i = 1; i <= m; ++i){
			int a, b; scanf("%d%d", &a, &b);
			E1[a].push_back(b); E2[b].push_back(a);
		}
		Kosaraju();  // ȷ��ǿ��ͨ����
		for(int i = 1; i <= scnt; ++i) in[i] = 0;  // ��ʼ�� 
		for(int i = 0; i < n; ++i){  // ���� 
			for(int j = 0, len = E2[i].size(); j < len; ++j){
				if(c[i] == c[E2[i][j]]) continue;
				E3[c[i]].push_back(c[E2[i][j]]);
				in[c[E2[i][j]]]++;  // ��ȼ� 
			}
		}
		int ans = 0, num = 0, temp[N];
		for(int i = 1; i <= scnt; ++i){
			if(in[i] == 0) temp[num++] = i;  // ���Ϊ0��ǿ��ͨ���� 
		}
		cc.clear();
		for(int i = 0; i < num; ++i){
			for(int j = 1; j <= scnt; ++j) vis2[j] = 0;
			sum = 0; dfs3(temp[i]);
			if(sum > ans){
				ans = sum; cc.clear(); cc.push_back(temp[i]);
			}else if(sum == ans) cc.push_back(temp[i]);
		}
		printf("Case %d: %d\n", t, ans-1);
		bool occur = 0;
		for(int i = 0; i < n; ++i){
			if(incc(i)){
				if(!occur){
					printf("%d", i); occur = 1;	
				}else printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
