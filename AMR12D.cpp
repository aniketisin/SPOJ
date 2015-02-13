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

bool palin(string a)
{
	int s = 0;
	int e = a.length()-1;
	while(s<e)
		if(a[s++]!=a[e--]) return 0;
	return 1;
}

#undef int
int main()
{
#define int long long
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout<<(palin(s) ? "YES\n" : "NO\n");
	}
	return 0;
}      
