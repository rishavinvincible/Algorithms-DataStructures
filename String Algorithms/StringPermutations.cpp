//a program to print all permutations of a given string

#include <bits/stdc++.h>
using namespace std;
void fun(string s,int l,int h)
{
	if(l==h)
	{
		cout<<s<<endl;
		return;
	}
	for(int i=l;i<=h;i++)
	{
		swap(s[l],s[i]);
		fun(s,l+1,h);
		swap(s[l],s[i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.size();
		fun(s,0,n-1);
	}
}