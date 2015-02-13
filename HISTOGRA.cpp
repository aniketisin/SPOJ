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

lld a[100010];

pair<lld,lld> st[400010];
lld n;
void upd(int s,int e,int node,int pos,int val)
{
	if(s>e) return;
	if(s==e) 
	{
		st[node] = mp(val,pos);
		return;
	}
	int m = (s+e)>>1;
	int l = node<<1;
	int r = l|1;
	if(pos>m) upd(m+1,e,r,pos,val);
	else upd(s,m,l,pos,val);
	st[node] = min(st[l],st[r]);
}

pii query(int s,int e,int x,int y,int node)
{
	if(s>e || s>y || e<x) return mp(INF,INF);
	if(s>=x && e<=y) return st[node];
	int m = (s+e)>>1;
	int l = node<<1;
	int r = l|1;
	if(x>m) return query(m+1,e,x,y,r);
	else if(y<=m) return query(s,m,x,y,l);
	return min(query(s,m,x,y,l),query(m+1,e,x,y,r));
}

/*int mymin(int s,int e)
{
	int idx = s,mn = a[s];
	for(int i=s;i<=e;i++)
		if(a[i]<mn) 
		{
			mn = a[i];
			idx = i;
		}
	return idx;
}*/

lld solve(int s,int e)
{
	//cout<<s<<" "<<e<<"\n";
	if(s<0 || e<0 || s>e) return 0;
	if(e==s) return a[s];
	lld ret = 0;
	int mid = query(0,n-1,s,e,1).S;
	ret = max(a[mid]*(e - s + 1)*1LL,max(solve(s,mid-1),solve(mid+1,e)));
	return ret;
}

int main()
{
	while(scanf("%lld",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++) 
		{
			sl(a[i]);
			upd(0,n-1,1,i,a[i]);
		}
		printf("%lld\n",solve(0,n-1));
	}
	return 0;
}      
