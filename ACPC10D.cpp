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

const int N = 1e5 + 10;
int a[N][3];
int dp[N][3];

int main()
{
	int n,k = 1;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		dp[1][0] = a[0][1] + a[1][0];
		dp[1][1] = a[0][1] + a[1][1];
		dp[1][1] = min(dp[1][1],dp[1][0]+a[1][1]);
		dp[1][1] = min(dp[1][1],a[0][1]+a[1][1] + a[0][2]);
		dp[1][2] = a[0][1] + a[1][2];
		dp[1][2] = min(dp[1][2],dp[1][1]+a[1][2]);
		dp[1][2] = min(dp[1][2],a[0][1]+a[0][2]+a[1][2]);
		for(int i=2;i<n;i++)
		{
			dp[i][0] = min(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][0]);
			dp[i][1] = min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2])) + a[i][1];
			dp[i][1] = min(dp[i][0] + a[i][1],dp[i][1]);
			dp[i][2] = min(dp[i-1][1],dp[i-1][2]) + a[i][2];
			dp[i][2] = min(dp[i][1] + a[i][2],dp[i][2]);
		}
		cout<<k<<". "<<dp[n-1][1]<<"\n";
		k++;
	}
	return 0;
}      
