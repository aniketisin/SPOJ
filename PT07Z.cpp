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

pii a[10010];
vi adj[10010];
bool mark[10010];
int dfs(int node)
{
	mark[node] = 1;
	int ret = 0;
	int ff = 0,ss = 0;
	for(int i=0;i<adj[node].size();i++)
	{
		if(mark[adj[node][i]]) continue;
		int xx = dfs(adj[node][i]) + 1;
		if(xx>ff) {ss = ff;ff = xx;}
		else if(xx>ss) ss = xx;
	}
	a[node].F = ff; a[node].S = ss;
	return ff;
}

int main()
{
	int n;
	fill(mark,0);
	si(n);
	for(int i=0;i<n-1;i++)
	{
		int xx,yy;
		sii(xx,yy);
		adj[xx].pb(yy);
		adj[yy].pb(xx);
	}
	dfs(1);
	int ans = 0;
	for(int i=1;i<=n;i++) ans = max(ans,a[i].F+a[i].S);
	cout<<ans<<endl;
	return 0;
}      
