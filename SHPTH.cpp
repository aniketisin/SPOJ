#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007

vi adj[10010],costs[10010];
map<string, int> m;
int best[10010];
int main()
{
	std::ios::sync_with_stdio(false);
	int t,n,p,xx,yy;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<10010;i++)
		{
			adj[i].clear();
			costs[i].clear();
		}
		m.clear();
		for(int i=0;i<n;i++)
		{
			cin>>s>>p;
			m[s] = i;
			for(int j=0;j<p;j++)
			{
				cin>>xx>>yy;
				xx--;
				adj[i].pb(xx);
				costs[i].pb(yy);
			}
		}
		int r;
		cin>>r;
		while(r--)
		{
			for(int i=0;i<n;i++) best[i] = INF;
			string s1,s2;
			cin>>s1>>s2;
			int ans = 0;
			int u = m[s1];
			int v = m[s2];
			priority_queue< pii , vector< pii > , greater< pii > > pq;
			pq.push(mp(0,u));
			while(!pq.empty())
			{
				int ss = pq.top().S;
				int dd = pq.top().F;
				if( ss == v) break;
				pq.pop();
				for(int i=0;i<adj[ss].sz;i++)
				{
					xx = adj[ss][i];
					yy = costs[ss][i];
					if(yy + dd < best[xx])
					{
						best[xx] = yy + dd;
						pq.push(mp(best[xx],xx));
					}
				}
			}
			cout<<best[v]<<"\n";
		}
	}
	return 0;
}

