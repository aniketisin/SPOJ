#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef pair<long long int , long long int> pll;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define mt                           make_tuple
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007
#define __sync__		     std::ios::sync_with_stdio(false);

map< pll,lld> dp;
vector< pair <pll,lld> > m;

lld solve(lld x,lld y)
{
	if(dp.find(mp(x,y))!=dp.end()) return dp[mp(x,y)];
	lld ret,tmp = 0;
	ret = 0;
	for(int i= 0;i<m.sz;i++)
		if(m[i].F.F<x && m[i].F.S<y)
			ret = max(ret,solve(m[i].F.F,m[i].F.S)+m[i].S);
	dp[mp(x,y)] = ret;
	return ret+tmp;
}

int main()
{
	__sync__;
	int n;
	while(cin>>n)
	{
		dp.clear();
		m.clear();
		if(n==0) return 0;
		lld xx[3];
		for(int i=0;i<n;i++)
		{
			cin>>xx[0]>>xx[1]>>xx[2];
			sort(xx,xx+3);
			m.pb(mp(mp(xx[0],xx[1]),xx[2]));
			m.pb(mp(mp(xx[0],xx[2]),xx[1]));
			m.pb(mp(mp(xx[1],xx[2]),xx[0]));
		}
		cout<<solve(INF,INF)<<"\n";
	}
	return 0;
}      
