#include <stdio.h>
#include <math.h>
#include <string.h> 
#define ll long long
#include <stack>
using namespace std;

// 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5
ll calcu_sum(ll x){  // ���ܺ� 
	// �Ȳ����� n*a+n*(n-1)/2*d  ����������� 
	// len(x) 1 ~ x �ĳ��� �൱������ͨ�� 
	// n �� 10^(cnt-1) �ĸ���  x-10^(cnt-1)+1 
	// ���� a = len(10^(cnt-1)-1)+d  ���� d = cnt λ�� 
	// sum = n*(len(10^(cnt-1)-1)+cnt)+n*(n-1)/2*cnt
	//     = n*len(10^(cnt-1)-1)+2*n*cnt/2+n*(n-1)/2*cnt
	//     = n*len(10^(cnt-1)-1)+n*(n+1)/2*cnt
	// ��sum += n*len(10^(cnt-1)-1)+n*(n+1)/2*cnt
	// ��101 cnt = 3  a = len(99)+4  n = 101-100+1 = 2
	// len(10^(cnt-1)-1)
	// len(99) �Ƿ����� len(9)����� 
	// len(99) = len(9)+(10, 11, ~ ,99) 
	// a = len(10^(cnt-1)-1)  d = cnt
	// n = 10^cnt-1-10^(cnt-1)+1 = 10^cnt - 10^(cnt-1)
	// len(10^cnt-1) = a + n*d
	//               = len(10^(cnt-1)-1)+n*cnt
	ll cnt = 0, len = 0, sum = 0, n = 1, m;  // �������ȫ��ll 
	while(true){
		n *= 10; cnt++;
		// 1��1���ۼ�̫�� �Ȱ�10,100����10^cnt���� 
		if(n - 1 < x){  // 9 99 999 < x
			m = n - n / 10;  // ��10^cnt - 10^(cnt-1)���� 
			sum += m * len + m * (m+1) / 2 * cnt;
			len += m * cnt;
		}else{  // 9 99 999 >= x ����ֹͣ�� 
			m = x - n / 10 + 1;  // ��ס x-10^(cnt-1)+1 Ҫ+1 
			sum += m * len + m * (m+1) / 2 * cnt;
			len += m * cnt;
			break;
		}
	}
	return sum;
}

ll calcu_num(ll x){  // ��calcu_sum���ƣ����Ǽ��������len���� 
	ll cnt = 0, len = 0, sum = 0, n = 1, m;
	while(true){
		n *= 10; cnt++;
		// 1��1���ۼ�̫�� �Ȱ�10,100����10^cnt���� 
		if(n - 1 < x){  // 9 99 999 < x
			m = n - n / 10;  // ��10^cnt - 10^(cnt-1)���� 
			len += m * cnt;
		}else{  // 9 99 999 >= x ����ֹͣ�� 
			m = x - n / 10 + 1;  // ��ס x-10^(cnt-1)+1 Ҫ+1 
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
		ll le = 0, ri = 1e9, mid, ans;  // ȡ1e18������Ϊ����
		while(le <= ri){
			mid = (le + ri) >> 1;  // ����̫�����ö��ֲ���
			if(calcu_sum(mid) < k){
				le = mid + 1; ans = mid;  // �ҵ�������ֲ������� 
			}else{
				ri = mid - 1;
			}
		}
//		printf("ans1 = %d\n", ans);
		// k ��(ans��ans+1)�� 
		k -= calcu_sum(ans);  // ����������ֵ ��ans+1��Ѱ�� 
		le = 0; ri = ans+1;
		while(le <= ri){  // ��Ȼʹ�ö��� 
			mid = (le + ri) >> 1;
			if(calcu_num(mid) < k){
				le = mid + 1; ans = mid;  // ������������ 
			}else{
				ri = mid - 1;
			}
		}
//		printf("ans2 = %d\n", ans);
		k -= calcu_num(ans);  // ��ans+1�ж������ 
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
