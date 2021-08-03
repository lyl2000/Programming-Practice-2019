#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

const int MAXA = 26, MAXB = 4;
int A, B, c, sign[10];
struct Pai{
	int a, b;
	Pai(){}
	Pai(int _a, int _b):a(_a), b(_b){}
	bool operator<(const Pai& pai) const {
		if(a != pai.a) return a < pai.a;
		return b < pai.b;
	}
	void output(){ printf("%d %d\n", a, b); }
}p[6], pai[6];
map<Pai, bool> isUse;

void check(){
	bool two = 1, three = 1;
	map<int, int> cnt;
	sort(pai+1, pai+6);
	for(int i = 1; i <= 5; ++i){
		cnt[pai[i].a]++;
		if(i >= 2){
			if(pai[i].a != pai[i-1].a + 1) two = 0;
			if(pai[i].b != pai[i-1].b) three = 0;
		}
	}//printf("two = %d three = %d\n", two, three);
	if(two && three){ sign[1]++; return; }
	if(two){ sign[2]++; return; }
	if(three){ sign[3]++; return; }
	map<int, int>::iterator iter;
	iter = cnt.begin();
	int num[5], n = 0;
//	printf("iter: ");
	while(iter != cnt.end()){
//		printf("%d ", iter->second);
		num[n++] = iter->second;
		iter++;
	}//printf("\n");
	sort(num, num+n, greater<int>());
	if(num[0] == 4) { sign[4]++; return; }
	else if(n == 2 && num[0] == 3 && num[1] == 2) { sign[5]++; return; }
	else if(n == 3 && num[0] == 2 && num[1] == 2) { sign[6]++; return; }
	else if(n == 3 && num[0] == 3 && num[1] == 1) { sign[7]++; return; }
	else if(n == 4 && num[0] == 2) { sign[8]++; return; }
	else { sign[9]++; return; }
}

void backtrack(int a, int b, int s){
	if(s >= 5){
//		printf("case %d:\n", ++c);
		for(int i = 1; i <= 5; ++i){
			pai[i] = p[i];
//			p[i].output();
		}
		check();
		return;
	}
	for(int k = a*B+b+1; k < A*B; ++k){
		int i = k / B, j = k % B;
		if(!isUse[Pai(i, j)]){
			p[s+1] = Pai(i, j);
			isUse[p[s+1]] = 1;
			backtrack(i, j, s+1);
			isUse[p[s+1]] = 0;
		}
	}
}

int main(){
	scanf("%d %d", &A, &B);
	scanf("%d %d %d %d", &p[1].a, &p[1].b, &p[2].a, &p[2].b);
	for(int i = 1; i <= 9; ++i) sign[i] = 0;
	isUse[p[1]] = 1; isUse[p[2]] = 1;
	c = 0; backtrack(0, -1, 2);
	for(int i = 1; i <= 9; ++i) printf("%d ", sign[i]);
	printf("\n");
	return 0;
}
