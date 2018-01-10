//Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.
#include <iostream>
using namespace std;
typedef long long int ll;
ll dp[100];
ll fun(int w)
{
	if(dp[w]!=-1)
		return dp[w];
	if(w==0)
		return dp[w] = 1;
	if(w==1)
		return dp[w] = 1;
	return dp[w] = fun(w-1) + fun(w-2);
}
int main()
{
	int t,w;
	cin>>t;
    while(t--)
    {
    	memset(dp,-1,sizeof(dp));
    	cin>>w;
    	cout<<fun(w)<<endl;
    }
}