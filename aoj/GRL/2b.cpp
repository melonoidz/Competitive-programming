#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
int popcount(signed t){
return __builtin_popcount(t);
}
int popcount(ll t){
return __builtin_popcountll(t);
}
bool ispow2(int i){
return i&&(i&-i)==i;
}
ll mask(int i){
return (ll(1)<<i)-1;
}
int lcm(int a, int b)
{
return a / __gcd(a, b) * b;
}
struct UnionFind {
vector<int> par;
UnionFind(int n) : par(n, -1) { }
void init(int n) { par.assign(n, -1); }
int root(int x) {
if (par[x] < 0) return x;
else return par[x] = root(par[x]);
}
bool issame(int x, int y) {
return root(x) == root(y);
}
bool merge(int x, int y) {
x = root(x); y = root(y);
if (x == y) return false;
if (par[x] > par[y]) swap(x, y); // merge technique
par[x] += par[y];
par[y] = x;
return true;
}
int size(int x) {
return -par[root(x)];
}
};
int V,E ;
struct Edge{
    int cost;
    int from;
    int to;   
};
bool comp(Edge &e1,Edge &e2)
{
    return e1.cost < e2.cost;
}
vc<Edge> G;
signed main(){
cin.tie(0);
ios::sync_with_stdio(0);
cout<<fixed<<setprecision(20);
 cin>>V>>E;
 rep(i,E){
    int s,t,w; cin>>s>>t>>w;
    Edge e{w,s,t};
    G.push_back(e);
 }       
sort(G.begin(), G.end(), comp);    
UnionFind uf(V);
int res=0;
for(auto& edge: G)
{
    if(!uf.issame(edge.from,edge.to)){
        res+=edge.cost;
        uf.merge(edge.from,edge.to);
    }
}       
cout<<res<<endl;                    
return 0;   
}