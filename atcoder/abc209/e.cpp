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
const int M = 52 * 52 * 52;
int conv(char x) {
    if ('A' <= x && x <= 'Z') return x - 'A';
    return x - 'a' + 26;
}
int sir(char a, char b, char c) {
    // 52進数
    return conv(a) * 52 * 52 + conv(b) * 52 + conv(c);
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<pi> edge(n);
    vvc<int> revG(M);
    vc<int> cnt(M), ans(M, -1);
    rep(i, n) {
        string s;
        cin >> s;
        edge[i].first = sir(s[0], s[1], s[2]);
        edge[i].second = sir(s[s.size() - 3], s[s.size() - 2], s[s.size() - 1]);
        cnt[edge[i].first]++;
        revG[edge[i].second].emplace_back(edge[i].first);  //逆辺で張る
    }
    queue<int> que;
    rep(i, M) {
        if (cnt[i] == 0) {
            ans[i] = 0;
            que.push(i);
        }
    }
    while (!que.empty()) {
        auto t = que.front();
        que.pop();
        for (auto x : revG[t]) {
            //まだ見ていないなら
            if (ans[x] == -1) {
                cnt[x]--;
                if (ans[t] == 0) {
                    ans[x] = 1;
                    que.push(x);
                } else if (cnt[x] == 0) {
                    //次数が0になったら
                    ans[x] = 0;
                    que.push(x);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[edge[i].second] == -1) cout << "Draw" << endl;
        if (ans[edge[i].second] == 0) cout << "Takahashi" << endl;
        if (ans[edge[i].second] == 1) cout << "Aoki" << endl;
    }
}