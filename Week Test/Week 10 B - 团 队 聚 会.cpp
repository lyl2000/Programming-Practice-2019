#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define ll long long

struct Time{
	int Y, M, D, h, m, s;
	Time(int _Y, int _M, int _D, int _h, int _m, int _s)
		:Y(_Y), M(_M), D(_D), h(_h), m(_m), s(_s){}
	Time(int *t){
		Y = t[0]; M = t[1]; D = t[2];
		h = t[3]; m = t[4]; s = t[5];
	}
	bool operator<(const Time& t) const {
		if(Y != t.Y) return Y < t.Y;
		if(M != t.M) return M < t.M;
		if(D != t.D) return D < t.D;
		if(h != t.h) return h < t.h;
		if(m != t.m) return m < t.m;
		return s < t.s;
	}
	bool operator>=(const Time& t) const {
		return !(*this < t);
	}
	bool operator<=(const Time& t) const {
		return !(t < *this);
	}
};

struct Table{
	Time s;
	Time e;
	Table(Time _s, Time _e):s(_s), e(_e){}
};

int m;
set<Time> time_set;
vector<Time> time_point; 
vector<Table> ta[25], ans;  // 20+5 

bool isNotBusy(int i, Time s, Time e){
	for(int j = 0; j < ta[i].size(); ++j){
		Table t = ta[i][j];
		if(t.s <= s && t.e >= e) return false;
		// 不可能有一个t，t.s>s&&t.e<e 因为s,e都是time_set里紧挨着的 
	}
	return true;
}

bool isOk(Time s, Time e){
	int cnt = 0;
	for(int i = 1; i <= m; ++i){  // 对每一个TA进行判断，是否可以开会 
		if(isNotBusy(i, s, e)) cnt++;
	}
	if(cnt >= 2 && cnt >= m-1) return true;
	return false;
}

bool isOver1h(Time s, Time e){
	ll st = (((((1ll*s.Y-1800)*12+s.M-1)*30+s.D-1)*24+s.h)*60+s.m)*60+s.s;
	ll et = (((((1ll*e.Y-1800)*12+e.M-1)*30+e.D-1)*24+e.h)*60+e.m)*60+e.s;
	if(et - st >= 3600) return true;
	return false;
} 

int main(){
	int t; scanf("%d", &t);
	Time ss(1800, 1, 1, 0, 0, 0), ee(2200, 1, 1, 0, 0, 0); 
	for(int grp = 1; grp <= t; ++grp){  // 每一组数据 
		scanf("%d", &m);  // TA数
		// 初始化 
		for(int i = 1; i <= m; ++i) ta[i].clear();
		ans.clear(); time_set.clear(); time_point.clear();
		time_set.insert(ss); time_set.insert(ee);
		for(int i = 1; i <= m; ++i){
			int n; scanf("%d", &n);  // 任务数 
			for(int j = 1; j <= n; ++j){
				int start[6], end[6];
				for(int k = 0; k < 6; ++k) scanf("%d", &start[k]);
				for(int k = 0; k < 6; ++k) scanf("%d", &end[k]);
				char info[105]; scanf("%[^\n]", info);
				Time s = Time(start), e = Time(end);
				time_set.insert(s); time_set.insert(e);
				ta[i].push_back(Table(s, e));
			}
		}
		
		for(set<Time>::iterator i = time_set.begin(); i != time_set.end(); i++){
			// ans的所有可能都在端点上  set已经排好序 可以按序便历 
			time_point.push_back(*i);
		}
		
		// 对每一个区间进行判断
		int le = 0, ri = 0, len = time_point.size();
		while(ri < len){
			// 判断[ri, ri+1]是否可行 端点必须紧挨着 
			// 如果可行 ri++ 防止ri越界要小于len-1 
			while(ri < len-1 && isOk(time_point[ri], time_point[ri+1])) ri++;
			if(isOver1h(time_point[le], time_point[ri])) 
				ans.push_back(Table(time_point[le], time_point[ri]));
			le = ri + 1;
			// [le, le+1]  找一个可行的开始点 
			while(le < len-1 && (!isOk(time_point[le], time_point[le+1]))) le++;
			ri = le + 1;
		}
		
		printf("Scenario #%d:\n", grp);
		if(ans.size() == 0){
			printf("no appointment possible\n");
		}else{
			for(int i = 0; i < ans.size(); ++i){
				Time s = ans[i].s, e = ans[i].e;
				printf("appointment possible from %02d/%02d/%d %02d:%02d:%02d to %02d/%02d/%d %02d:%02d:%02d\n"
					, s.M, s.D, s.Y, s.h, s.m, s.s, e.M, e.D, e.Y, e.h, e.m, e.s);
			}
		}
		printf("\n");
	}
	return 0;
}
