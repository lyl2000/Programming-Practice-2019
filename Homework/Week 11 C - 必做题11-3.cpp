#include <string>
#include <iostream>
#include <map>
using namespace std;

string code;
map<char, char> dict;  // 由密文转明文的字典 

int main(){
	getline(cin, code);
	for(int i = 0; i < 26; ++i) dict['A'+i] = (i+21)%26+'A';
	for(int i = 0; i < code.size(); ++i){
		if(code[i] < 'A' || code[i] > 'Z') cout << code[i];
		else cout << dict[code[i]];
	}
	cout << endl;
	return 0;
} 
