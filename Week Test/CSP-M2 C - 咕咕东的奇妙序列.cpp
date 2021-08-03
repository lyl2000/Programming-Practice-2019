#include <stdio.h>
#include <math.h>
#include <string.h> 
#define ll long long
#include <stack>
using namespace std;

// 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5
ll calcu_sum(ll x){  // 求总和 
	// 等差数列 n*a+n*(n-1)/2*d  返回数列求和 
	// len(x) 1 ~ x 的长度 相当于数列通项 
	// n 到 10^(cnt-1) 的个数  x-10^(cnt-1)+1 
	// 首项 a = len(10^(cnt-1)-1)+d  公差 d = cnt 位数 
	// sum = n*(len(10^(cnt-1)-1)+cnt)+n*(n-1)/2*cnt
	//     = n*len(10^(cnt-1)-1)+2*n*cnt/2+n*(n-1)/2*cnt
	//     = n*len(10^(cnt-1)-1)+n*(n+1)/2*cnt
	// 总sum += n*len(10^(cnt-1)-1)+n*(n+1)/2*cnt
	// 如101 cnt = 3  a = len(99)+4  n = 101-100+1 = 2
	// len(10^(cnt-1)-1)
	// len(99) 是否能由 len(9)算出？ 
	// len(99) = len(9)+(10, 11, ~ ,99) 
	// a = len(10^(cnt-1)-1)  d = cnt
	// n = 10^cnt-1-10^(cnt-1)+1 = 10^cnt - 10^(cnt-1)
	// len(10^cnt-1) = a + n*d
	//               = len(10^(cnt-1)-1)+n*cnt
	ll cnt = 0, len = 0, sum = 0, n = 1, m;  // 保险起见全用ll 
	while(true){
		n *= 10; cnt++;
		// 1个1个累加太慢 先按10,100……10^cnt递增 
		if(n - 1 < x){  // 9 99 999 < x
			m = n - n / 10;  // 按10^cnt - 10^(cnt-1)加满 
			sum += m * len + m * (m+1) / 2 * cnt;
			len += m * cnt;
		}else{  // 9 99 999 >= x 可以停止了 
			m = x - n / 10 + 1;  // 记住 x-10^(cnt-1)+1 要+1 
			sum += m * len + m * (m+1) / 2 * cnt;
			len += m * cnt;
			break;
		}
	}
	return sum;
}

ll calcu_num(ll x){  // 与calcu_sum类似，但是计算出长度len即可 
	ll cnt = 0, len = 0, sum = 0, n = 1, m;
	while(true){
		n *= 10; cnt++;
		// 1个1个累加太慢 先按10,100……10^cnt递增 
		if(n - 1 < x){  // 9 99 999 < x
			m = n - n / 10;  // 按10^cnt - 10^(cnt-1)加满 
			len += m * cnt;
		}else{  // 9 99 999 >= x 可以停止了 
			m = x - n / 10 + 1;  // 记住 x-10^(cnt-1)+1 要+1 
			len += m * cnt;
			break;
		}
	}
	return len;
}

int main(){
	int q; scanf("%d", &q);
	while(q--){
		ll k; scanf("%lld", &k);
		ll le = 0, ri = 1e9, mid, ans;  // 取1e18开根作为上限
		while(le <= ri){
			mid = (le + ri) >> 1;  // 线性太慢，用二分查找
			if(calcu_sum(mid) < k){
				le = mid + 1; ans = mid;  // 找到最靠近但又不超过的 
			}else{
				ri = mid - 1;
			}
		}
//		printf("ans1 = %d\n", ans);
		// k 在(ans，ans+1)里 
		k -= calcu_sum(ans);  // 计算多余的数值 在ans+1中寻找 
		le = 0; ri = ans+1;
		while(le <= ri){  // 仍然使用二分 
			mid = (le + ri) >> 1;
			if(calcu_num(mid) < k){
				le = mid + 1; ans = mid;  // 靠近但不超过 
			}else{
				ri = mid - 1;
			}
		}
//		printf("ans2 = %d\n", ans);
		k -= calcu_num(ans);  // 在ans+1中多余的项 
		ans += 1; k -= 1;
		stack<int> s;
		while(ans){
			s.push(ans % 10);
			ans /= 10;
		}
		while(k--) s.pop();
		printf("%d\n", s.top());
	}
	return 0;
}
