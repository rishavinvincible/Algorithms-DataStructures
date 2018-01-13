
/*Every substring of identical letters is replaced by a single instance of that 
letter followed by the number of occurences of that letter. Then, the string 
thus obtained is further encrypted by reversing it.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,res="";
		cin>>s;
		int n = s.size(), i=0;
		while(i<n)
		{
			int c=1;
			char x = s[i];
			i++;
			while(i<n && s[i]==s[i-1])
			{
				c++;
				i++;
			}
			res = to_string(c) + x +res;
		}
		cout<<res<<endl;
	}
}