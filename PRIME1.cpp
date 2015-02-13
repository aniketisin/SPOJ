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

const lld mx = 1e9 + 10;

bool a[mx];

int main()
{
	int t;
	lld n,m;
	fill(a,0);
	si(t);
	a[2] = a[3] = a[5] = a[7] = 1;
	while(t--)
	{
		sl(n);sl(m);
		for(int i=n;i<=m;i++)
		{
			if(i==1 || i&1==0)
				continue;
			if(a[i])
				printf("%d\n",i);
			else
			{
				int f = 0;
				if(i%6==1 || i%6==5)
				{
					for(int k=3;k*k<=i;k+=2)
					{
						if(i%k==0)
						{
							f=1;
							break;
						}
					}
					if(!f)
					{
						printf("%d\n",i);
						a[i] = 1;	
					}
				}
			}
		}
		putchar('\n');
	}
	return 0;
}      
