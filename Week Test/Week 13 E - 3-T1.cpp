#include <stdio.h>
int ab(char A, char B){
	if(A == 'S'){
		if(B == 'S') return 0;
		else if(B == 'J') return 1;
		else if(B == 'B') return -1;
	}else if(A == 'J'){
		if(B == 'S') return -1;
		else if(B == 'J') return 0;
		else if(B == 'B') return 1;
	}else if(A == 'B'){
		if(B == 'S') return 1;
		else if(B == 'J') return -1;
		else if(B == 'B') return 0;
	}
}
int main(){
	int n; scanf("%d ", &n);
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		char A, B; scanf("%c %c", &A, &B);
		int c = ab(A, B);
		if(c > 0) a++;
		else if(c < 0) b++;
		getchar();
	}
	if(a > b) printf("suantou\n");
	else if(a == b) printf("QAQ\n");
	else printf("huaye\n");
	return 0;
}
