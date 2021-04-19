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
int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, x;
    cin >> n >> x;
    vc<int> a(n);
    int cur = 0;
    bool nan = true;
    int cnt = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] != -1) {
            cur ^= a[i];
        } else {
            nan = false;
            cnt++;
        }
    }
    if (nan) {
        if (cur == x) {
            rep(i, n) cout << a[i] << " ";
            cout << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    } else {
        int cg = x ^ cur;
        if ((1LL << topbit(cg)) > x) {
            cout << -1 << endl;
            return 0;
        }
        rep(i, n) {
            if (a[i] == -1) {
                a[i] = 0;
                if (cnt == 1) {
                    a[i] += cg;
                } else {
                    int tb = topbit(cg);
                    if (tb >= 0 && cg > 0) {
                        a[i] |= (1LL << tb);
                        cg ^= (1LL << tb);
                    }
                    cnt--;
                }
            }
            if (a[i] > x) {
                cout << -1 << endl;
                return 0;
            }
        }
        rep(i, n) cout << a[i] << " ";
        cout << endl;
    }
}