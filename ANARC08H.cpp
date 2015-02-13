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

int solve(int n,int k)
{
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans = (ans+k)%i;
	return ans;
}

int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n==0 && k==0) return 0;
		cout<<n<<" "<<k<<" "<<solve(n,k)+1<<"\n";
	}
}      
