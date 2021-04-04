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
    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    int ans = 0;
    vc<int> t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') t.push_back(i);
    }
    if (t.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int gl = max(0LL, t.back() - r + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (i == gl) {
                cout << ans + 1 << endl;
                return 0;
            }
            ans++;
            for (int j = i; j < i + r; j++) {
                s[j] = 'o';
                if (j == gl) {
                    ans += j - i + 1;
                    cout << ans << endl;
                    return 0;
                }
            }
            ans++;
        } else {
            if (i == gl) {
                cout << ans + 1 << endl;
                return 0;
            }
            ans++;
        }
    }
}