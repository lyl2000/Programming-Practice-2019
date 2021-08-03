#include <stdio.h>

int main(){
	int n, k; scanf("%d%d", &n, &k);
	int money = n, y = 1;  // 存款 年 
	double price = 200;  // 房价 
	bool isOk = true;
	while(money < price){
		money += n;
		price += price*k/100;
		y++;
		if(y > 20){
			isOk = false;
			break;
		}
//		printf("%d %lf %d\n", money, price, y);
	}
	if(!isOk) printf("Impossible\n");
	else printf("%d\n", y);
	return 0;
}
