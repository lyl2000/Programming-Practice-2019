#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
const int N=5000;
int n,m;
struct student{
	string name;
	int ac;
	int time;
	student(){}
	student(string _name,int _ac,int _time):name(_name),ac(_ac),time(_time){}
	bool operator<(const student& temp){
		if(ac!=temp.ac) return ac>temp.ac;
		if(time!=temp.time) return time<temp.time;
		return name<temp.name;
	}
};
student a[N];
int get_score(string score){
	int n=score.size(),flag=0,num=0,fail=0;
	for(int i=0;i<n;i++){
		if(n==1&&score[i]==0) return 0;
		if(i==0&&score[i]=='-') return 0;
		if(score[i]=='('||score[i]==')'){
			flag=1;
			continue;
		}
		if(!flag) num=num*10+score[i]-'0';
		else fail=fail*10+score[i]-'0';
	}
	return num+fail*m;
}
int main(){
	cin>>n>>m;
	int num=0;
	string name,score;
	while(cin>>name){
		int all_time=0,time,ac=0;
		for(int i=0;i<n;i++){
			cin>>score;
			time=get_score(score);
			if(time>0){
				all_time+=time;
				ac++;
			}
		}
		a[num++]=student(name,ac,all_time);
	}
	sort(a,a+num);
	for(int i=0;i<num;i++){
		cout<<setw(10)<<left<<a[i].name<<" ";
		cout<<setw(2)<<right<<a[i].ac<<" ";
		cout<<setw(4)<<right<<a[i].time<<endl;
	}
	return 0;
} 
