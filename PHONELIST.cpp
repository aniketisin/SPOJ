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

int tr[1000010][11];
bool mark[1000010][11];
int next = 1;
bool build(string s)
{
	int i = 0;
	int v = 0;
	int ret = 0;
	while(i < s.length())
	{
		if(tr[v][s[i]] == -1)
		{
			v = tr[v][s[i]] = next++;
			if(ret==0)
				ret = 1;
		}
		else
			v = tr[v][s[i]];
		
		if(mark[v][s[i]] == 1 && ret==0) ret = -1;
		
		if(i==s.length()-1) 
			mark[v][s[i]] = 1;
		i++;
	}
	if(ret==-1) ret = 0;
	return ret;
}


int main()
{
	int t;
	si(t);
	while(t--)
	{
		next = 1;
		fill(tr,-1);
		fill(mark,0);
		int n;
		si(n);
		bool f = 1;
		string xx;
		for(int i=0;i<n;i++)
		{
			cin>>xx;
			if(f)
				f = build(xx);
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}      
