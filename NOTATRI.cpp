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
#define __sync__		     std::ios::sync_with_stdio(false);

int a[2010];

int main()
{
	__sync__;
	int n,t;
	while(cin>>n)
	{
		if(n==0) break;
		lld ans=0;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int idx = upper_bound(a,a+n,a[i]+a[j])-a;
				ans+=n-idx;
			}
		cout<<ans<<"\n";
	}
	return 0;
}      
