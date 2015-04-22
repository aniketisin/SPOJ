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
	int left,right;
	int val,sum;
	tree() 
	{
		val = INT_MIN; 
		left = right = sum = INT_MIN;
	}
};


class segTree
{
	public:

		int n;

		vector< tree > st;

		segTree(int _n = 0)
		{
			n = _n;
			st.resize(4*n + 10);
		}

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
			A.sum = R.sum + L.sum;
			A.left = max(L.left, L.sum + R.left);
			A.right = max(R.right, L.right+R.sum);
			A.val = max(max(max(L.val,R.val),max(A.left,A.right)),L.right+R.left);
			return A;
		}

		tree query(int l, int r)
		{
			return query(0,n-1,l,r,1);
		}
};





int main()
{
}      
