#include<bits/stdc++.h>
using namespace std;

/*-----Fast I/O-----*/
inline void inp( int &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
/*-----End of Fast I/O-----*/

typedef vector<int> vi; 
typedef pair<int,int> pii;
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
#define INF                          INT_MAX
#define mod 1000000007

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) return 0;
		
		int dp[110][510];
		pii party[110];
		fill(dp,0);
		for(int i=0;i<m;i++)
		{
			int xx,yy;
			sii(xx,yy);
			party[i].F=xx;
			party[i].S=yy;
		}
		pii ans = mp(0,INT_MIN);
		int mx = INT_MIN;
		for(int j=1;j<=n;j++)
		{
			dp[0][j] = (party[0].F == j) ? party[0].S : 0;
			for(int i=1;i<m;i++)
			{
				dp[i][j] = dp[i-1][j];
				if(j - party[i].F >=0) dp[i][j] = max(dp[i-1][j-party[i].F] + party[i].S,dp[i][j]);
			}
			if(dp[m-1][j]>mx) {ans = mp(j,dp[m-1][j]);mx=dp[m-1][j];}
		}
		cout<<ans.F<<" "<<ans.S<<endl;
	}
	return 0;
}      
