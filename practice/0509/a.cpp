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
    map<int, int> cnt;
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (auto itr = cnt.rbegin(); itr != cnt.rend(); itr++) {
        int num = itr->first;
        if (cnt[num] == 0) continue;
        int st = 1;
        while (st <= num) {
            st *= 2LL;
        }
        int now = st - num;
        if (now == num) {
            if (cnt[now] > 1) {
                //ここ
                ans += cnt[num] / 2;
            }
        } else {
            if (cnt[now] > 0 && cnt[num] > 0) {
                //ここ
                ans += min(cnt[now], cnt[num]);
                cnt[now] -= min(cnt[now], cnt[num]);
            }
        }
    }
    cout << ans << endl;
}