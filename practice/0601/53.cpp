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
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
int mx;
void solve(int n) {
    int left = 0;
    int right = n / 2;
    int cur = (left + right) / 2;
    int tmp, res;
    cout << "?"
         << " " << cur << endl;
    cin >> tmp;
    cout << "?"
         << " " << right << endl;
    cin >> res;
    if (tmp < res) {
        left = right;
        right = n;
        mx = res;
        //右区間
    } else {
        mx = tmp;
    }
    int l, r;
    bool ok = true;
    int num;
    while (ok) {
        int mid = (left + right) / 2;
        int submid = (left + mid) / 2;
        cout << "? " << submid << endl;
        cin >> l;
        cout << "? " << mid << endl;
        cin >> r;
        if (mx < l && l < r) {
            // まだ右に区間がある
            left = mid;
        } else {
            ok = false;
            if (mx < l && l > r) {
                right = mid;
                num = max(mx, r);
            } else {
                // mx>l
                right = submid;
                num = mx;
            }
        }
    }
    int v;
    while (abs(left - right) > 1) {
        int md = (left + right) / 2;
        cout << "? " << md << endl;
        cin >> v;
        if (v > num) {
            num = v;
            left = md;
        } else {
            right = md;
        }
    }
    cout << "! " << num << endl;
    return;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int T, N;
    cin >> T;
    rep(P, T) {
        cin >> N;
        solve(N);
    }
    return 0;
}