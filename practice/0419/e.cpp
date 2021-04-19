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

string x;
int m;
bool judge(int a) {
    int tmp = 0LL;
    int cnt = 1LL;
    for (int i = x.length() - 1; i >= 0; i--) {
        int now = x[i] - '0';
        tmp += now * cnt;
        cnt *= a;
    }
    if (tmp <= m) return true;
    return false;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> x;
    cin >> m;
    if (x.length() == 1) {
        int num = x[0] - '0';
        if (num > m) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
    int st = 0;
    for (auto u : x) {
        int g = u - '0';
        st = max(st, g);
    }
    int ok = st;
    int ng = 1e18 + 1LL;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (judge(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok - st << endl;
}