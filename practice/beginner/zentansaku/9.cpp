#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    Int ans=0;
    for(int i=0; i<1000; i++){
        int tmp[3];
        tmp[0]=i/100;
		tmp[1]=(i/10)%10;
		tmp[2]=i%10;
		int count=0;
		for (int j =0; j<s.length(); j++)
		{
 
			if ((s[j]-'0')==tmp[count])
			{
				
              count++;
			}
			if(count==3)
			{
				ans++;
              break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}