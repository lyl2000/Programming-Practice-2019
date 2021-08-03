#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 1e6+50;
const int inf = 1e9;
int a[N];
int dp[N], Max[N];
/*
״̬��dp[i][j] ǰi���� ѡ����j������ ��a[i]��������j ������ 
ת�ƣ�dp[i][j] = max(dp[i-1][j]+a[i], dp[k][j-1]+a[i]), j-1<=k<=i-1
�������飺dp[i] = max(dp[i-1]+a[i], Max[i-1]+a[i])
Max[]  dp[k][j-1] j-1<=k<=i-1
*/
int main(){
	int m, n; 
	while(~scanf("%d%d", &m, &n)){
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		dp[0] = 0; int temp;
		for(int i = 0; i <= n; ++i) Max[i] = 0;  // ��ʼΪ0 
		for(int j = 1; j <= m; ++j){
			temp = -inf;
			for(int i = j; i <= n; ++i){
				dp[i] = max(dp[i-1]+a[i], Max[i-1]+a[i]);
				Max[i-1] = temp;  // ����Ϊ��һ������ 
				temp = max(temp, dp[i]);
//				printf("%d %d temp = %d\n", j, i, temp);
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}
