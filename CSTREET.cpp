#include<bits/stdc++.h>
using namespace std;

/*-----Fast I/O-----*/
inline void inp( int &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
/*-----End of Fast I/O-----*/

typedef vector<int> vi; 
typedef pair<int,int> pii;

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
#define int long long

const int N = 300010;
int p,n,m;
int par[1010];
vector< pair<int , pii> > v;

int root(int x)
{
	if(par[x]<0) return x;
	return root(par[x]);
}

void join(int x ,int y)
{
	x = root(x);
	y = root(y);
	par[x] = y;
}


#undef int
int main()
{
#define int long long
	cout.sync_with_stdio(true);
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		fill(par,-1);
		cin>>p>>n>>m;
		for(int i=0;i<m;i++)
		{
			int xx,yy,zz;
			cin >> xx >> yy >> zz;
			v.pb(mp(zz,mp(xx,yy)));
			//v.pb(mp(zz,mp(yy,xx)));
		}
		sort(v.begin(),v.end());
		int ans = 0;
		for(int i = 0,c = 0;i < m && c < n - 1; i++)
		{
			int uu = v[i].S.F, vv = v[i].S.S;
			if(root(uu) == root(vv)) continue;
			join(uu,vv);
			c++;
			ans += v[i].F * p;
		}
		cout<<ans<<"\n";
	}
	return 0;
}     
