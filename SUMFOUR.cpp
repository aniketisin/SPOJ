#include<bits/stdc++.h>
using namespace std;

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

int ff[16000010];
int ss[16000010];
int a[4][4010];

int main()
{
	int xx,n,yy;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[0][i],&a[1][i],&a[2][i],&a[3][i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			ff[i*n+j] = a[0][i]+a[1][j];
			ss[i*n+j] = a[2][i]+a[3][j];
		}
	sort(ff,ff+n*n);
	sort(ss,ss+n*n);
	lld ans = 0;
	for(int i=0;i<n*n;)
	{
		int j=i;
		lld val;
		while(i<n*n && ss[i]==ss[j])i++; val = i-j;
		int *x = lower_bound(ff,ff+n*n,-ss[j]);
		int *y = upper_bound(ff,ff+n*n,-ss[j]);
		ans+=(y-x)*val;
	}
	printf("%lld\n",ans);
	//cout<<ans<<"\n";
	return 0;

}      
