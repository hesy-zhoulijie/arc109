```cpp
#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,k;
	cin >>n>>k;
	string s;
	cin >>s;
	char w[222][222];
	w['R']['R']=w['R']['S']=w['S']['R']='R'; 
	w['S']['S']=w['P']['S']=w['S']['P']='S';
	w['P']['P']=w['R']['P']=w['P']['R']='P';
	while ( k-- ){
		string ss=s+s;
		for ( int i = 0 ; i < n ; ++i ){
			s[i]=w[ss[i*2+1]][ss[i*2]];
		}
	}
	cout <<s[0]<<endl;
	return 0;
}
```
***
```cpp
#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	char w[100][100];

	w['R']['R']=w['R']['S']=w['S']['R']='R';
	w['S']['S']=w['S']['P']=w['P']['S']='S';
	w['P']['P']=w['P']['R']=w['R']['P']='P';

	while(k--)
	{
		string ss=s+s;
		for(int i=0;i<n;++i)
		s[i]=w[ss[i*2]][ss[i*2+1]];
	}
	
	cout<<s[0];
	return 0; 
}
```