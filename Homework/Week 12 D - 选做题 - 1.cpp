#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 150;
char s[N];
int dp[N][N];
/*
dp[i, j]  [i, j] 区间内的最长子序列长度
dp[i, j] = dp[i+1, j-1]+2 if s[i]?s[j]  ()[]
		   dp[i, j-1]
		   dp[i+1, j]
		   dp[i, k] + dp[k+1, j]  i<=k<=j-1
*/
int main(){
	while(scanf("%s", s)){
		if(!strcmp(s, "end")) break;
		int len = strlen(s);
		for(int i = 0; i < len; ++i) dp[i][i] = 0;
//		for(int i = 0; i < len-1; ++i) dp[i][i+1] = 0;
		for(int sz = 2; sz <= len; ++sz){
			for(int i = 0; i < len-sz+1; ++i){
				int l = i, r = i+sz-1; dp[l][r] = 0;

				if(s[l]=='('&&s[r]==')'||s[l]=='['&&s[r]==']'){
					if(l+1<=r-1) dp[l][r] = max(dp[l][r], dp[l+1][r-1] + 2);
					else dp[l][r] = max(dp[l][r], 2);
				}
				dp[l][r] = max(dp[l][r], max(dp[l][r-1], dp[l+1][r]));
				for(int k = l; k <= r-1; ++k){
					dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]);
				}
//				printf("%d %d %d\n", l, r, dp[l][r]);		
			}
		}
		printf("%d\n", dp[0][len-1]);
	}
	return 0;
}
