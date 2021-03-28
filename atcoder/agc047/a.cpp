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
    const int cal = 1000000000LL;
    map<pair<int, int>, int> cnt;
    rep(i, n) {
        string s;
        cin >> s;
        string g;  // 小数点以下を取り出したもの
        if (count(s.begin(), s.end(), '.') != 0) {
            while (s.back() != '.') {
                g.push_back(s.back());
                s.pop_back();
            }
            s.pop_back();
            std::reverse(g.begin(), g.end());
        }
        while ((int)g.length() < 9) g.push_back('0');

        // 整数に変換
        int x = std::stoi(s) * cal + std::stoi(g);

        int nt = (int)x;
        int nf = (int)x;
        int tw = 0;
        int fv = 0;
        while (nt % 2 == 0) {
            nt /= 2;
            tw++;
        }
        while (nf % 5 == 0) {
            nf /= 5;
            fv++;
        }
        tw = min(18LL, tw);
        fv = min(18LL, fv);
        cnt[pi(tw, fv)]++;
    }
    int ans = 0;
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            for (int k = 0; k <= 18; k++) {
                for (int l = 0; l <= 18; l++) {
                    if (i + k >= 18 && j + l >= 18) {
                        if (i == k && j == l) {
                            ans += cnt[pi(i, j)] * (cnt[pi(k, l)] - 1);
                        } else {
                            ans += cnt[pi(i, j)] * cnt[pi(k, l)];
                        }
                    }
                }
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}