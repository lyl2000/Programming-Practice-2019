#include <stdio.h>
const int N = 2e5+50;
char s[N];
bool o[N];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	int k = 0, j = 1;
	for(int i = 0; i < n; ++i) o[i] = 0;
	for(int i = 0; i < n; ++i, ++j){
		if(j % 2 && i < n-1 && s[i] == s[i+1]){
			o[i] = 1; j--; k++;
		}
		if(i == n-1 && j % 2){
			o[i] = 1; k++;
		}
	}
	printf("%d\n", k);
	for(int i = 0; i < n; ++i){
		if(!o[i]) printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
