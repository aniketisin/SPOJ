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

map<string,int> m;

int main()
{
	int t;
	si(t);
	while(t--)
	{
		m["HHH"] = m["HHT"] = m["HTH"] = m["HTT"] = 0;
		m["TTT"] = m["TTH"] = m["THT"] = m["THH" ] = 0;
		int c;
		char ch;
		string a="";
		si(c);
		a += getchar();
		a +=getchar();
		a +=getchar();
		m[a]++;
		for(int i=0;i<37;i++)
		{
			a.erase(0,1);
			a += getchar();
			m[a]++;
		}
		getchar();
		cout<<c<<" "<<m["TTT"]<<" "<<m["TTH"]<<" "<<m["THT"]<<" "<<m["THH"]<<" "<<m["HTT"]<<" "<<m["HTH"]<<" "<<m["HHT"]<<" "<<m["HHH"]<<endl;
	}
	return 0;
}      
