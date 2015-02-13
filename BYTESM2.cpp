#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

/*-----Fast I/O-----*/
inline void inp( int &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
/*-----End of Fast I/O-----*/

typedef long long int lld;

#define sz(a)                        int((a).size()) 
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define present(c,x)                 ((c).find(x) != (c).end()) 
#define si(n)                        inp(n)
#define sl(n)                        scanf("%lld",&n)
#define ss(n)                        scanf("%s",n)
#define sii(n,m)		     inp(n);inp(m)
#define siii(n,m,r)		     inp(n);inp(m);inp(r)
#define abs(x)                       ((x)<0?-(x):(x))
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define mod 1000000007
#define max(a,b)		     ((a>b) ? a:b)

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,m;
		sii(n,m);
		int a[110][110];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) si(a[i][j]);
		lld dp[110][110];
		fill(dp,-100LL);
		for(int i=1;i<=m;i++) dp[1][i] = a[1][i];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j] = max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
				dp[i][j] = max(dp[i-1][j+1]+a[i][j],dp[i][j]);
			}
		}
		lld ans = 0;
		for(int i=1;i<=m;i++) ans = max(ans,dp[n][i]);
		cout<<ans<<endl;
	}
	return 0;
}      
