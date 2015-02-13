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

int main()
{
	int t;
	si(t);
	int a[4][5];
	fill(a,0);
	while(t--)
	{
		int n,m;
		char c;
		cin>>n>>c>>m;
		a[n][m]++;
	}
//	cout<<a[3][4]<<" "<<a[1][2]<<" "<<a[1][4]<<endl;
	lld ans = 0;
	ans += min(a[3][4],a[1][4]);
	a[3][4] -= ans;
	a[1][4] -= ans;
	int tmp = a[1][2];
	tmp >>=1;
	ans += tmp;
	a[1][2] = (int)(a[1][2]&1);
	tmp = a[1][4];
	tmp = a[1][4]/4;
	ans+=tmp;
	a[1][4] = a[1][4]%4;
	if(a[1][4]>=1)
	{
		if(a[1][2])
		{
			a[1][2] = 0;
			ans+=1;
			if(a[1][4]<3)
				a[1][4] = 0;
			else
				a[1][4] = 1;
		}
	}
	while(a[3][4]--) ans++;
	while(a[1][2]--) ans++;
	while(a[1][4]--)
	{
		if(a[1][4]>=2) {a[1][4] = 0;ans++;}
		else ans++;
	}
	cout<<ans+1LL<<endl;
	return 0;
}      
