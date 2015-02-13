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

lld memo[52][52][52][52];

lld F(int dig,int three_count,int six_count,int nine_count)
{
	if(dig==0)
		return (lld)((three_count==six_count) && (six_count==nine_count) && three_count>=1);
	if(memo[dig][three_count][six_count][nine_count] != -1)
		return memo[dig][three_count][six_count][nine_count];
	lld ret = 0LL;
	ret += (1LL*3*((F(dig-1,three_count+1, six_count, nine_count))%mod))%mod;
	ret %= mod;
	ret += (1LL*7*((F(dig-1,three_count, six_count, nine_count))%mod))%mod;
	ret %= mod;
	memo[dig][three_count][six_count][nine_count] = ret;
	memo[dig][three_count][nine_count][six_count] = ret;
	memo[dig][six_count][three_count][nine_count] = ret;
	memo[dig][six_count][nine_count][three_count] = ret;
	memo[dig][nine_count][three_count][six_count] = ret;
	memo[dig][nine_count][six_count][three_count] = ret;
	return ret;
}

lld solve(char buff[])
{
	int l = strlen(buff);
	lld ans = 0;
	int three_count,six_count,nine_count;
	three_count = six_count = nine_count = 0;
	int j = l;
	for(int i=0;i<l;i++)
	{
		j--;
		int d = buff[i] - '0';
		int xx = d;
		lld tmp = 0LL;
		if(d>3)
		{
			tmp += (F(j,three_count+1, six_count, nine_count))%mod;
			tmp %= mod;
			xx--;
		}
		if(d>6)
		{
			tmp <<= 1;
			tmp %= mod;
			xx--;
		}
		ans += (1LL*xx*((F(j,three_count, six_count, nine_count))%mod))%mod;
		ans %= mod;
		ans += tmp;
		ans %= mod;
		if(d==3) three_count++;
		if(d==6) six_count++;
		if(d==9) nine_count++;
	}
	return ans;
}

int main()
{
	int t;
	si(t);
	fill(memo,-1);
	while(t--)
	{
		char a[60],b[60];
		int c1,c2,c3,p=0;
		c1 = c2 = c3 = 0;
		ss(a);ss(b);
		for(int i=0;i<strlen(b);i++)
		{
			if(b[i]=='3') c1++;
			if(b[i]=='6') c2++;
			if(b[i]=='9') c3++;
		}
		if(c1==c2 && c2==c3 && c1>0)
			p=1;
		printf("%lld\n",((solve(b) - solve(a)) + p + mod)%mod);
	}
	return 0;
}      
