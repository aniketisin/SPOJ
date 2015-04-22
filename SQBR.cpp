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

lld dp[40][40];
int n,k;
int a[40];
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		fill(dp,0);
		fill(a,0);
		cin>>n>>k;
		for(int i=0;i<k;i++)
		{
			int xx;
			cin>>xx;
			--xx;
			a[xx] = 1;
		}
		dp[0][0] = 0;
		dp[0][1] = 1;
		for(int i=1;i<(n<<1);i++)
			for(int j=0;j<=i+1;j++)
			{
				if(!a[i])
					dp[i][j] += dp[i-1][j+1];
				if(j) dp[i][j] += dp[i-1][j-1];
			}
		cout<<dp[2*n-1][0]<<"\n";
	}
	return 0;
}      
