/*You have got a maze, which is a N*N Grid. Every cell of the maze contains these numbers 1, 2 or 3. 
If it contains 1 : means we can go Right from that cell only.
If it contains 2 : means we can go Down from that cell only.
If it contains 3 : means we can go Right and Down to both paths from that cell.
We cant go out of the maze at any time.

Initially, You are on the Top Left Corner of The maze(Entry). And, You need to go to the Bottom Right Corner of the Maze(Exit).
You need to find the total number of paths from Entry to Exit Point.

There may be many paths but you need to select that path which contains the maximum number of Adventure.
The Adventure on a path is calculated by taking the sum of all the cell values thatlies in the path.
If no valid path exists, Adventure is zero.Since the total paths may be very large, Output it Modulo (1e9+7).*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int dp1[1000][1000];
int dp2[1000][1000];
ll fun(int i,int j,int n,vector<vector<int> > &arr)
{
	if(i==n-1 && j==n-1)
	{
		return arr[i][j];
	}
	if(dp1[i][j]!=-1)
		return dp1[i][j];
	if(i>=n||j>=n)
		return -9999;
	
	if(arr[i][j]==1)
		return dp1[i][j] =  (arr[i][j] + fun(i,j+1,n,arr))%mod;
	else if(arr[i][j]==2)
		return dp1[i][j] = (arr[i][j] + fun(i+1,j,n,arr))%mod;
    else 
    	return dp1[i][j] = (3+max(fun(i+1,j,n,arr),fun(i,j+1,n,arr)))%mod;
}
ll count(int i,int j,int n,vector<vector<int> > &arr)
{
	if(i==n-1 && j==n-1)
	{
		return 1;
	}
	if(dp2[i][j]!=-1)
		return dp2[i][j];
	if(i>=n||j>=n)
		return 0;
	
	if(arr[i][j]==1)
		return dp2[i][j] = count(i,j+1,n,arr)%mod;
	else if(arr[i][j]==2)
		return dp2[i][j] = count(i+1,j,n,arr)%mod;
    else 
    	return dp2[i][j] = (count(i+1,j,n,arr)%mod + count(i,j+1,n,arr)%mod)%mod;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(dp1,-1,sizeof(dp1));
		memset(dp2,-1,sizeof(dp2));
		cin>>n;
		vector<vector<int> >  arr(n,vector<int> (n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}
	    ll res = fun(0,0,n,arr);
	    ll c = count(0,0,n,arr);
	    cout<<c<<" "<<res<<endl;
	}
}