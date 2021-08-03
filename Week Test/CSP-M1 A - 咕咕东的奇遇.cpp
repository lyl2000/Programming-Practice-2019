#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin>>str;
	int res=0;
	char start='a';
	for(int i=0;i<str.length();i++){
		int len=(str[i]+26-start)%26;
		if(len<=13){
			res+=(str[i]-start+26)%26;
		}else{
			res+=(start-str[i]+26)%26;	
		}
		start=str[i];
	}
	cout<<res<<endl;
	return 0;
}
