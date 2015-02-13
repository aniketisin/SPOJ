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

int convert(string a)
{
	int l = a.length(),ret = 0;
	for(int i=0;i<l;i++)
	{
		if(a[i] <= '9' && a[i] >='0')
			ret = ret*10 + a[i] -'0';
		else
			return -1;
	}
	return ret;
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int num1,num2,res;
		string a,b,c,kachra;
		cin>>a>>kachra>>b>>kachra>>c;
		num1 = convert(a);
		num2 = convert(b);
		res = convert(c);
		if(num1 == -1)
			num1 = res - num2;
		if(num2 == -1)
			num2 = res - num1;
		if(res == -1)
			res = num1+num2;
		cout<<num1<<" + "<<num2<<" = "<<res<<endl;
	}
	return 0;
}      
