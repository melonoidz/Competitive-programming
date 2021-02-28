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
    int k;
    cin >> k;
    vc<int> card(10, k);
    string s, t;
    cin >> s;
    cin >> t;
    int ans = 0;
    int nt = 0, na = 0;
    vc<int> pl(12);
    pl[0] = 1;
    for (int i = 0; i <= 10; i++) {
        pl[i + 1] = pl[i] * 10;
    }
    vc<int> ca(10, 0), ct(10, 0);
    for (int i = 0; i < 4; i++) {
        int now = s[i] - '0';
        ct[now]++;
        int noww = t[i] - '0';
        ca[noww]++;
        card[now]--;
        card[noww]--;
    }
    for (int i = 1; i < 10; i++) {
        nt += pl[ct[i]] * i;
    }
    for (int i = 1; i < 10; i++) {
        na += pl[ca[i]] * i;
    }
    for (int tk = 1; tk < 10; tk++) {
        for (int ao = 1; ao < 10; ao++) {
            if (tk == ao) {
                if (card[tk] >= 2) {
                    int nnt = nt - pl[ct[tk]] * tk + tk * pl[ct[tk] + 1];
                    int nat = na - pl[ca[ao]] * ao + ao * pl[ca[ao] + 1];
                    if (nnt > nat) {
                        ans += card[tk] * (card[tk] - 1);
                    }
                }
            } else {
                if (card[tk] > 0 && card[ao] > 0) {
                    int nnt = nt - pl[ct[tk]] * tk + tk * pl[ct[tk] + 1];
                    int nat = na - pl[ca[ao]] * ao + ao * pl[ca[ao] + 1];
                    if (nnt > nat) {
                        ans += (card[tk] * card[ao]);
                    }
                }
            }
        }
    }
    int cntt = (9 * k - 8) * (9 * k - 9);
    cout << fixed << setprecision(20) << double(ans) / cntt << endl;
}