#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
map<string, string> 会超空间 
把string通过哈希转成数字  空间大大减小 
*/
int seed = 7, mod = 1e9+7;
map<int, string> str1, str2;
int str2int(string str){
	int len = str.size(), ans = 0, sd = seed;
	for(int i = 0; i < len; ++i){
		ans += int(str[len-i-1])*sd % mod;
		sd = sd * seed % mod;
	}
	return ans;
}
int main(){
	string sent, curse, feature;
	while(getline(cin, sent)){
		if(sent == "@END@") break;
		int sz = sent.size(), i = 1;
		for(; i < sz; ++i){
			if(sent[i] == ']') break;
		}
		curse = sent.substr(1, i-1);
		int hash1 = str2int(curse);
//		cout << curse << endl;
		feature = sent.substr(i+2, sz - i-2);
		int hash2 = str2int(feature);
//		cout << feature << endl;
		str1[hash1] = feature;
		str2[hash2] = curse;
	}
	int n; scanf("%d ", &n);
	for(int i = 0; i < n; ++i){
		string test;
		int hash;
		getline(cin, test);
		if(test[0] == '['){
			hash = str2int(test.substr(1, test.size()-2));
		}else{
			hash = str2int(test);
		}
		string ans1 = str1[hash], ans2 = str2[hash];
		if(ans1 != "") cout << ans1 << endl;
		else if(ans2 != "") cout << ans2 << endl;
		else cout << "what?" << endl;
	}
	return 0;
} 
