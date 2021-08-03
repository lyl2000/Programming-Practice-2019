#include <stdio.h>
#include <string.h>
const int N = 120;
int main(){
	int n; scanf("%d", &n);
	char s[N]; scanf("%s", s);
	int sz = 1;
	for(int i = 0; i < n; i += sz){
		printf("%c", s[i]); sz++;
	}
	return 0;
} 
