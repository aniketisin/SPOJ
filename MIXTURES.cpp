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

pii dp[110][110];
int a[110];
pii solve(int s,int e)
{
	if(dp[s][e]!=mp(-1,-1)) return dp[s][e];
	if(e==s) return mp(0,a[s]%100);
	if(e-s == 1) return mp(a[e]*a[s],(a[e]+a[s])%100);
	int ret1=INF,ret2;
	for(int i=s;i<e;i++)
	{
		pii xx = solve(s,i);
		pii yy = solve(i+1,e);
		int pp = (xx.S%100)*(yy.S%100) + xx.F+yy.F;
		if(pp < ret1) {ret1 = pp; ret2 = (xx.S + yy.S)%100;}
	}
	dp[s][e] = mp(ret1,ret2);
	return dp[s][e];

}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<110;i++)
			for(int j=0;j<110;j++) dp[i][j] = mp(-1,-1);
		for(int i=0;i<n;i++)
			si(a[i]);
		cout<<solve(0,n-1).F<<endl;
	}
	return 0;
}      
