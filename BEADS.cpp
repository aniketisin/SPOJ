#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		a+=a;
		cout<<a<<"\n";
		int ans = -1;
		int off = 0;
		for(int i=0;i<a.length();i++)
		{
			off%=(a.length()/2);
			if(ans==-1)
			{
				ans = i;
				continue;
			}
			if(a[i]<a[ans])
			{
				ans = i;
				off = 0;
				continue;
			}
			if(a[ans+off]==a[i])
			{
				off++;
				continue;
			}
			if(a[ans+off]>a[i])
			{
				ans = i-off;
				off = 0;
				continue;
			}
			if(a[ans+off]<a[i])
			{
				off = 0;
				continue;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}      
