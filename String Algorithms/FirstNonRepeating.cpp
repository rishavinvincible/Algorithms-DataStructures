//find its first non-repeating character
#include <bits/stdc++.h>
using namespace std;

int mark[256];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		memset(mark,0,sizeof(mark));
		int n = s.size();
		char first;
		for(int i=n-1;i>=0;i--)
		{
			 char x = s[i];
			 if(mark[x]==0)
			 	first = x;
			 mark[x]++;
		}
		cout<<first<<endl;
	}
}