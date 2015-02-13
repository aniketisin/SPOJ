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

vi primes;
vi factors[1010];
bool mark[1010];
void prime()
{
	for(int i=2;i<1010;i++)
	{
		if(mark[i])
			continue;
		primes.pb(i);
		factors[i].pb(i);
		mark[i] = 1;
		for(int j=2*i;j<1010;j+=i)
		{
			mark[j] = 1;
			factors[j].pb(i);
		}
	}
}

int main()
{
	int n;
	fill(mark,0);
	prime();
	si(n);
	lld ans = 1;
	for(int i=2;i<=n;i++)
	{
		int cnt = 0;
		cout<<"no-> "<<i<<" factors ";
		for(int x : factors[i])
		{
			cout<<x<<" ";
			int j = i;
			while(j%x==0)
			{
				j/=x;
				cnt++;
			}
		}
		cout<<"  "<<cnt<<endl;
		ans += 1LL<<(cnt-1);
	}
	printf("%lld\n",ans);
	return 0;
}      
