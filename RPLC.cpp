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
#define int long long


#undef int
int main()
{
#define int long long
	int t, s = 1;
	cin >> t;
	while(t--)
	{
		int n,xx,energy = 1, ans = -1;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> xx;
			energy -= xx;
			ans = max(ans,energy);
		}
		if(ans <= 0) ans = 1;
		cout << "Scenario #" << s <<": " << ans << "\n";
		s++;
	}
	return 0;
}      
