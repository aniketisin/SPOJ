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

lld cows,stalls;

int xx[100010];

lld possible(lld a)
{
	lld d = 0;
	int s1 = 0;
	int s2 = 1;
	while(s1<s2 && s2<stalls)
	{
		if((xx[s2]-xx[s1] >= a) && s2<stalls) {
			s1 = s2;
			s2++;
			d++;
		}
		while(xx[s2] - xx[s1] < a && s2<stalls) s2++;
	}
	if(d>=cows-1)
		return true;
	return false;
}

lld solve(lld s,lld e)
{
	if(s>e) return -1;
	if(s==e) 
	{
		if(possible(s)) return s;
		return -1;
	}
	lld mid = (s+e)>>1;
	if(possible(mid))
		return max(solve(mid+1,e),mid);
	else
		return solve(s,mid-1);
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		sl(stalls);sl(cows);
		for(int i=0;i<stalls;i++) si(xx[i]);
		sort(xx,xx+stalls);
		cout<<solve(0,xx[stalls-1] - xx[0])<<endl;
	}
	return 0;
}      
