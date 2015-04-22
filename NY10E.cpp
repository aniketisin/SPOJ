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


int main()
{
	int t;
	cin>>t;
	lld dp[70][10];
	fill(dp,0);
	for(int i=0;i<10;i++) dp[1][i] = 1;
	for(int i=2;i<66;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<=j;k++)
				dp[i][j] += dp[i-1][k];
	while(t--)
	{
		int xx,yy;
		cin>>xx>>yy;
		lld ans = 0;
		for(int i=0;i<10;i++) ans+=dp[yy][i];
		cout<<xx<<" "<<ans<<"\n";
	}
	return 0;
}


