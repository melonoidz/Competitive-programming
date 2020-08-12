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
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

void MergeSort(vector<Int> &a, int left ,int right,int count){
    if(right-left==1) return ;
    int mid=(left+right)/2;

    MergeSort(a, left, mid, count);
    MergeSort(a, mid, right, count);

    vector<Int> buf;
    for(int i=left; i<mid; i++) buf.emplace_back(a[i]);
    for(int i=right-1; i>=mid; i--) buf.emplace_back(a[i]);

    int itr_left=0;
    int itr_right=(int)buf.size()-1;

    for(int i=left; i<right; i++){
        if(buf[itr_left]<=buf[itr_right]){
            a[i]=buf[itr_left];
            itr_left++;
        }
        else{
            a[i]=buf[itr_right];
            itr_right--;
        }
        count++;
    }
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int n; cin>>n;
    vector<Int> S(n);
    for(Int i=0; i<n; i++) cin>>S[i];
    Int count=0;
    MergeSort(S,0,n,count);
    for(int i=0; i<n; i++){
       if(i<n-1) cout<<S[i]<<" ";
       else cout<<S[i]<<endl;
    }
    cout<<count<<endl;
    return 0; 
}