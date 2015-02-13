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
	int n,m;
	while(cin>>n)
	{
		if(n==0) break;
		vi a,b;
		int sum1[10020];
		int sum2[10020];
		fill(sum1,0);
		fill(sum2,0);
		vector< pii > in;
		for(int i=0;i<n;i++)
		{
			int xx;
			si(xx);
			a.pb(xx);
			if(i) sum1[i] = sum1[i-1] + xx;
			else sum1[i] = xx;
		}
		si(m);
		for(int i=0;i<m;i++)
		{
			int xx;
			si(xx);
			b.pb(xx);
			if(i) sum2[i] = sum2[i-1] + xx;
			else sum2[i] = xx;
		}
		for(int i=0;i<n;i++)
		{
			int idx = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
			if(b[idx]==a[i])
				in.pb(mp(i,idx));
		}
		in.pb(mp(n-1,m-1));
		int ans = max(sum1[n-1],sum2[m-1]);

		int ans2 = 0;
		if(in.size()) ans2 = max(sum1[in[0].F],sum2[in[0].S]);
		for(int i=1;i<in.size();i++)
			ans2+= max(sum1[in[i].F]-sum1[in[i-1].F],sum2[in[i].S]-sum2[in[i-1].S]);
		cout<<max(ans,ans2)<<endl;
	}
	return 0;
}      
