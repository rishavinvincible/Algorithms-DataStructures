//Given a string, find the longest substring which is palindrome.
//For example, if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”.
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		int n = s.size();
		int start=0, maxlength = 0, low, high;
		//Idea is to go through each of the 2*n+1 centers and expand around those centers.
		for(int l=0;l<n;l++)
		{
			//Expand around the point b/w characters
			low = l-1;
			high = l;
			while(low>=0 && high<n && s[low]==s[high])
			{
				if(high - low +1>maxlength)
				{
					start = low;
					maxlength = high - low + 1;
				}
				low--;
				high++;
			}
			
			//Expand around the element right now
			low=l-1;
			high = l+1;
			while(low>=0 && high<n && s[low]==s[high])
			{
				if(high - low +1>maxlength)
				{
					start = low;
					maxlength = high - low + 1;
				}
				low--;
				high++;
			}
		}
		cout<<s.substr(start, maxlength)<<endl;
	}
}
