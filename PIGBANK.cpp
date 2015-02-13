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

lld dp[10010];
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int bef,after;
		sii(bef,after);
		int n = after-bef;
		int m;
		si(m);
		if(n<0) {cout<<"This is impossible.\n"; continue;}
		pii a[510];
		fill(dp, 0);
		for(int i=1;i<=m;i++)
		{
			int xx,yy;
			sii(xx,yy);
			a[i] = mp(xx,yy);
		}
		for(int j=0;j<=n;j++)
		{
			for(int i=1;i<=m;i++)
			{
				lld tmp = INF;
				if(dp[j]!=0) tmp = dp[j];
				if(j - a[i].S > 0 && dp[j-a[i].S]!=0)
					dp[j] = dp[j-a[i].S]+a[i].F;
				dp[j] = min(tmp,dp[j]);
				lld tmp1 = (j==a[i].S) ? a[i].F : 0;
				if(dp[j]==0) dp[j] = tmp1;
				else if(tmp1!=0) dp[j] = min(dp[j],tmp1);

			}
		}
		if(dp[n]==0) {cout<<"This is impossible.\n"; continue;}
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[n]<<"."<<endl;
	}
	return 0;
}     
