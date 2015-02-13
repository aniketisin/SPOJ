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
lld dp[13][100];

lld solve(int i,int j)
{
	if(i==0 && j==0) return 1LL;
	if(i<=0 || j<0 || j>((i)*(i-1))/2) return 0LL;
	if(j==0) return 1LL;
	if(dp[i][j] != -1) return dp[i][j];
	lld ret = 0;
	for(int p=0;p<i;p++)
		ret+= solve(i-1,j-p);
	dp[i][j] = ret;
	return ret;
}

int main()
{
	int t;
	si(t);
	fill(dp,-1);
	while(t--)
	{
		int xx,yy;
		sii(xx,yy);
		cout<<solve(xx,yy)<<"\n";
	}
	return 0;
}      
