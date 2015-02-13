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
	string a;
	while(cin >> a)
	{
		if(a == "0")
			break;
		lld dp[5010];
		fill(dp,0);
		dp[0] = 1;
		dp[1] = (a[1]=='0' ? 0 : 1) + (lld)((a[0]-'0')*10 + a[1] - '0' <=26  && a[0]>'0');
		int l = a.length();
		for(int i=2;i<l;i++)
			dp[i] = (a[i]=='0'? 0LL : dp[i-1]) + (((a[i-1]-'0')*10 + a[i] - '0' <=26 && a[i-1]>'0') ? dp[i-2] : 0LL);
		cout<<dp[l-1]<<endl;
	}
	return 0;
}      
