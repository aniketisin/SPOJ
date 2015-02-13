#include<bits/stdc++.h>
using namespace std;

int mymod(string a,int b)
{
	int res = 0;
	for(int i=0;i<a.length();i++)
		res = ((a[i]-'0') + res*10)%b;
	return res;
}

int gcd(int a,int b)
{
	if(b==0) return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		string b;
		cin>>a>>b;
		if(a==0) cout<<b<<endl;
		else
		{
			int c = mymod(b,a);
			cout<<gcd(a,c)<<endl;
		}
	}
	return 0;
}      
