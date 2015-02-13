#include<bits/stdc++.h>
using namespace std;

/*-----Fast I/O-----*/
inline void inp( int &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
/*-----End of Fast I/O-----*/

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz(a)                        int((a).size()) 
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define present(c,x)                 ((c).find(x) != (c).end()) 
#define si(n)                        inp(n)
#define sl(n)                        scanf("%lld",&n)
#define ss(n)                        scanf("%s",n)
#define sii(n,m)		     inp(n);inp(m)
#define siii(n,m,r)		     inp(n);inp(m);inp(r)
#define abs(x)                       ((x)<0?-(x):(x))
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007


int main()
{
	string a,b,x,y;
	while(cin >> a >> b)
	{
		int l1 = a.length();
		int l2 = b.length();
		l1--;l2--;
		int c = 0;
		while(l1>=0 && l2>=0)
		{
			a[l1] -='0';
			b[l2] -='0';
			a[l1] = (a[l1] + b[l2] + c);
			c = a[l1]/10;
			a[l1] = a[l1] % 10 + '0';
			l1--;
			l2--;

		}
		while(l1>=0)
		{
			a[l1] -= '0';
			a[l1] += c;
			c = a[l1]/10;
			a[l1] = a[l1]%10 + '0';
			l1--;
		}
		if(c>0)
		{
			a = "0" + a;
			a[0] = c + '0';
		}
		c = 0;
		for(int i=0;i<a.length();i++)
		{
			a[i] = c*10 + a[i] -'0';
			if(a[i]&1)
				c = 1;
			else
				c = 0;
			a[i]/=2;
			a[i] += '0';
		}
		l1 = a.length();
		l2 = b.length();
		l1--;l2--;
		x = a;
		while(l1>=0 && l2>=0)
		{
			x[l1] = x[l1] - b[l2] - '0';
			if(x[l1] < 0 ) 
			{
				x[l1] += 10;
				int l = l1-1;
				while(x[l]=='0' && l>0){ x[l]='9';l--;}
				x[l]--;
			}
			x[l1] += '0';
			l1--;
			l2--;
		}
		int xx = 0;
		while(a[xx] == '0' && xx<a.length()-1) xx++;
		while(xx<a.length()) {cout<<a[xx];xx++;}
		cout<<endl;
		xx = 0;
		while(x[xx] == '0' && xx<x.length()-1) xx++;
		while(xx<x.length()) {cout<<x[xx];xx++;}
		cout<<endl;
	}
	return 0;
}      
