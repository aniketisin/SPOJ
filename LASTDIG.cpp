#include<bits/stdc++.h>
using namespace std;

inline void inp( int &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}

typedef vector<int> vi; 

#define pb                           push_back 
#define sii(n,m)		     inp(n);inp(m)

int main()
{
	int a,b,t;
	inp(t);
	while(t--)
	{
		sii(a,b);
		int l = a%10;
		int cycle = 1,xx = (l*l)%10;
		vi p;
		p.pb(l);
		while(xx!=l)
		{
			p.pb(xx);
			xx = (xx*l)%10;
			cycle++;
		}
		if(b==0)
		{
			cout<<"1\n";
			continue;
		}
		printf("%d\n",p[((b%cycle) - 1 + cycle)%cycle]);
	}
	return 0;
}      
