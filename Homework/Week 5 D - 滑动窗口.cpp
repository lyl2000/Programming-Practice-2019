#include <stdio.h>

const int N = 1000000+100;
struct Num{
	int index, num;
}a[N], queue[N]; 
int min[N], max[N], head = 0, tail = -1;

int main(){
	int k, n;
	scanf("%d %d", &n, &k);  //注意k不同时后面的代码改动 
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i].num);
		a[i].index = i;
	}
	for(int i = 0; i < n; ++i){
		while(head <= tail && i - queue[head].index > k-1) head++;
		while(head <= tail && queue[tail].num > a[i].num) tail--;
		queue[++tail] = a[i];
		if(i >= k-1) min[i-k+1] = queue[head].num;
	}
	head = 0;
	tail = -1;
	for(int i = 0; i < n; ++i){
		while(head <= tail && i - queue[head].index > k-1) head++;
		while(head <= tail && queue[tail].num < a[i].num) tail--;
		queue[++tail] = a[i];
		if(i >= k-1) max[i-k+1] = queue[head].num;
	}
	for(int i = 0; i < n-k+1; ++i) printf("%d ", min[i]);
	printf("\n");
	for(int i = 0; i < n-k+1; ++i) printf("%d ", max[i]);
	printf("\n");
	return 0;
}
