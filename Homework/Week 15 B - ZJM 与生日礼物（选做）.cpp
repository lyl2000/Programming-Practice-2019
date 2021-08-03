#include <stdio.h>
#include <string.h>
/*
�Ƿ����һ��������һ������ǰ׺
�ֵ��� 
*/
const int N = 1e3+50, charset = 2;
struct Tree{
	int tot, root, child[N][charset], flag[N];
	// �ڵ��ţ�����child[now][x]��ʾnow��x�ӽڵ㣬��β��־
	Tree(){  // ���캯�� 
		memset(child, -1, sizeof(child));
		root = tot = 0;
	}
	void clear(){  // ��� 
		memset(child, -1, sizeof(child));
		root = tot = 0;
	}
	bool insert(char *s){  // �ֵ����в����ַ��� 
		int now = root, cnt = 0, len = strlen(s);  // �Ӹ���ʼ
		for(int i = 0; i < len; ++i){
			int x = s[i] - '0';
			if(child[now][x] == -1){
				child[now][x] = ++tot;
				flag[now] = 0;
			}else if(i == len-1 || flag[child[now][x]]){
				// s�������ַ�����ǰ׺  �����ַ�����s��ǰ׺ 
				cnt = 1;
			}
			now = child[now][x];
		}
		flag[now] = 1;  // ��ǽ�β
		return cnt;
	}
	bool query(char *s){  // ��ѯ�Ƿ����ַ�����s��ǰ׺ 
		int now = root, len = strlen(s);  // �Ӹ���ʼ��ѯ
		for(int i = 0; i < len; ++i){
			int x = s[i] - '0';
			if(child[now][x] == -1) return false;  // ������
			if(flag[x] == 1) return true;  // ǰ׺ 
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
