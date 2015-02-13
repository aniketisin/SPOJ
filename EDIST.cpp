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

char  a[2010],b[2010];
int n,m;
lld dp[2010][2010];
lld edist(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	if(j==m && i==n) return 0;
	if(j==m) return abs(n-i);
	if(i==n) return abs(m-j);
	lld r1 = edist(i+1,j+1) + (lld)(a[i]!=b[j]);
	lld r2 = edist(i,j+1) + 1;
	lld r3 = edist(i+1,j) + 1;
	dp[i][j] = min(min(r1,r2),r3);
	return dp[i][j];
}


int main()
{
	int t;
	si(t);
	while(t--)
	{
		fill(dp,-1);
		ss(a);ss(b);
		n = strlen(a);
		m = strlen(b);
		cout<<edist(0,0)<<endl;
	}
	return 0;
}      
