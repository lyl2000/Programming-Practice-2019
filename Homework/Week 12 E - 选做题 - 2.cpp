#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 33000;
const int inf = 1e9;
// 状压DP
int dp[N], sum[N], pre[N];  // 2^15  所有状态 
// dp[s]:完成s作业集合后被扣除的最少分数 
struct Work{
	string s;
	int d, c;
	Work(){}
	Work(string _s, int _d, int _c):s(_s), d(_d), c(_c){}
	bool operator < (const Work& w) const {
		return s < w.s;
	}
}work[16];
void output(int s){
	if(s == 0) return;
	output(s^(1<<pre[s]));
	cout << work[pre[s]].s << endl;
} 
int main(){
	int cnt; cin >> cnt;
	while(cnt--){  // cnt组数据 
		int n; cin >> n;  // n个任务 
		for(int i = 0; i < n; ++i){
			cin >> work[i].s >> work[i].d >> work[i].c;
		}
		sort(work, work+n);  // 按名称字典序排序
		int m = (1<<n)-1;
		for(int i = 0; i <= m; ++i){  // 初始化 
			dp[i] = inf; sum[i] = 0; pre[i] = -1;
		}
		dp[0] = 0;
		for(int s = 0; s <= m; ++s){
			for(int i = 0; i < n; ++i){
				int j = (1<<i);
				if(!(s&j)){  // s对应位置为0 
					int t = max(sum[s]+work[i].c-work[i].d, 0);  // 转移后所需总时间 
					if(dp[s|j] > dp[s] + t){  // 可以更优 
						dp[s|j] = dp[s] + t;
						pre[s|j] = i;  // 记录路径
						sum[s|j] = sum[s] + work[i].c;  // 更新总时间 
					}
				}
			}
		}
		cout << dp[m] << endl;
		output(m);
	}
	return 0;
}
