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
    //市松模様ぽくなる
    // Mで探す
    // 2N-1のマスの状況？
    //空白行は下のみなのでパスしてよい
    int n, m;
    cin >> n >> m;
    vc<pi> p;
    vc<int> a, b;
    set<int> s;
    int l, r;
    int x, y;
    rep(i, m) {
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    sort(ALL(p));
    s.insert(n);
    l = 0;
    while (l < m) {
        a.clear();
        b.clear();
        r = l;
        while (r < m) {
            // 同x(行)の点の数を数える
            if (p[r].first == p[l].first)
                r++;
            else
                break;
        }
        for (int i = l; i < r; i++) {
            // y(列)
            // 1
            y = p[i].second;
            if (((s.find(y - 1) != s.end()) || (s.find(y + 1) != s.end())) &&
                (s.find(y) == s.end()))
                a.push_back(y);
            // 2,3
            if (((s.find(y - 1) == s.end()) && (s.find(y + 1) == s.end())) &&
                (s.find(y) != s.end()))
                b.push_back(y);
        }
        for (int i = 0; i < a.size(); i++) s.insert(a[i]);
        for (int i = 0; i < b.size(); i++) s.erase(b[i]);
        l = r;
    }
    cout << s.size() << endl;
}