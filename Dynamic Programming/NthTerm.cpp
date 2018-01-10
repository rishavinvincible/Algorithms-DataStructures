//A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.
#include <iostream>
using namespace std;
typedef long long int ll;
ll fun(int n)
{
	ll res = (n*(n-1)/2) + 1;
		//cout<<res<<endl;
		ll val = 1;
		for(int i=1;i<=n;i++)
		{
			val = val * res;
			res+=1;
		}
		return val;
}
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll res = 0;
		for(int i=1;i<=n;i++)
			res+=fun(i);
		cout<<res<<endl;
		
	}
}