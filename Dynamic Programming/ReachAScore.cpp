//Consider a game where a player can score 3 or 5 or 10 points in a move. //Given a total score n, find number of distinct combinations to reach the given score.
#include <iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int dp[n+1];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=3;i<=n;i++)
			dp[i]+=dp[i-3];
		for(int i=5;i<=n;i++)
			dp[i]+=dp[i-5];
		for(int i=10;i<=n;i++)
			dp[i]+=dp[i-10];
		cout<<dp[n]<<endl;
	}
}