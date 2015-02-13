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

lld mat[4][4];
lld curr[4][4];
int msize;
lld c[4][4];
void mult(lld a[][4],lld b[][4])
{
	for(int i=0;i<msize;i++)
	{
		for(int j=0;j<msize;j++)
		{
			c[i][j] = 0;
			for(int k=0;k<msize;k++)
				c[i][j] += (a[i][k]*b[k][j])%mod;
			if(c[i][j] >= mod) c[i][j] %= mod;
		}
	}
	for(int i=0;i<msize;i++)
		for(int j=0;j<msize;j++)
			a[i][j] = c[i][j];
}

void mpow(lld pw)
{
	while(pw > 0)
	{
		if((pw&1))
			mult(curr,mat);
		mult(mat,mat);
		pw >>= 1;
	}
}

int main()
{
	int t;
	si(t);
	msize = 3;
	while(t--)
	{
		fill(mat,0);
		fill(curr,0);
		for(int i=0;i<4;i++)
			curr[i][i] = 1;
		
		mat[0][0] = mat[0][1] = mat[0][2] = 1;
		mat[1][0] = 1;
		mat[2][2] = 1;
		
		lld n,m;
		
		sl(n);sl(m);
		lld ff,ss;
		ff = ss = 0;
		if(n<=2) 
		{
			ss = n;
			ss = (n-1>=0) ? n-1 : 0;
		}
		if(m<=1) ff = m;
		if(m>=2)
		{
			mpow(m-1);
			ff = ((curr[0][0] %mod)  + (curr[0][2] %mod )) %mod;
		}

		fill(curr,0);
		fill(mat,0);
		for(int i=0;i<4;i++)
			curr[i][i] = 1;
		
		mat[0][0] = mat[0][1] = mat[0][2] = 1;
		mat[1][0] = 1;
		mat[2][2] = 1;
		if(n>2)
		{
			mpow(n - 2);
			ss = ((curr[0][0] %mod)  + (curr[0][2] %mod ) )%mod;
		}	
		cout<<(ff-ss + mod)%mod<<endl;
	}
	return 0;
}      
