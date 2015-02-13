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

vi a[1000005];
short b[1000005];
bool ok;
int main()
{
	int t,s=1;
	si(t);
	while(t--)
	{
		ok = 1;
		int xx,yy,n,m;
		sii(n,m);
		for(int i=1;i<=n;i++) 
		{ a[i].clear(); b[i] = -1;}
		for(int i=0;i<m;i++)
		{
			sii(xx,yy);
			a[xx].pb(yy);
			a[yy].pb(xx);
		}
		for(int i=1;i<=n;i++)
		{
			queue<int> q;
			if(b[i]!=-1) continue;
			q.push(i);
			b[i] = 1;
			while(!q.empty())
			{
				int n = q.front();
				q.pop();
				for(int i=0;i<a[n].size();i++)
				{
					if(b[a[n][i]] == -1)
					{
						b[a[n][i]] = b[n]^1;
						q.push(a[n][i]);
					}
					else if(b[a[n][i]]==b[n])
					{
						ok = 0;
						break;
					}
				}
				if(!ok) break;
			}
			if(!ok) break;
		}
		cout<<"Scenario #"<<s<<":\n";
		if(ok==1) cout<<"No suspicious bugs found!\n";
		else cout<<"Suspicious bugs found!\n";
		s++;
	}
	return 0;
}      
