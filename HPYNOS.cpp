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
	unsigned long long int n,cnt=0,ans;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	while(n>9)
	{
		char a[100];
		sprintf(a,"%llu",n);
		int l = strlen(a);
		ans = 0;
		for(int i=0;i<l;i++)
			ans += 1ULL*(a[i]-'0')*(a[i]-'0');
		n = ans;
		cnt++;
	}
	if(n==7) cout<<cnt+5ULL<<endl;
	else if(n==1) cout<<cnt<<endl;
	else cout<<"-1\n";
	return 0;
}      
