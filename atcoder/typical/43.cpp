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
pi delta[] = {pi(1, 0), pi(0, 1), pi(-1, 0), pi(0, -1)};
struct state {
    int x, y, dir;
};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w;
    cin >> h >> w;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vc<string> S;
    rep(i, h) {
        string g;
        cin >> g;
        S.push_back(g);
    }
    vc<vc<vc<int>>> dp(1010, vc<vc<int>>(1010, vc<int>(4, 1e18)));
    deque<state> deq;
    rep(i, 4) {
        dp[rs][cs][i] = 0;
        deq.push_back({rs, cs, i});
    }
    while (!deq.empty()) {
        auto u = deq.front();
        deq.pop_front();
        rep(i, 4) {
            int tx = u.x + delta[i].first;
            int ty = u.y + delta[i].second;
            // u.dir==iじゃない時はcost++
            int cost = dp[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
            if (0 <= tx && tx < h && 0 <= ty && ty < w && S[tx][ty] == '.' &&
                dp[tx][ty][i] > cost) {
                dp[tx][ty][i] = cost;
                if (u.dir != i)
                    deq.push_back({tx, ty, i});
                else
                    deq.push_front({tx, ty, i});
            }
        }
    }
    int ans = 1LL << 60;
    rep(i, 4) { chmin(ans, dp[rt][ct][i]); }
    cout << ans << endl;
    return 0;
}