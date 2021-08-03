#include <string.h>
#include <map>
#include <stdio.h>
using namespace std;
map<char, int> cnt;
const int N = 1e6+5;
char str[N];

bool isOk(){
	int num = 0;
	for(int i = 0; i < 26; ++i){
		char c = i+'A';
		if(cnt[c] > 1) return false;  // 出现次数大于1 
	}
	return true;
}

int main(){
	scanf("%s", str);
	int len = strlen(str);
	int le = 0, ri = len - 26;
	for(int i = 0; i < 26; ++i){
		cnt[str[i]]++;
	}
	while(le <= ri){
		if(isOk()){
			int z[26], num = 0;
			for(int i = 0; i < 26; ++i) z[i] = 0;
			for(int i = 0; i < 26; ++i){
				char c = i + 'A';
				if(cnt[c] == 0) z[num++] = i;  // 未出现的字母 
			}
			num = 0;
			for(int i = le; i < le + 26; ++i){
				char c = str[i];
				if(c == '?') printf("%c", z[num++] + 'A');
				else printf("%c", c);
			}
			printf("\n");
			return 0;
		}else{
			if(le < ri){
				--cnt[str[le]];
				++cnt[str[le+26]];	
			}
			++le;
		}
	}
	printf("-1\n");
	return 0;
}
