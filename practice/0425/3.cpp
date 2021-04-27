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

int st, gl;
int n;
vc<string> words;
map<int, string> w;
vc<vc<int>> path(1100);
vc<pi> cnt(1100, pi(1e9, 0));
void dfs(int x, int now = 0, int was = -1) {
    if (cnt[now].first > x) {
        cnt[now].first = x;
        cnt[now].second = was;
        for (auto u : path[now]) {
            if (cnt[u].first > x + 1) {
                dfs(x + 1, u, now);
            }
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string first, last;
    cin >> first >> last;
    if (first == last) {
        cout << 0 << endl;
        cout << first << endl;
        cout << last << endl;
        return 0;
    }
    cin >> n;
    words.push_back(first);
    words.push_back(last);
    rep(i, n) {
        string g;
        cin >> g;
        words.push_back(g);
    }
    for (int i = 0; i < words.size(); i++) {
        w[i] = words[i];
    }
    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            int cnt = 0;
            for (int k = 0; k < words[j].size(); k++) {
                if (words[i][k] == words[j][k]) cnt++;
            }
            if (cnt == words[i].length() - 1) {
                path[i].push_back(j);
                path[j].push_back(i);
            }
        }
    }
    dfs(0);
    int ans = cnt[1].first;
    if (ans == 1e9) {
        cout << -1 << endl;
        return 0;
    }
    vc<string> res;
    int tmp = cnt[1].second;
    while (tmp != 0) {
        res.push_back(w[tmp]);
        tmp = cnt[tmp].second;
    }
    reverse(ALL(res));
    cout << res.size() << endl;
    cout << first << endl;
    rep(i, res.size()) { cout << res[i] << endl; }
    cout << last << endl;
}