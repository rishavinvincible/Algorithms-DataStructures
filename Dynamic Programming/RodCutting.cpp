//Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
//Determine the maximum value obtainable by cutting up the rod and selling the pieces.
#include <iostream>
using namespace std;
int dp[100];
int fun(int n, int arr[])
{
	if(n==0)
		return dp[n] = 0;
	if(n<0)
		return dp[n] = 99999;
	int res = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		res = min(res, fun(n-arr[i-1],arr));
	}
	return dp[n] = res;
}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(dp,-1,sizeof(dp));
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int res = fun(n,arr);
		cout<<res<<endl;
	}
}
