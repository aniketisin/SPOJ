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

struct fenwick
{

	int size;
	vi ft;
	fenwick(int n)
	{
		size = n;
		ft.resize(n+1);
	}
	
	lld sum(int b)
	{
		lld sum = 0;
		for(;b ;b -= (b&(-b))) 
			sum += ft[b];
		return sum;
	}

	lld sum(int a,int b)
	{
		return sum(b) - ( a <= 1? 0 : sum(a-1));
	}

	void update(int k, int v)
	{
		for(;k<=size; k += (k&(-k))) ft[k]+=v;
	}
	
};

int main()
{
	int t;
	si(t);
	getchar();
	while(t--)
	{
		getchar();
		int n,xx;
		vi a,b;
		si(n);
		getchar();
		fenwick f(n);
		for(int i=0;i<n;i++) {scanf("%d",&xx); a.pb(xx);}
		b = a;
		sort(b.begin(),b.end());
		for(int i=0;i<n;i++)
		{
			int idx = lower_bound(b.begin(),b.end(),a[i])-b.begin();
			a[i] = idx+1;
		}
		lld inv=0;
		for(int i=n-1;i>=0;i--)
		{
			inv += f.sum(a[i]);
			f.update(a[i],1);
		}
		cout<<inv<<endl;
	}
	return 0;
}      
