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
	int t;
	si(t);
	while(t--)
	{
		string a;
		cin >> a;
		bool done = 0;
		int s = 0;
		int e = a.length() - 1;
		bool nines = 1;
		for(int i=0;i<=e;i++)
			if(a[i] != '9')
			{ nines = 0; break;}
		if(nines)
		{
			cout<<"1";
			for(int i=0;i<e;i++) cout<<"0";
			cout<<"1\n";
			continue;
		}
		while(s<e)
		{
			if(done)
			{
				if(a[s] > a[e]) a[e] = a[s];
				else if(a[s] < a[e] ) {a[e] = a[s]; done = 0;}
				s++;e--;
				continue;
			}
			if(a[s] > a[e])
			{
				a[e] = a[s];
				done = 1;
			}
			else if(a[e] > a[s])
			{
				a[e] = a[s];
			}
			s++; e--;
		}
		if(!done) 
		{
			swap(s,e);
			if(a[s] != '9')
				a[s] = a[e] = a[s] + 1;
			else
			{
				while(a[s]==a[e] && a[s] == '9')
				{
					a[s] = a[e] = '0';
					s--;e++;
				}
				if(a[s]==a[e]) a[s] = a[e] = a[s] + 1;
				else {a[s] = a[e] = '0'; a[s-1] = a[e+1] = a[s-1]+ 1;}
			}
		}
		cout<<a<<endl;
	}
	return 0;
}      
