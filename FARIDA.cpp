#include<bits/stdc++.h>
using namespace std;

typedef long long int lld;
typedef vector<lld> vi; 
typedef pair<lld,lld> pii;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007
#define int long long int


int a[10010],n;
int dp[10010];
#undef int
int main()
{
#define int long long int
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		if(n)
			dp[0] = a[0], dp[1] = max(a[0],a[1]);
		for(int i=2;i<n;i++)
			dp[i] = max(dp[i-1],dp[i-2]+a[i]);
		cout<<"Case "<<c<<": "<<((n>0) ? dp[n-1]:0LL)<<"\n";
	}
	return 0;
}      
