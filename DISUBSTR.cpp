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

int z[1100][1100],n;
string s;
void zFunc(int k)
{
	int L,R;
	L = R = k;
	for(int i=k+1;i<n;i++)
	{
		if(i>R)
		{
			L = R = i;
			while(R<n && s[R-L+k] == s[R]) R++;
			z[k][i-k] = R-L; R--;
		}
		else
		{
			int j = i-L+k;
			if(z[k][j-k] < R-i+1) z[k][i-k] = z[k][j-k];
			else
			{
				L = i;
				while(R<n && s[R-L+k] == s[R]) R++;
				z[k][i-k] = R-L;R--;
			}
		}
	}
}


int main()
{
	int t;
	si(t);
	while(t--)
	{
		fill(z,0);
		cin>>s;
		n = s.length();
		int ans = 0;
		for(int i=0;i<n;i++) zFunc(i);
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i;j++)
				cout<<z[i][j]<<" ";
			cout<<endl;
		}*/
		for(int i=0;i<n;i++)
		{
			int mx = 0;
			for(int j=0;j<i;j++)
				mx = max(z[j][i-j],mx);
			ans += n - i - mx;
		}
		cout<<ans<<endl;
	}
	return 0;
}      
