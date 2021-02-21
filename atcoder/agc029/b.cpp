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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int ans = 0;
    vc<int> bek(31);
    bek[0] = 2;
    for (int i = 0; i < 29; i++) {
        bek[i + 1] = bek[i] * 2;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < 29; j++) {
            if (bek[j] > b[i]) {
                tmp = j;
                break;
            }
        }
        // cout << bek[tmp] << "## " << tmp << " = tmp" << endl;
        int now = bek[tmp];
        if (binary_search(a.begin(), a.end(), now - b[i]) &&
            now - b[i] != b[i]) {
            if (cnt[now - b[i]] <= 0) continue;
            cnt[now - b[i]]--;
            ans++;
        }
    }
    cout << ans << endl;
}