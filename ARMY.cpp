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
		getchar();
		multiset<int> s1,s2;
		int n,m;
		sii(n,m);
		int xx;
		for(int i=0;i<n;i++){ si(xx); s1.insert(xx); }
		for(int i=0;i<m;i++){ si(xx); s2.insert(xx); }
		while(!s1.empty() && !s2.empty())
		{
			set<int> :: iterator it1,it2;
			it1 = s1.begin();
			it2 = s2.begin();
			if(*it1 >= *it2)
				s2.erase(*it2);
			else
				s1.erase(*it1);
		}
		if(s1.empty()) cout<<"MechaGodzilla\n";
		else cout<<"Godzilla\n";
	}
	return 0;
}      
