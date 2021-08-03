#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 

const int N = 5e3+50;
struct Dir{
	string nm;
	int pre;  // �ϲ�Ŀ¼ 
	map<string, int> child;  // ��Ŀ¼ 
	int sz;  // ��Ŀ¼����Ŀ +1 
	vector<string> p5, b5;  // �洢ǰ5���ͺ�5�� 
	bool tag; 
	Dir(){}
	Dir(string _nm, int _pre):nm(_nm), pre(_pre), sz(1), tag(false){
		child.clear(); p5.clear(); b5.clear();
	}
}dir[N];
struct His{
	string cmd;
	string nm;
	int d;
	His(){}
	His(string _cmd, string _nm, int _d):cmd(_cmd), nm(_nm), d(_d){}
};
int now, cnt;
vector<His> his;  // ��ʷ��¼ 

void update(int num){
	int temp = now;
	while(temp != -1){
		dir[temp].tag = false;
		dir[temp].sz += num;
		temp = dir[temp].pre;
	}
}
void mkdir(string s){
	if(dir[now].child.find(s) != dir[now].child.end()){
		cout << "ERR" << endl; return;
	}  // �ҵ��Ͳ��ܴ��� 
	dir[cnt] = Dir(s, now);  // ������Ŀ¼ 
	cout << "OK" << endl; his.push_back(His("mkdir", s, cnt));
	dir[now].child[s] = cnt++; update(1);
}
void rm(string s){
	if(dir[now].child.find(s) == dir[now].child.end()){
		cout << "ERR" << endl; return;
	}  // û�ҵ�
	int num = dir[now].child.find(s)->second;
	cout << "OK" <<endl; his.push_back(His("rm", s, num));
	dir[now].child.erase(s); update(-1*dir[num].sz);
}
void cd(string s){
	if(s == ".."){
		int pre = dir[now].pre;
		if(pre != -1){
			cout << "OK\n"; his.push_back(His("cd", s, now));
			now = dir[now].pre; return;
		}else{
			cout << "ERR\n"; return;
		}
	}
	if(dir[now].child.find(s) == dir[now].child.end()){
		cout << "ERR\n"; return;
	}  // û�ҵ�
	cout << "OK\n"; his.push_back(His("cd", s, now));
	now = dir[now].child.find(s)->second;
}
void sz(int d){  // =1����ֻ���Լ���û���²�Ŀ¼ 
	cout << dir[d].sz << endl;
}
void ls(int d){
	int len = dir[d].child.size();
	if(len == 0){
		cout << "EMPTY\n";
	}else if(len <= 10){
		for(map<string, int>::iterator it = dir[d].child.begin(); it != dir[d].child.end(); it++){
			cout << dir[it->second].nm << endl;
		}
	}else{
		map<string, int>::iterator it = dir[d].child.begin();
		for(int i = 0; i < 5; ++i){
			cout << dir[it->second].nm << endl; it++;
		}
		cout << "...\n";
		it = dir[d].child.end();
		for(int i = 0; i < 5; ++i) it--;
		for(int i = 0; i < 5; ++i){
			cout << dir[it->second].nm << endl; it++;
		}
	}
}
void pretrack(int d, vector<string>& v){
	v.push_back(dir[d].nm);
	int len = dir[d].child.size();
	for(map<string, int>::iterator it = dir[d].child.begin(); it != dir[d].child.end(); it++){
		pretrack(it->second, v);  // ǰ����� 
	}
}
void pushdown(int d){
	dir[d].p5.clear(); dir[d].b5.clear();
	pretrack(d, dir[d].p5);  // ������
	dir[d].tag = true; 
} 
void treefirst(int num, int d, vector<string>& v){
	v.push_back(dir[d].nm);
	if(--num == 0) return;
	int len = dir[d].child.size();
	for(map<string, int>::iterator it = dir[d].child.begin(); it != dir[d].child.end(); it++){
		int csz = dir[it->second].sz;
		if(csz >= num){
			treefirst(num, it->second, v); return;
		}else{
			treefirst(csz, it->second, v); num -= csz;
		}
	}
}
void treelast(int num, int d, vector<string>& v){
	int len = dir[d].child.size();
	map<string, int>::iterator it = dir[d].child.end();
	while(len--){
		it--;
		int csz = dir[it->second].sz;
		if(csz >= num){
			treelast(num, it->second, v); return;
		}else{
			treelast(csz, it->second, v); num -= csz;
		}
	}
	v.push_back(dir[d].nm);
}
void tree(int d){
	if(dir[d].sz == 1){
		cout << "EMPTY" << endl;
	}else if(dir[d].sz > 1 && dir[d].sz <= 10){
		if(!dir[d].tag)  // û�и��´𰸣���Ҫ���� 
			pushdown(d);  // �����еĶ��Ž�ȥ 
		for(int i = 0, len = dir[d].p5.size(); i < len; ++i)
			cout << dir[d].p5[i] << endl;
	}else if(dir[d].sz > 10){
		if(!dir[d].tag){  // û�и��´𰸣���Ҫ���� 
			dir[d].p5.clear(); dir[d].b5.clear();
			treefirst(5, d, dir[d].p5);
			treelast(5, d, dir[d].b5);
			dir[d].tag = true; 
		}
		for(int i = 0; i < 5; ++i)
			cout << dir[d].p5[i] << endl;
		cout << "...\n";
		for(int i = 4; i >= 0; --i)
			cout << dir[d].b5[i] << endl;
	}
}
void undo(){
	int len = his.size();
	if(len == 0){
		cout << "ERR" << endl; return;
	}
	string cmd = his[len-1].cmd;
	cout << "OK" << endl; his.pop_back();
	if(cmd == "mkdir"){
		int goal = his[len-1].d;
		string s = his[len-1].nm;
		// dir[now] rm s
		dir[now].child.erase(s);
		update(-1*dir[goal].sz);
	}else if(cmd == "rm"){
		int goal = his[len-1].d;
		string s = his[len-1].nm;
		// dir[now] mkdir {s, goal}
		dir[now].child[s] = goal;
		update(1*dir[goal].sz);
	}else if(cmd == "cd"){
		now = his[len-1].d;
	}
}
int main(){
	__;
	int t; cin >> t;
	while(t--){
		int q; cin >> q;
		now = 0, cnt = 1;
		his.clear();
		dir[now] = Dir("root", -1); 
		for(int i = 0; i < q; ++i){
			string cmd; cin >> cmd;
			if(cmd == "MKDIR"){
				string s; cin >> s;
				mkdir(s); // ��dir[cnt]�д���Ŀ¼ �ϲ�Ŀ¼Ϊnow 
			}else if(cmd == "RM"){
				string s; cin >> s;
				rm(s); // ��dir[now]����Ŀ¼����s �ҵ�ɾ�� 
			}else if(cmd == "CD"){
				string s; cin >> s;
				cd(s); // ��dir[now]����Ŀ¼����s �򷵻��ϲ�Ŀ¼ 
			}else if(cmd == "SZ"){
				sz(now); // �����ǰĿ¼�Ĵ�С 
			}else if(cmd == "LS"){
				ls(now); //��ѯ��Ŀ¼ 
			}else if(cmd == "TREE"){
				tree(now); // ��ѯ��� 
			}else if(cmd == "UNDO"){
				undo(); // ���� 
			}
		}
	}
	return 0;
}
