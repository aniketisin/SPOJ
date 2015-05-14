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
#define mod 10000007
#define __sync__		     std::ios::sync_with_stdio(false);

lld add(lld xx,lld yy)
{
	return (xx+yy)%mod;
}

lld mpow(lld a,lld b)
{
	lld ret = 1;
	while(b)
	{
		if(b&1)
			ret = (ret*a)%mod;
		a = (a*a)%mod;
		b /= 2;
	}
	return ret;
}

int main()
{
	__sync__;
	lld n,k;
	while(cin>>n>>k)
	{
		if(n==0 && k==0) return 0;
		lld xx = mpow(n%mod,k),yy;
		xx = add(xx,mpow(n%mod,n));
		yy = mpow((n-1)%mod,n-1);
		xx = add(xx,add(yy,yy));
		yy = mpow((n-1)%mod,k);
		xx = add(xx,add(yy,yy));
		cout<<xx<<"\n";
	}
	return 0;
}      
