#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 1e5+50;
int n;
struct Player{
	string s1;  // 名字 
	string s2;  // 牌 
	int pai[5];  // 转化后的牌 
	vector<int> value;  // 一系列比较的值
	int v; 
	void trans(){  // 将手牌字符串转化为整形数组 
		int len = s2.length(), p = 0;
		for(int i = 0; i < len; ++i){
			if(i < len-1 && s2[i+1] == '0'){
				pai[p++] = 10; i++;  //跳过0 
			}else if(s2[i] == 'A') pai[p++] = 1;
			else if(s2[i] == 'J') pai[p++] = 11;
			else if(s2[i] == 'Q') pai[p++] = 12;
			else if(s2[i] == 'K') pai[p++] = 13;
			else pai[p++] = s2[i] - '0';
		}
	}
	void getValue(){  // 计算手牌值 返回手牌属于哪一种情况 
		sort(pai, pai + 5);
		bool r[9];  // 1~8 8种情况 
		map<int, int> mp;  // 牌->数目 
		for(int i = 1; i <= 8; ++i) r[i] = true;
		for(int i = 0; i < 5; ++i){
			if(i == 0 && pai[i] != 1) r[8] = false;  // 排序后首位是A 
			if(i == 1 && pai[i] != 10) r[8] = false;
			if(i > 1 && pai[i] != pai[i-1] + 1) r[8] = false;
			if(i > 0 && pai[i] != pai[i-1] + 1) r[7] = false;
			mp[pai[i]]++;
		}
		int val[5], cnt = 0;
		for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
			val[cnt++] = it->second;
		}
		sort(val, val+cnt, greater<int>());  // 降序排序
		for(int i = 0; i < cnt; ++i){
			if(i == 0 && val[i] < 4) r[6] = false;
			if(i == 0 && val[i] < 3){
				r[5] = false; r[4] = false;	
			}
			if(i > 0 && val[i] < 2) r[5] = false;
			if(i == 0 && val[i] < 2){
				r[3] = false; r[2] = false;
			}
			if(i == 1 && val[i] < 2) r[3] = false;
		}
		int ans = 0;
		for(int i = 8; i >= 1; --i){
			if(r[i]){
				ans = i; break;
			}
		}
		if(ans == 7){
			value.push_back(pai[4]);  // 顺子的最大值 
		}else if(ans == 6){
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 4) value.push_back(it->first);
			}
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 1) value.push_back(it->first);
			}
		}else if(ans == 5){
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 3) value.push_back(it->first);
			}
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 2) value.push_back(it->first);
			}
		}else if(ans == 4){
			int sum = 0;
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 3) value.push_back(it->first);
				if(it->second == 1) sum += it->first;
			}value.push_back(sum);
		}else if(ans == 3){
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 2) value.push_back(it->first);
			}
			sort(value.begin(), value.end(), greater<int>());
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 1) value.push_back(it->first);
			}
		}else if(ans == 2){
			int sum = 0;
			for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if(it->second == 2) value.push_back(it->first);
				if(it->second == 1) sum += it->first;
			}value.push_back(sum);
		}else if(ans == 1){
			int sum = 0;
			for(int i = 0; i < 5; ++i) sum += pai[i];
			value.push_back(sum);
		}
		v = ans;
	}
	void show(){
		cout << s1 <<" "<< s2 << endl;
	}
	bool operator<(const Player& p) const {
		if(v != p.v) return v > p.v;
		for(int i = 0, len = value.size(); i < len; ++i){
			if(value[i] != p.value[i]) return value[i] > p.value[i];
		}
		return s1 < p.s1;
	}
}player[N];

int main(){
	while(cin >> n){
		for(int i = 0; i < n; ++i){
			cin >> player[i].s1;
			cin >> player[i].s2;
			player[i].trans(); player[i].getValue();
		}
		sort(player, player + n);
		for(int i = 0; i < n; ++i){
			cout << player[i].s1 << endl;
		}
	}
	return 0;
}
