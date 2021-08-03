#include <stdio.h>
#include <queue>
using namespace std;

struct Num{
	int num, cnt;  // ²Ù×÷´ÎÊı 
	Num(){}
	Num(int _num, int _cnt):num(_num), cnt(_cnt){}
};
queue<Num> q;
int n, m, ans;

void trans(){
	while(!q.empty()){
		int num = q.front().num, cnt = q.front().cnt; q.pop();
//		printf("%d %d\n", num, cnt);
		if(num == m){
			ans = cnt; return;
		}
		else if(num < m){
			q.push(Num(num*2, cnt+1));
			q.push(Num(num*3, cnt+1));
		}
	}
	ans = -1;
}

int main(){
	scanf("%d%d", &n, &m);
	q.push(Num(n, 0));
	trans();
	printf("%d\n", ans);
	return 0;
} 
