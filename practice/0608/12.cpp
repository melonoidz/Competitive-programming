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
    vc<int> a{1, 2, 3, 4, 5, 6, 7};
    vc<int> b{1, 2, 3, 4, 5, 6};
    do {
        auto tmp = a;
        do {
            bool cand = true;
            rep(i, b.size()) {
                if (b[i] % 2 == i % 2) cand = false;
            }
            if (!cand) continue;
            for (int i = 0; i < b.size(); i++) {
                int q = b[i];
                if (i % 2 == 0) {
                    if (q % 2 == 1) {
                        swap(tmp[q - 1], tmp[q]);
                        bool ok = true;
                        for (int x = 0; x < tmp.size(); x++) {
                            if (tmp[x] != x + 1) ok = false;
                        }
                        if (ok) {
                            cout << "OK!! " << endl;
                            rep(z, tmp.size()) cout << a[z] << " ";
                            cout << endl;
                            rep(J, b.size()) cout << b[J] << " ";
                            cout << endl;
                            cout << " =OUT " << endl;
                        }
                    }
                } else {
                    if (q % 2 == 0) {
                        swap(tmp[q - 1], tmp[q]);
                        bool ok = true;
                        for (int x = 0; x < tmp.size(); x++) {
                            if (tmp[x] != x + 1) ok = false;
                        }
                        if (ok) {
                            cout << "OK!! " << endl;
                            rep(z, tmp.size()) cout << a[z] << " ";
                            cout << endl;
                            rep(J, b.size()) cout << b[J] << " ";
                            cout << endl;
                            cout << " =OUT " << endl;
                        }
                    }
                }
            }
        } while (next_permutation(ALL(b)));
    } while (next_permutation(ALL(a)));
}