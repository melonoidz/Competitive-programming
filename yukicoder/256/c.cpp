#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

bool judge(int d,int a){
    if (a==(d)%12|| a==(d+2)%12 || a==(d+4)%12 || a==(d+5)%12 || a==(d+7)%12 || a==(d+9)%12 || a==(d+11)%12){
        return true;
    }
    else{
    return false;
    }
}
int n;
int t[12];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i =0; i<n; i++){
        int v; cin >>v;
        t[i]=v;
    }
    vector<int> cnt;
    cnt.resize(0);
    for(int i=0; i<12; i++){
        int  ans=0;
        for (int j=0; j<n; j++){
            if(judge(i,t[j])){
                ans++;
            };
        }
        if (ans==n){
            cnt.emplace_back(i);
        }
    }
    if (cnt.size()==0|| cnt.size()>1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<cnt[0]<<endl;
    }
    return 0;
}