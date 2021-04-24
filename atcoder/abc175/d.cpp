#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed

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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int INF = 1LL << 60;
    int ans = -INF;
    int n, k;
    cin >> n >> k;
    vector<int> p(n, 0);
    vector<int> c(n, 0);
    rep(i, n) {
        int o;
        cin >> o;
        p[i] = o - 1;
    }
    rep(i, n) { cin >> c[i]; }
    vector<vector<int>> cost;
    for (int i = 0; i < n; i++) {
        int start = i;
        int tmp = 0;
        vector<int> roop;
        vector<int> ch(n, 0);
        while (ch[start] != 1) {
            ch[start] = 1;
            tmp += c[p[start]];
            roop.push_back(tmp);
            start = p[start];
        }
        cost.push_back(roop);
    }
    if (k < n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < min(k, int(cost[i].size())); j++) {
                ans = max(ans, cost[i][j]);
            }
        }
        cout << ans << endl;
    } else {
        vector<int> mi(n, 0);
        rep(i, n) {
            if (cost[i].back() <= 0) {
                mi[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (mi[i]) {
                // 1ループで十分な場合
                for (int j = 0; j < cost[i].size(); j++) {
                    ans = max(ans, cost[i][j]);
                }
            } else {
                int mm = -INF;
                int mcnt = 0;
                for (int j = 0; j < cost[i].size(); j++) {
                    if (cost[i][j] > mm) {
                        mm = cost[i][j];
                        mcnt = j;
                        int rop = (k - mcnt - 1LL) / (int)cost[i].size();
                        int nans = rop * cost[i].back() + mm;
                        ans = max(ans, nans);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
