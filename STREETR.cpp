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
	int a[100010];
	int diff[100010];
	int n,gcd = 0,ans = 0;;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++) diff[i-1] = a[i] - a[i-1];
	for(int i=0;i<n-1;i++) gcd = __gcd(gcd,diff[i]);
	for(int i=0;i<n-1;i++)
		ans+= diff[i]/gcd - 1;
	cout<<ans<<"\n";
	return 0;
}      
