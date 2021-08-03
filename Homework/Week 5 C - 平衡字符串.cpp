#include <iostream>
#include <string>
#include <map>
using namespace std;

const int N = 100000+100;
string s;
map<char, int> cnt;

int main(){
	cin >> s;
	int n = s.length(), L = 0, R = 0, ans = n;
	for(int i = 0; i < n; ++i) cnt[s[i]]++;  //计算个数 
	if(!(cnt['Q']==cnt['W']&&cnt['Q']==cnt['E']&&cnt['Q']==cnt['R'])){
		cnt[s[0]]--;
		while(R < n){
//			cout<<cnt['Q']<<' '<<cnt['W']<<' '<<cnt['E']<<' '<<cnt['R']<<endl;
			int M = max(max(cnt['Q'], cnt['W']), max(cnt['E'], cnt['R']));
			int T = R - L + 1;
			int F = T - ((M-cnt['Q'])+(M-cnt['W'])+(M-cnt['E'])+(M-cnt['R']));
//			cout<<"M = "<<M<<" T = "<<T<<" F = "<<F<<endl;
			if(F >= 0 && F % 4 == 0){  //满足条件 
				if(R-L+1 < ans) ans = R-L+1;  //更新 ans
				cnt[s[L++]]++;  //缩短区间 更新 cnt 
			}else cnt[s[++R]]--;  //会不会越界？？ 不会 
		}
	}else ans = 0;
	cout << ans << endl;
	return 0;
}
