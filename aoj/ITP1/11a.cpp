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

struct Dice{
  int s[6];
  void roll(char c){
    int b;
    if(c=='E'){
      b=s[0];
      s[0]=s[3];
      s[3]=s[5];
      s[5]=s[2];
      s[2]=b;
    }
    if(c=='W'){
      b=s[0];
      s[0]=s[2];
      s[2]=s[5];
      s[5]=s[3];
      s[3]=b;
    }
    if(c=='N'){
      b=s[0];
      s[0]=s[1];
      s[1]=s[5];
      s[5]=s[4];
      s[4]=b;
    }
    if(c=='S'){
      b=s[0];
      s[0]=s[4];
      s[4]=s[5];
      s[5]=s[1];
      s[1]=b;
    }
  }
  int top() {
    return s[0];
  }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Dice a;
    Dice b;
    rep(i,6) cin>>a.s[i];
    rep(i,6) cin>>b.s[i];
    bool flag=false;
    int j=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(a.s[i]==b.s[j]) {flag=true; j=a.s[i];}
        }
    }
    if (!flag) {cout<<"No"<<endl;
    return 0;
    }
    
    


    return 0;
}
