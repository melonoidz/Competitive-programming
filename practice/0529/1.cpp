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
    int q, l;
    cin >> q >> l;
    stack<pi> ST;
    int cnt = 0;
    rep(i, q) {
        string t;
        cin >> t;
        if (t == "Push") {
            // Push
            int n, m;
            cin >> n >> m;
            cnt += n;
            if (cnt > l) {
                cout << "FULL" << endl;
                return 0;
            }
            ST.push(make_pair(n, m));
        } else if (t == "Pop") {
            // Pop
            int n;
            cin >> n;
            cnt -= n;
            if (cnt < 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            while (n > 0) {
                auto p = ST.top();
                int num = p.first;
                if (num <= n) {
                    ST.pop();
                } else {
                    ST.top().first -= n;
                }
                n -= num;
            }

        } else if (t == "Top") {
            // Top
            if (cnt == 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            auto p = ST.top();
            cout << p.second << endl;
        } else {
            // Size
            cout << cnt << endl;
        }
    }
    cout << "SAFE" << endl;
    return 0;
}