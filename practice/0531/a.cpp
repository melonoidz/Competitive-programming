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
    int h, w;
    cin >> h >> w;
    int q;
    cin >> q;
    atcoder::dsu uf(440000);
    map<pi, int> vertex;
    int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0, 0, -1};
    vc<vc<int>> f(h, vc<int>(w, 0)), num(h, vc<int>(w));
    int cnt = 1;
    rep(i, h) rep(j, w) {
        num[j][i] = cnt;
        cnt++;
    }
    rep(i, q) {
        int x;
        cin >> x;
        if (x == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            f[c][r] = 1;
            int now = num[c][r];
            for (int j = 0; j < 4; j++) {
                int nx = r + dx[j];
                int ny = c + dy[j];
                if (!(nx < 0 || ny < 0 || nx >= w || ny >= h)) {
                    if (f[ny][nx] != 0) {
                        int tmp = num[ny][nx];
                        uf.merge(now, tmp);
                    }
                }
            }
        } else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            if (pi(a, b) == pi(c, d)) {
                cout << "Yes" << endl;
            } else {
                if (uf.same(num[b][a], num[d][c]) &&
                    (f[b][a] == 1 && f[d][c] == 1)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
}