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

int dp[110][110],a[110][110];
int main()
{
	int n,m;
	sii(n,m);
	for(int i=0;i<110;i++)
		for(int j=0;j<110;j++)
			dp[i][j]=INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			si(a[i][j]);
	for(int i=0;i<m;i++) dp[0][i] = a[0][i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j==0)
			{
				dp[i][j] = min(dp[i-1][j]+a[i][j],dp[i][j]);
				if(j+1<m)
					dp[i][j] = min(dp[i][j],dp[i-1][j+1]+a[i][j]);
			}
			else
			{
				dp[i][j] = min(dp[i-1][j-1]+a[i][j],min(dp[i-1][j]+a[i][j],dp[i][j]));
				if(j+1<m)
					dp[i][j] = min(dp[i][j],dp[i-1][j+1]+a[i][j]);

			}
		}
	}
	int mn = INF;
	for(int i=0;i<m;i++)
		mn = min(mn,dp[n-1][i]);
	cout<<mn<<endl;
}      
