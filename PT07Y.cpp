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

int par[11000];

int get(int xx)
{
	if(par[xx]!=-1)
		return get(par[xx]);
	return xx;
}

void set_par(int xx,int yy)
{
	if(par[xx]!=-1) set_par(par[xx],yy);
	else par[yy] = xx;
}

int main()
{
	int n,m;
	sii(n,m);
	bool mark[11000],f=0;
	set< pii > s;
	fill(mark,0);
	fill(par,-1);
	for(int i=0;i<m;i++)
	{
		int xx,yy;
		sii(xx,yy);
		xx--;yy--;
		if(get(xx) == get(yy)) f=1;
		else 
		{
			set_par(max(xx,yy),min(xx,yy));
			s.insert(mp(min(xx,yy),max(xx,yy)));
		}
	}
	if(s.size()!=n-1) f = 1;
	if(f) cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}      
