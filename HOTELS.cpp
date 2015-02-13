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
vector<lld> sum;
int n,m;

int main()
{
	sii(n,m);
	int xx;
	sum.resize(n);
	for(int i=0;i<n;i++) 
	{
		si(xx);
		a.pb(xx);
		if(i) sum[i] = sum[i-1] + xx;
		else sum[i] = xx;
	}
	lld ans = sum[0];
	for(int i=1;i<n;i++)
	{
		int xx = upper_bound(sum.begin(),sum.end(),1LL*(sum[i]-m-1)) - sum.begin();
		if(xx!=m)
			ans = max(ans,sum[i]-sum[xx]);
	}
	cout<<ans<<endl;
	return 0;
}      
