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

lld sum[1000010];
map<lld,lld> m;
int main()
{
	int t;
	si(t);
	while(t--)
	{
		m.clear();
		lld n;
		sl(n);
		lld ans=0;
		for(int i=0;i<n;i++)
		{	
			lld xx;
			sl(xx);
			if(i)
				sum[i] = sum[i-1]+xx;
			else
				sum[i] = xx;
			if(present(m,1LL*sum[i])) m[1LL*sum[i]]++;
			else m[1LL*sum[i]] = 1;
		}
		for(map<lld,lld> :: iterator it=m.begin();it!=m.end();it++)
		{
			lld c = (*it).S;
			ans+=(c*(c-1))/2;
			if((*it).F==0) ans+=c;
		}
		cout<<ans<<endl;
	}
	return 0;
}      
