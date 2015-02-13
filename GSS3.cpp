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

struct tree
{
	int left,right;
	int val,sum;
	tree() 
	{
		val = INT_MIN; 
		left = right = sum = INT_MIN;
	}
};

tree st[6*50000];

void update(int s,int e,int node,int pos,int v)
{
	if(s>e) return;
	if(s==e) 
	{
		st[node].val = v;
		st[node].left = st[node].right = st[node].sum = v;
		return;
	}
	
	int l = node<<1;
	int r = l|1;
	int m = (s+e)>>1;
	
	if(pos>m)
		update(m+1,e,r,pos,v);
	else
		update(s,m,l,pos,v);
	
	st[node].sum = st[l].sum + st[r].sum;
	st[node].left = max(st[l].left , st[l].sum + st[r].left);
	st[node].right = max(st[r].right, st[r].sum + st[l].right);
	st[node].val = max(max(max(st[l].val,st[r].val),max(st[node].left,st[node].right)),st[l].right+st[r].left);
	
}

tree query(int s,int e,int a,int b,int node)
{
	if((s>=a && e<=b)) return st[node];
	tree L,R,A;	
	int l = node<<1;
	int r = l|1;
	int m = (s+e)>>1;
	if(a>m) return query(m+1,e,a,b,r);
	if(b<=m) return query(s,m,a,b,l);
	
	R = query(m+1,e,a,b,r);
	L = query(s,m,a,b,l);
	A.sum = R.sum + L.sum;
	A.left = max(L.left, L.sum + R.left);
	A.right = max(R.right, L.right+R.sum);
	A.val = max(max(max(L.val,R.val),max(A.left,A.right)),L.right+R.left);
	return A;
}

int main()
{
	int t;
	si(t);
	int xx;
	for(int i=0;i<t;i++)
	{
		si(xx);
		update(0,t-1,1,i,xx);
	}
	int m,a,b,o;
	si(m);
	while(m--)
	{
		siii(o,a,b);
		a--;b--;
		if(o==1)
			printf("%d\n",query(0,t-1,a,b,1).val);
		else
			update(0,t-1,1,a,b+1);
	}
	return 0;
}      
