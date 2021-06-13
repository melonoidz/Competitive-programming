#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
vc<int> dx(16180, 0);
vc<int> dy(16180, 0);

void solve(vc<int>& d, vc<int> c, int now, int cnt, bool isX) {
    if (!d[now]) {
        d[now] = 1;
        if (c.size() > cnt) {
            solve(d, c, now + c[cnt], cnt + 1, isX);
            if (cnt != 0 || !isX) solve(d, c, now - c[cnt], cnt + 1, isX);
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    vc<int> X;
    vc<int> Y;
    bool f = true;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[0] == 'T') {
            X.push_back(0);
            f = false;
        } else {
            if (s[i] == 'F') {
                cnt++;
            } else {
                if (f) {
                    X.push_back(cnt);
                    cnt = 0;
                    f = false;
                } else {
                    Y.push_back(cnt);
                    cnt = 0;
                    f = true;
                }
            }
        }
    }
    if (f) {
        X.push_back(cnt);
    } else {
        Y.push_back(cnt);
    }
    solve(dx, X, 8100, 0 + X.front(), true);
    solve(dy, Y, 8100, 0, false);
    if (dx[x + 8100] && dy[y + 8100]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}