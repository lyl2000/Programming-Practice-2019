#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int A,B,C;
struct beizi{
	int a,b;
	string c;
	beizi(){}
	beizi(int _a,int _b):a(_a),b(_b){}
	beizi(int _a,int _b,string _c):a(_a),b(_b),c(_c){}
	bool operator<(const beizi& temp)const{
		if(a!=temp.a) return a<temp.a;
		return b<temp.b;
	}
	bool operator==(const beizi& temp)const{
		return a==temp.a&&b==temp.b;
	}
	beizi fillA(){
		return beizi(A,b,"fill A");
	}
	beizi fillB(){
		return beizi(a,B,"fill B");
	}
	beizi emptyA(){
		return beizi(0,b,"empty A");
	}
	beizi emptyB(){
		return beizi(a,0,"empty B");
	}
	beizi pourAtoB(){
		return (a+b>B)?beizi(a+b-B,B,"pour A B"):beizi(0,a+b,"pour A B");
	}
	beizi pourBtoA(){
		return (a+b>A)?beizi(A,a+b-A,"pour B A"):beizi(a+b,0,"pour B A");
	}
};
queue<beizi> Q;
map<beizi,bool> isFound;
map<beizi,beizi> father;

bool check(beizi child,beizi now){
	if(isFound[child]==0){
		isFound[child]=1;
		father[child]=now;
		Q.push(child);
	}
}

void print(beizi now){
	if(now==beizi(0,0)) return;
	print(father[now]);
	cout<<now.c<<endl;
}

void bfs(){
	beizi now(0,0);
	Q.push(now);
	isFound[now]=1;
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(now.a==C||now.b==C){
			print(now);
			return;  //ÕÒµ½Ä¿±ê 
		}
		check(now.emptyA(),now);
		check(now.emptyB(),now);
		check(now.fillA(),now);
		check(now.fillB(),now);
		check(now.pourAtoB(),now);
		check(now.pourBtoA(),now);
	}
	return;
}

int main(){
	while(cin>>A>>B>>C){
		isFound.clear();
		father.clear();
		while(!Q.empty()) Q.pop();
		bfs();
		cout<<"success"<<endl;
	} 
	return 0;
} 
