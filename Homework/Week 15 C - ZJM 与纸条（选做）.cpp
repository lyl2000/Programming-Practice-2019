#include <stdio.h>
#include <string.h>
const int N = 1e4+50;
const int M = 1e6+50;
/*
���� P�� S�г��ֵĴ���  S:����,P:ģʽ�� 
KMP�㷨 O(n+m) 
next ���鶨��Ϊ��next[i] ��ʾ P[0] ~ P[i] ��һ���Ӵ���
ʹ��ǰk���ַ�ǡ���ں�k���ַ�������k
*/
int nxt[N];
void get_nxt(const char *p, int len){
	// ����nxt����ֵ 
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
		while(j && p[j] != s[i]) j = nxt[j-1];  // ʧ��
		if(p[j] == s[i]) j++;
		if(j == len1){
			ans++;
			j = nxt[j-1];  // ת�Ƶ���һ�� 
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
