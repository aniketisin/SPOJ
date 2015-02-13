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

vector<int>  a;

int main()
{
	int k = 2;
	int tmp = 1;
	while(tmp < 10000010)
	{
		a.pb(tmp);
		tmp = k*(k+1)/2;
		k++;
	}
	int t;
	si(t);
	while(t--)
	{
		int n,m;
		int ans1,ans2;
		si(n);
		m = n;
		int idx = lower_bound(a.begin(),a.end(),n) - a.begin() -1;
		if(a[idx] == n)
			idx--;
		idx++;
		int sum = idx+2;
		n -= a[idx-1];
		ans2 = sum - n;
		ans1 = sum - ans2;
		if(sum%2==0)
			swap(ans1,ans2);
		cout<<"TERM "<<m<<" IS "<<ans1<<"/"<<ans2<<endl;
	}
	return 0;
	
}      
