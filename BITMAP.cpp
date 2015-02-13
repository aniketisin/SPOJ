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

int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};

bool v(int i,int j,int n, int m)
{
	if(i>=n || j>=m || i<0 || j<0)
		return 0;
	return 1;
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,m;
		sii(n,m);
		queue< pii > q;
		string a[185];
		for(int i=0;i<n;i++) cin>>a[i];
		int node[185][185];
		bool vis[185][185];
		fill(node,INF);
		fill(vis,0);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) 
				if(a[i][j]=='1') 
				{
					q.push(mp(i,j));
					node[i][j]=0;
					vis[i][j] = 1;
				}
		while(!q.empty())
		{
			pii tmp = q.front();
			int xx = tmp.F;
			int yy = tmp.S;
			q.pop();
			for(int i=0;i<4;i++)
			{
				if(!v(xx+x[i],yy+y[i],n,m) || vis[xx+x[i]][yy+y[i]]) continue;
				node[xx+x[i]][yy+y[i]] = node[xx][yy]+1;
				vis[xx+x[i]][yy+y[i]]=1;
				q.push(mp(xx+x[i],yy+y[i]));
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) cout<<node[i][j]<<" ";
			cout<<endl;
		}

	}
	return 0;
}      
