#include <stdio.h>
#include <algorithm>
using namespace std;
struct Time{
	int s, e;
	Time(){}
	Time(int _s, int _e):s(_s), e(_e){}
	bool operator < (const Time& t) const {
		return s < t.s;
	}
}time[25], sleep[25];
int main(){
	int a, b, n;
	while(~scanf("%d%d%d", &a, &b, &n)){
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int sh, sm, eh, em;
			scanf("%d:%d-%d:%d", &sh, &sm, &eh, &em);
			time[i] = Time(sh*60+sm, eh*60+em);
		}
		sort(time, time+n);
		for(int i = 0; i < n; ++i){
			int m = (i+1)%n, len;
			if(time[m].s < time[i].e)
				len = time[m].s - time[i].e - 1 + 24*60;
			else
				len = time[m].s - time[i].e - 1;
			if(len >= a * 60){
				sleep[cnt++] = Time((time[i].e + 1)%(24*60), (time[m].s - 1+24*60)%(24*60));
//				cost += len;
			}
		}
		if(cnt == 0){
			printf("No\n"); continue;
		}
		bool isOk = true;
		for(int i = 0; i < cnt; ++i){
			int m = (i+1)%cnt, len;
//			printf("%d %d\n", sleep[m].s, sleep[i].e);
			if(sleep[m].s < sleep[i].e)
				len = sleep[m].s - sleep[i].e - 1 + 24*60;
			else
				len = sleep[m].s - sleep[i].e - 1;
//			printf("%d\n", len);
			if(len > b * 60){
				isOk = false;
				break;
			}
		}
		if(isOk){
			printf("Yes\n%d\n", cnt);
			for(int i = 0; i < cnt; ++i){
				int sh = sleep[i].s/60, sm = sleep[i].s%60, 
					eh = sleep[i].e/60, em = sleep[i].e%60;
				printf("%02d:%02d-%02d:%02d\n", sh, sm, eh, em);
			}
		}else{
			printf("No\n"); continue;
		}
	}
	return 0;
}
