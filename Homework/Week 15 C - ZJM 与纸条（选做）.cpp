#include <stdio.h>
#include <string.h>
const int N = 1e4+50;
const int M = 1e6+50;
/*
计算 P在 S中出现的次数  S:主串,P:模式串 
KMP算法 O(n+m) 
next 数组定义为：next[i] 表示 P[0] ~ P[i] 这一个子串，
使得前k个字符恰等于后k个字符的最大的k
*/
int nxt[N];
void get_nxt(const char *p, int len){
	// 计算nxt数组值 
	nxt[0] = 0;
	for(int i = 1, j = 0; i < len; ++i){
		while(j && p[i] != p[j]) j = nxt[j-1];
		if(p[i] == p[j]) j++;
		nxt[i] = j;
	}
}
int kmp(const char *p, const char *s){
	int len1 = strlen(p), len2 = strlen(s);
	int j = 0, ans = 0;
	get_nxt(p, len1);
	for(int i = 0; i < len2; ++i){
		while(j && p[j] != s[i]) j = nxt[j-1];  // 失配
		if(p[j] == s[i]) j++;
		if(j == len1){
			ans++;
			j = nxt[j-1];  // 转移到下一个 
		}
	}
	return ans; 
} 
int main(){
	int n; scanf("%d", &n);
	char p[N], s[M];
	while(n--){
		scanf("%s", p); scanf("%s", s);
		printf("%d\n", kmp(p, s));
	}
	return 0;
}
