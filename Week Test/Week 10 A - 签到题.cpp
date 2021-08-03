#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b ,&c);
	if(a >= b && a >= c){
		if(a % 2) printf("%lld\n", b * c);
		else printf("0\n");
	}else if(b >= a && b >= c){
		if(b % 2) printf("%lld\n", a * c);
		else printf("0\n");
	}else if(c >= a && c >= b){
		if(c % 2) printf("%lld\n", a * b);
		else printf("0\n");
	}
	return 0;
} 
