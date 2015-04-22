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
#define __sync__		     std::ios::sync_with_stdio(false);

struct tree
{
	int val1,val2;
	tree() 
	{
		val1 = val2 = INT_MIN; 
	}
};


class segTree
{
	public:

		int n;

		vector< tree > st;

		segTree(int _n)
		{
			n = _n;
			st.resize(4*n + 10);
		}

		segTree() {}

		~segTree()
		{
			st.clear();
			n = 0;
		}

		void update(int s,int e,int node,int pos,int v)
		{
			if(s>e) return;
			if(s==e) 
			{
				st[node].val1 = v;
				return;
			}

			int l = node<<1;
			int r = l|1;
			int m = (s+e)>>1;

			if(pos>m)
				update(m+1,e,r,pos,v);
			else
				update(s,m,l,pos,v);

			if(st[l].val1>st[r].val1) 
			{
				st[node].val1 = st[l].val1;
				st[node].val2 = max(st[l].val2,st[r].val1);
			}
			else 
			{
				st[node].val1 = st[r].val1;
				st[node].val2 = max(st[r].val2,st[l].val1);
			}

		}

		void update(int pos,int v)
		{
			update(0,n-1,1,pos,v);
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
			if(L.val1>R.val1) 
			{
				A.val1 = L.val1;
				A.val2 = max(L.val2,R.val1);
			}
			else 
			{
				A.val1 = R.val1;
				A.val2 = max(R.val2,L.val1);
			}
			return A;
		}

		int query(int l, int r)
		{
			tree xx = query(0,n-1,l,r,1);
			return xx.val1 + xx.val2;
		}
};

const int N = 1e5 + 4;

segTree st(N);

int main()
{
	__sync__;
	int n,xx,yy,q;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>xx;
		st.update(i,xx);
	}
	string type;
	cin>>q;
	while(q--)
	{
		cin>>type>>xx>>yy;
		xx--;yy--;
		if(type=="U")
			st.update(xx,yy+1);
		else cout<<st.query(xx,yy)<<"\n";
	}
	return 0;
}      
