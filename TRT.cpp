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

vi a;
int dp[2010][2010];
lld solve(int s,int e,int t)
{
	if(s>e) return 0;
	if(s==e) return a[s]*t;
	if(dp[s][e] != -1) return dp[s][e];
	lld ret = max(a[s]*t + solve(s+1,e,t+1),a[e]*t + solve(s,e-1,t+1));
	dp[s][e] = ret;
	return ret;
}

int main()
{
	int n,xx;
	si(n);
	fill(dp,-1);
	for(int i=0;i<n;i++){si(xx); a.pb(xx);}
	cout<<solve(0,n-1,1)<<endl;
	return 0;
}      
