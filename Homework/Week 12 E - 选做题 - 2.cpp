#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 33000;
const int inf = 1e9;
// ״ѹDP
int dp[N], sum[N], pre[N];  // 2^15  ����״̬ 
// dp[s]:���s��ҵ���Ϻ󱻿۳������ٷ��� 
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
	while(cnt--){  // cnt������ 
		int n; cin >> n;  // n������ 
		for(int i = 0; i < n; ++i){
			cin >> work[i].s >> work[i].d >> work[i].c;
		}
		sort(work, work+n);  // �������ֵ�������
		int m = (1<<n)-1;
		for(int i = 0; i <= m; ++i){  // ��ʼ�� 
			dp[i] = inf; sum[i] = 0; pre[i] = -1;
		}
		dp[0] = 0;
		for(int s = 0; s <= m; ++s){
			for(int i = 0; i < n; ++i){
				int j = (1<<i);
				if(!(s&j)){  // s��Ӧλ��Ϊ0 
					int t = max(sum[s]+work[i].c-work[i].d, 0);  // ת�ƺ�������ʱ�� 
					if(dp[s|j] > dp[s] + t){  // ���Ը��� 
						dp[s|j] = dp[s] + t;
						pre[s|j] = i;  // ��¼·��
						sum[s|j] = sum[s] + work[i].c;  // ������ʱ�� 
					}
				}
			}
		}
		cout << dp[m] << endl;
		output(m);
	}
	return 0;
}
