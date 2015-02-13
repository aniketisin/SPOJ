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

string a[30];
bool vis[30][30];
int n,m,yes = 0;
int x[] = {0,1,-1,0};
int y[] = {-1,0,0,1};
bool valid(int a,int b)
{
	if(a>=n || b>=m || a<0 || b<0) return 0;
	return 1;
}
void dfs(pii s,pii e)
{
	if(s==e) 
	{
		yes = 1;
		return;
	}
	if(vis[s.F][s.S]) return;
	vis[s.F][s.S] = 1;
	for(int i=0;i<4;i++)
	{
		int xx = s.F+x[i];
		int yy = s.S+y[i];
		if(valid(xx,yy) && a[xx][yy]!='#') dfs(mp(xx,yy),e);
	}
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int c=0;
		yes = 0;
		vector< pii > pnt;
		sii(n,m);
		fill(vis,0);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) 
		{
			if(a[0][i]=='.') 
				pnt.pb(mp(0,i));
			if(a[n-1][i]=='.' && n-1!=0)
				pnt.pb(mp(n-1,i));
		}
		for(int i=1;i<n-1;i++)
		{
			if(a[i][0]=='.')
				pnt.pb(mp(i,0));
			if(a[i][m-1]=='.' && m-1!=0)
				pnt.pb(mp(i,m-1));
		}
		if(pnt.size()!=2) {cout<<"invalid\n"; continue;}
		dfs(pnt[0],pnt[1]);
		if(yes) cout<<"valid\n";
		else cout<<"invalid\n";
	}
	return 0;
}      
