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
    deque<int> a;
    rep(i, n) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int ans = 0;
    //不変の白箇所を決め打ちして，累積和で残りを計算するでもOK
    while (a.size() > 1) {
        int LL, LR, RL, RR;
        LL = a.front();
        a.pop_front();
        LR = a.front();
        a.pop_front();
        RR = a.back();
        a.pop_back();
        RL = a.back();
        a.pop_back();
        int lcost, rcost;
        lcost = LL * 2 + LR + 1;
        rcost = RR * 2 + RL + 1;
        if (lcost < rcost) {
            ans += lcost;
            int next = a.front();
            a.pop_front();
            int now = LL + LR + next + 2;
            a.push_front(now);
            a.push_back(RL);
            a.push_back(RR);
        } else {
            ans += rcost;
            int next = a.back();
            a.pop_back();
            int now = RL + RR + next + 2;
            a.push_back(now);
            a.push_front(LR);
            a.push_front(LL);
        }
    }
    cout << ans << endl;
}