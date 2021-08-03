#include <stdio.h>
#include <string.h>
/*
是否存在一个串是另一个串的前缀
字典树 
*/
const int N = 1e3+50, charset = 2;
struct Tree{
	int tot, root, child[N][charset], flag[N];
	// 节点编号，根，child[now][x]表示now的x子节点，结尾标志
	Tree(){  // 构造函数 
		memset(child, -1, sizeof(child));
		root = tot = 0;
	}
	void clear(){  // 清空 
		memset(child, -1, sizeof(child));
		root = tot = 0;
	}
	bool insert(char *s){  // 字典树中插入字符串 
		int now = root, cnt = 0, len = strlen(s);  // 从根开始
		for(int i = 0; i < len; ++i){
			int x = s[i] - '0';
			if(child[now][x] == -1){
				child[now][x] = ++tot;
				flag[now] = 0;
			}else if(i == len-1 || flag[child[now][x]]){
				// s是其他字符串的前缀  其他字符串是s的前缀 
				cnt = 1;
			}
			now = child[now][x];
		}
		flag[now] = 1;  // 标记结尾
		return cnt;
	}
	bool query(char *s){  // 查询是否有字符串是s的前缀 
		int now = root, len = strlen(s);  // 从根开始查询
		for(int i = 0; i < len; ++i){
			int x = s[i] - '0';
			if(child[now][x] == -1) return false;  // 不存在
			if(flag[x] == 1) return true;  // 前缀 
		}
		return false;
	}
};
int main(){
	char s[N]; int k = 1;
	Tree t; bool ans = 0, num = 0;
	while(~scanf("%s", s)){
		if(strcmp(s, "9") == 0){
			if(ans) printf("Set %d is not immediately decodable\n", k);
			else printf("Set %d is immediately decodable\n", k);
			t.clear(); k++; ans = 0; num = 0;
			continue;
		}
		num = t.insert(s);
//		printf("%d\n", num);
		if(num) ans = 1;
	} 
	return 0;
}
