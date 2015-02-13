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

vi f,ans;
int n;
string pattern;
void KMP_failure_function()
{
	f[0] = f[1] = 0;
	for(int i=2;i<=n;i++)
	{
		int j = f[i-1];
		for(;;)
		{
			if(pattern[j] == pattern[i-1])
			{
				f[i] = j+1;
				break;
			}
			if(j==0) {f[i] = 0; break;}
			j = f[j];
		}
	}
}

int main()
{
	while(cin>>n)
	{
		getchar();
		ans.clear();
		f.resize(n+1);
		cin>>pattern;
		KMP_failure_function();
		getchar();
		char c;
		int state = 0,idx=0;
		while((c=getchar())&&c!='\n')
		{
			for(;;)
			{
				if(c==pattern[state])
				{
					idx++;
					state++;
					if(state==n)
						ans.pb(idx-n);
					break;
				}
				else if(state>0) state = f[state];
				else {idx++; break;}
			}
		}
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
		cout<<endl;
	}
	return 0;
}      
