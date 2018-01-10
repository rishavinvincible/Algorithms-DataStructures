//Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
#include <iostream>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ncr=1, res=1;
		for(int r=1;r<=n;r++)
		{
			ncr = (ncr * (n-r+1))/r;
			res += (ncr)*(ncr);
			res = res%mod;
		}
		cout<<res<<endl;
	}
}