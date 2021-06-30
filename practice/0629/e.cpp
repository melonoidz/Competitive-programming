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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, vc<int>> cnt;
    if (n < 8) {
        for (int bit = 0; bit < (1 << n); bit++) {
            if (bit == 0) continue;
            int now = 0;
            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) {
                    now += a[i];
                    now %= 200;
                }
            }
            now %= 200;
            if (!cnt[now].empty()) {
                // Yes
                auto u = cnt[now].front();
                vc<int> b, c;
                for (int i = 0; i < n; i++) {
                    if (u & (1 << i)) {
                        b.push_back(i + 1);
                    }
                    if (bit & (1 << i)) {
                        c.push_back(i + 1);
                    }
                }
                cout << "Yes" << endl;
                cout << b.size() << " ";
                rep(i, b.size()) { cout << b[i] << " "; }
                cout << endl;
                cout << c.size() << " ";
                rep(i, c.size()) { cout << c[i] << " "; }
                cout << endl;
                return 0;
            } else {
                cnt[now].push_back(bit);
            }
        }
        cout << "No" << endl;
        return 0;
    } else {
        for (int bit = 0; bit < (1 << 8); bit++) {
            if (bit == 0) continue;
            int now = 0;
            for (int i = 0; i < 8; i++) {
                if (bit & (1 << i)) {
                    now += a[i];
                    now %= 200;
                }
            }
            now %= 200;
            if (!cnt[now].empty()) {
                // Yes
                auto u = cnt[now].front();
                vc<int> b, c;
                for (int i = 0; i < 8; i++) {
                    if (u & (1 << i)) {
                        b.push_back(i + 1);
                    }
                    if (bit & (1 << i)) {
                        c.push_back(i + 1);
                    }
                }
                cout << "Yes" << endl;
                cout << b.size() << " ";
                rep(i, b.size()) { cout << b[i] << " "; }
                cout << endl;
                cout << c.size() << " ";
                rep(i, c.size()) { cout << c[i] << " "; }
                cout << endl;
                return 0;
            } else {
                cnt[now].push_back(bit);
            }
        }
        cout << "No" << endl;
        return 0;
    }
    return 0;
}