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

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,xx,m;
		vi s1,s2;
		si(n);
		for(int i=0;i<n;i++) 
		{
			si(xx);
			s1.pb(xx);
		}
		si(m);
		for(int i=0;i<m;i++) 
		{
			si(xx);
			s2.pb(xx);
		}
		int ans = INF;
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		s2.pb(INF);
		for(int i=0;i<n;i++)
		{
			int idx = lower_bound(s2.begin(),s2.end()-1,s1[i]) - s2.begin();
			ans = min(ans,abs(s1[i]-s2[idx]));
			if(idx-1>=0)
				ans=min(ans,abs(s2[idx-1]-s1[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}      
