//Problem is 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int a=arr[0], b=arr[0], loc_a=0, loc_b=0, curr=1, maxlen=1;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>a)
			{
				a = arr[i];
				loc_a = i;
				if(a-b<=1)
					curr++;
				else
				{

					loc_b = loc_b + 1;
					b = arr[loc_b];
					curr = i - loc_b +1;
				}
			}
			else if(arr[i]<b)
			{
				b = arr[i];
				loc_b = i;
				if(a-b<=1)
					curr++;
				else
				{
					loc_a = loc_a + 1;
					a = arr[loc_a];
					curr = i - loc_a + 1;
				}
			}
			maxlen = max(maxlen, curr);
		}
		cout<<maxlen<<endl;
	}
}