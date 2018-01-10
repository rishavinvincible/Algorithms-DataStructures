//Given a array. We have to print the maxsum difference of zeros and one in a subarray
//If there are no zeros, output -1
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int dp[s.size()];
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
				dp[i]=-1;
			else
				dp[i]=1;
		}			
		int maxsum=dp[0], currsum=dp[0];
        for(int i=1;i<s.size();i++)
        {
        	currsum = max(currsum+dp[i],dp[i]);
        	maxsum = max(maxsum, currssum);
        }
        if(maxsum>=0)
        	cout<<maxsum<<endl;
        else
        	cout<<"-1"<<endl;
	}
}