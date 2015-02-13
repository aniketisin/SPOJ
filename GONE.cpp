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

bool memo[100][100];
lld D[100][100];
int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};


bool isPrime(lld x)
{
	if(x<0)
		return 0;
	for(int i=0;i<29;i++)
		if(prms[i]==x)
			return 1;
	return 0;
}

//f=1 ==> even else odd
lld F(int dig,int sum)
{
	if(dig==0)
		return (lld)(isPrime(sum));
	if(memo[dig][sum])
		return D[dig][sum];
	memo[dig][sum]=1;
	lld ret = 0LL;
	for(int i=0;i<10;i++)
		ret+=F(dig-1,sum+i);
	D[dig][sum] = ret;
	return ret;
}

lld solve(lld x)
{
	lld ans = 0LL;
	lld sum;
	sum = 0;
	char buff[50];
	sprintf(buff,"%lld",x);
	int l = strlen(buff);
	int j = l;
	for(int i=0;i<l;i++)
	{
		j--;
		int d = buff[i]-'0';
		for(int k=0;k<d;k++)
			ans+=F(j,sum+k);
		sum+=d;
	}
	return ans;
}

int main()
{
	int t;
	si(t);
	fill(memo,false);
	while(t--)
	{
		lld a,b;
		sl(a);sl(b);
		printf("%lld\n",solve(b+1)-solve(a));
	}
	return 0;
}      
