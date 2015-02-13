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
	char a[210][210],c;
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		getchar();
		int k = 0,j=0,t = 1;
		while(1)
		{
			c=getchar();
			if(c=='\n')
				break;
			a[k][j] = c;
			j+=t;
			if(j==n || j<0)
			{
				j-=t;
				t*=-1;
				k++;
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<k;j++)
				printf("%c",a[j][i]);
		putchar('\n');
	}
	return 0;
}      
