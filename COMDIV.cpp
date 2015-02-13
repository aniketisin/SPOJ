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

const int mx = 1e6+13;
vi prime;
void pre()
{
	bool mark[1010];
	fill(mark,0);
	for(int i=2;i<1010;i++)
	{
		if(mark[i]) continue;
		mark[i] = 1;
		prime.pb(i);
		for(int j=2*i;j<1010;j+=i)
			mark[j]++;
	}
}

int main()
{
	pre();
	int t;
	si(t);
	while(t--)
	{
		int a,b;
		sii(a,b);
		int xx = __gcd(a,b);
		lld ans = 1;
		for(int i=0;i<prime.size();i++)
		{
			if(prime[i]>xx) break;
			if(xx%prime[i]==0)
			{
				int c = 0;
				while(xx%prime[i]==0)
				{
					c++;
					xx/=prime[i];
				}
				ans*=1LL*(c+1);
			}
		}
		if(xx>1) ans<<=1;
		printf("%lld\n",ans);
	}
	return 0;
}      
