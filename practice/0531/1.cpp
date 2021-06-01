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

class BIT {
  public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n) : n(n), a(n + 1, 0) {}

    // a[i]にxを加算する
    void add(ll i, ll x) {
        i++;
        if (i == 0) return;
        for (ll k = i; k <= n; k += (k & -k)) {
            a[k] += x;
        }
    }

    // a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i, ll j) { return sum_sub(j) - sum_sub(i - 1); }

    // a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i) {
        i++;
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k -= (k & -k)) {
            s += a[k];
        }
        return s;
    }

    // a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x) {
        if (x <= 0) {
            // xが0以下の場合は該当するものなし→0を返す
            return 0;
        } else {
            ll i = 0;
            ll r = 1;
            //最大としてありうる区間の長さを取得する
            // n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while (r < n) r = r << 1;
            //区間の長さは調べるごとに半分になる
            for (int len = r; len > 0; len = len >> 1) {
                //その区間を採用する場合
                if (i + len < n && a[i + len] < x) {
                    x -= a[i + len];
                    i += len;
                }
            }
            return i;
        }
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int q;
    cin >> q;
    BIT S(200200);
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            // Add
            int x;
            cin >> x;
            S.add(x, 1);
        } else {
            int x;
            cin >> x;
            auto d = S.lower_bound(x);
            cout << d << endl;
            S.add(d, -1);
        }
    }
}