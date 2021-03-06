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
string x;
int l;
int ch(int a) {
    int tmp = 0;
    int f = 1;
    for (int i = 0; i < l; i++) {
        int num = x[l - i - 1] - '0';
        if (i == 0)
            tmp += num;
        else
            tmp += (num * f);
        f *= a;
    }
    return tmp;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    cin >> x;
    int m;
    cin >> m;
    l = x.size();
    int low = 0;
    for (int i = 0; i < x.size(); i++) {
        int g = x[i] - '0';
        low = max(low, g);
    }
    low++;
    if (l == 1) {
        if (low > m)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }

    int up = m + 1LL;
    if (l != 1) {
        up = 1000000001;
    }
    int ok = low;
    while (abs(ok - up) > 1) {
        int mid = (ok + up) / 2;
        if (ch(mid) < m) {
            ok = mid;
        } else {
            up = mid;
        }
    }
    int ans = ok - low + 1;
    if (ch(ok + 1) <= m) ans++;
    cout << ans << endl;
}