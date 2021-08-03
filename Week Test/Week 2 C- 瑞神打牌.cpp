#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
char players[]={'N','E','S','W'};
string s[]={"North player:","East player:","South player:","West player:"};
string sign="+---+---+---+---+---+---+---+---+---+---+---+---+---+";
char colors[]={'C','D','S','H'};
char nums[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
map<char,int> mp;
map<char,int> the_color;
map<char,int> the_num;
struct pai{
	char color;
	char num;
	pai(){}
	pai(char _color,char _num):color(_color),num(_num){}
	bool operator<(const pai& p)const{
		if(color!=p.color) return the_color[color]<the_color[p.color];
		return the_num[num]<the_num[p.num];
	}
};
pai player[4][13];
pai the_player[13];
int main(){
	char starter;
	string kapai,kapai1,kapai2;
	for(int i=0;i<4;i++) mp[players[i]]=i;
	for(int i=0;i<4;i++) the_color[colors[i]]=i;
	for(int i=0;i<13;i++) the_num[nums[i]]=i;
	while(cin>>starter){
		if(starter=='#') break;
		int nowplayer=(mp[starter]+1);
		cin>>kapai1>>kapai2;
		kapai=kapai1+kapai2;
		char color,num;
		int cnt=0;
		for(int i=0;i<13;i++){
			for(int j=0;j<4;j++){
				color=kapai[cnt++];
				num=kapai[cnt++];
				player[(nowplayer+j)%4][i]=pai(color,num);
			}
		}
		for(int i=2;i<6;i++){
			int n=i%4;
			for(int j=0;j<13;j++){
				the_player[j]=player[n][j];
			}
			sort(the_player,the_player+13);
			cout<<s[n]<<endl;
			cout<<sign<<endl;
			for(int j=0;j<13;j++){
				cout<<"|"<<the_player[j].num<<" "<<the_player[j].num;
			}cout<<"|"<<endl;
			for(int j=0;j<13;j++){
				cout<<"| "<<the_player[j].color<<" ";
			}cout<<"|"<<endl;
			for(int j=0;j<13;j++){
				cout<<"|"<<the_player[j].num<<" "<<the_player[j].num;
			}cout<<"|"<<endl;
			cout<<sign<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
