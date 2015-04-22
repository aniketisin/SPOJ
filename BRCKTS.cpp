#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007

struct tree
{
	int mn,sum;
	tree() 
	{
		mn = INT_MAX; 
		sum = 0;
	}
};

tree st[6*50000];

void update(int s,int e,int node,int pos,int v)
{
	if(s>e) return;
	if(s==e) 
	{
		st[node].sum = v;
		st[node].mn = v;
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
	st[node].mn = min(st[l].mn,st[r].mn + st[l].sum);
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
	A.mn = min(L.mn,L.sum+R.mn);
	return A;
}


int main()
{
	int t = 0;
	ios_base::sync_with_stdio(false);
	while(t<10)
	{
		int n,xx,q;
		string a;
		cin>>n>>a;
		for(int i=0;i<n;i++)
		{
			xx = (a[i]=='(')?1:-1;
			update(0,n-1,1,i,xx);
		}
		cin>>q;
		cout<<"Test "<<t+1<<":\n";
		while(q--)
		{
			cin>>xx;
			if(xx > 0)
			{
				tree tmp = query(0,n-1,xx-1,xx-1,1);
				update(0,n-1,1,xx-1,-tmp.sum);
			}
			else
			{
				if(st[1].sum==0 && st[1].mn>=0)
					cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
		t++;
	}
	return 0;
}      

