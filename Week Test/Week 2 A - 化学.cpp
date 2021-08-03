#include <iostream>
#include <string.h>
using namespace std;
int JW[7][5];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(JW,0,sizeof(JW));
		int a,b,c3=0,c4=0,pos=0;
		for(int i=0;i<5;i++){
			cin>>a>>b;
			JW[a][++JW[a][0]]=b;
			JW[b][++JW[b][0]]=a;
		}
//		for(int i=1;i<7;i++){
//			for(int j=0;j<5;j++)
//				cout<<JW[i][j]<<' ';
//			cout<<endl;
//		}
		for(int i=1;i<7;i++){
			if(JW[i][0]==3){
				c3++;
				pos=i;
			}
			if(JW[i][0]==4) c4++;
		}
		if(!c3&&!c4) cout<<"n-hexane"<<endl;
		else if(!c4&&c3==2) cout<<"2,3-dimethylbutane"<<endl;
		else if(c4) cout<<"2,2-dimethylbutane"<<endl;
		else{
			int cnt=0;
			for(int i=1;i<=JW[pos][0];i++){
				if(JW[JW[pos][i]][0]==2) cnt++;
			}
			if(cnt==2) cout<<"3-methylpentane"<<endl;
			else if(cnt==1) cout<<"2-methylpentane"<<endl;
		}
	}
	return 0;
} 
