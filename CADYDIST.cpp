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
	unsigned long long int n,xx;
	while(cin>>n)
	{
		if(n==0) break;
		vector<unsigned long long int> a,b;
		unsigned long long int ans = 0;
		for(int i=0;i<n;i++) {cin>>xx; a.pb(xx);}
		for(int i=0;i<n;i++) {cin>>xx; b.pb(xx);}
		sort(a.begin(),a.end());
		sort(b.rbegin(),b.rend());
		for(int i=0;i<n;i++) ans += a[i]*b[i];
		cout<<ans<<"\n";
	}
}      
