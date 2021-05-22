#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define ALL(a) (a).begin(), (a).end()
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, 1, -1};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w;
    cin >> h >> w;
    h--, w--;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vc<string> S;
    rep(i, h) {
        string g;
        cin >> g;
        S.push_back(g);
    }
    const int inf = 1LL << 60;
    vc<vc<int>> dp(1010, vc<int>(1010, inf));
    dp[rs][cs] = 0;
    queue<pair<pi, int>> q;
    q.push(make_pair(pi(rs, cs), dp[rs][cs]));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto nx = p.first.second;
        auto ny = p.first.first;
        auto ncnt = p.second;
        rep(i,4){
          int xx=nx+dx[i];
          int yy=ny+dy[i];
          if(xx<0 || yy<0 || xx>=w || yy>=h) continue;
          if(S[yy][xx]=='#') continue;
          
        }
    }
}