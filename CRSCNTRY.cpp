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

lld dp[2010][2010];

lld lcs(int a[], int b[], int x, int y)
{
	if(x<0 || y<0) return 0LL;
	if(dp[x][y]!=-1) return dp[x][y];
	lld ret = 0;
	ret = max(lcs(a,b,x-1,y-1)+(lld)(a[x]==b[y]),max(lcs(a,b,x-1,y),lcs(a,b,x,y-1)));
	dp[x][y] = ret;
	return ret;
}

int main()
{
	int n,m;
	int t,xx;
	cin>>t;
	while(t--)
	{
		int a[2010],l1 = 0;
		int b[2010];
		int o = 0;
		lld ans = 0;
		while(cin>>xx && xx!=0)
			a[o++] = xx;
		l1 = o;
		while(cin>>xx && xx!=0)
		{
			fill(dp,-1);
			o = 1;
			b[0] = xx;
			while(cin>>xx && xx!=0)
				b[o++] = xx;
			ans = max(ans,lcs(a,b,l1-1,o-1));
		}
		cout<<ans<<"\n";
	}
	return 0;

}      
