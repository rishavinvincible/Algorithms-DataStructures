//Given an array of integers A[] and a number k.You can pair two number of array if difference between them is strictly less than k. 
//The task is to find maximum possible sum of such disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.
#include <iostream>
using namespace std;
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>k;
		sort(arr,arr+n);
		int dp[n];
		memset(dp,0,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<n;i++)
		{
			dp[i]=dp[i-1];
			if(arr[i]-arr[i-1]<k)
			{
				if(i>=2)
					dp[i] = max(dp[i],dp[i-2]+arr[i]+arr[i-1]);
				else
					dp[i] = max(dp[i],arr[i]+arr[i-1]);
			}
		}
		cout<<dp[n-1]<<endl;
	}
}