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
vi ff,ss;

int main()
{
	int n;
	map<int,int> m1,m2;
	si(n);
	int a[110];
	for(int i=0;i<n;i++)
		si(a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				int r = a[i]*a[j] + a[k];
				ff.pb(r);
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(a[k]!=0)
				{
					int r = (a[i]+a[j])*a[k];
					ss.pb(r);
				}
	sort(ss.begin(),ss.end());
	int ans = 0;
	pair<vector<int> :: iterator, vector<int> :: iterator > xx;
	for(int i=0;i<ff.size();i++)
	{
		xx = equal_range(ss.begin(),ss.end(),ff[i]);
		ans+=(xx.S-ss.begin())-(xx.F-ss.begin());
	}
	printf("%d\n",ans);
	return 0;
}      
