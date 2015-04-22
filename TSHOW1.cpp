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

string solve(int len,int pos)
{
	//if(pos==0) return "5";
	if(len<=0 || pos<0) return "";
	string ret = "";
	if( pos <= (1LL<<(len-1))) 
	{
		ret += '5';
		ret += solve(len-1, pos);
	}
	else 
	{
		ret+= '6';
		ret += solve(len-1, pos - (1LL<<(len-1)));
	}
	return ret;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lld xx;
		cin>>xx;
		int log = 1;
		for(log = 1; ((1LL<<(log+1)) - 2) < xx; log++);
		//log--;
		//cout<<log<<" "<<(xx - (1LL<<(log)) + 2)<<"\n";
		//if((1LL<<log) != xx) log++;
		cout<<solve(log,xx - (1LL<<(log)) + 2)<<"\n";
	}
	return 0;
}      
