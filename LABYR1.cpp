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

string a[1010];
int m,n,ans = -1;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
bool vis[1010][1010];
pii solve(pii v)
{
	if(vis[v.F][v.S]) return mp(0,0);
	vis[v.F][v.S]=1;
	int ff=0,ss=0;
	for(int i=0;i<4;i++)
	{
		int xx = v.F+x[i];
		int yy = v.S+y[i];
		if(xx<0 || yy<0 || xx>=n || yy>=m || a[xx][yy]=='#' || vis[xx][yy])
			continue;
		int tmp = solve(mp(xx,yy)).F + 1;
		if(tmp>=ff) ss=ff,ff=tmp;
		else if(tmp>ss) ss=tmp;
	}
	ans = max(ans,ff+ss);
	return mp(ff,ss);
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		sii(m,n);
		fill(vis,0);
		pii s;
		for(int i=0;i<n;i++)
			cin>>a[i];
		ans = -1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(vis[i][j] || a[i][j]=='#') continue;
				else
					pii xx = solve(mp(i,j));
		cout<<"Maximum rope length is "<<ans<<".\n";
	}
	return 0;
}      
