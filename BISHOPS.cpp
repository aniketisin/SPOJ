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
	while(cin>>a)
	{
		if(a=="1")
		{
			cout<<1<<endl;
			continue;
		}
		a = "0" + a;
		int l = a.length(),c = 0;
		for(int i=l-1;i>=0;i--)
		{
			a[i] -= '0';
			a[i] = a[i]*2 + c;
			c = a[i]/10;
			a[i] = a[i]%10;
			a[i] += '0';
		}
		if(a[l-1] == '0') 
		{
			a[l-1] = '8';
			int k = l-2;
			while(a[k]=='0') 
			{ a[k]='9'; k--; }
			a[k]--;
		}
		else a[l-1] -=2;
		int k = 0;
		while(a[k]=='0') k++;
		a.erase(0,k);
		cout<<a<<endl;;
	}
}      
