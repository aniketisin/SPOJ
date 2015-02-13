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

bool prime[100010];
void pre()
{
	bool mark[100010];
	fill(mark,0);
	fill(prime,0);
	for(int i=2;i<100010;i++)
	{
		if(mark[i]) continue;
		mark[i] = 1;
		prime[i] = 1;
		//cout<<i<<"\n";
		for(int j=2*i;j<100010;j+=i)
			mark[j] = 1;
	}
}

int main()
{
	pre();
	int t;
	si(t);
	while(t--)
	{
		string s,e;
		cin>>s>>e;
		queue<string> q;
		int dist[100010];
		for(int i=0;i<100010;i++) dist[i] = INF;
		int xx = atoi(s.c_str());
		dist[xx] = 0;
		q.push(s);
		while(!q.empty())
		{
			string yy = q.front();
			int p = atoi(yy.c_str());
			q.pop();
			for(int i=0;i<yy.length();i++)
			{
				for(int j=0;j<10;j++)
				{
					if((i==0 && j==0) || yy[i]==j+'0') continue;
					char tmp = yy[i];
					yy[i] = j+'0';
					xx = atoi(yy.c_str());
					if(!prime[xx]) 
					{
						yy[i] = tmp;
						continue;
					}
					if(dist[xx]>dist[p]+1)
					{
						dist[xx] = dist[p]+1;
						//cout<<xx<<" "<<dist[xx]<<"\n";
						q.push(yy);
					}
					yy[i] = tmp;
				}
			}
			/*while(!q.empty())
			{	cout<<q.front()<<"\n";
				q.pop();
			}*/
		}
		cout<<dist[atoi(e.c_str())]<<"\n";
	}
	return 0;
}      
