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
    int n;
    n = 4;
    vvc<int> t;
    rep(a, 3) {
        rep(b, 3) {
            rep(c, 3) {
                rep(d, 3) {
                    vc<int> q;
                    q.push_back(a);
                    q.push_back(b);
                    q.push_back(c);
                    q.push_back(d);
                    t.push_back(q);
                }
            }
        }
    }
    int l = t.size();
    rep(i, l) {
        rep(j, l) {
            rep(k, l) {
                rep(x, l) {
                    vvc<int> mt;
                    mt.push_back(t[i]);
                    mt.push_back(t[j]);
                    mt.push_back(t[k]);
                    mt.push_back(t[x]);
                    bool ok = true;
                    vc<int> su;
                    rep(p, 4) {
                        int sum = 0;
                        rep(r, 4) { sum += mt[p][r]; }
                        su.push_back(sum);
                    }
                    rep(p, 4) {
                        int sum = 0;
                        rep(r, 4) { sum += mt[r][p]; }
                        su.push_back(sum);
                    }
                    sort(ALL(su));
                    for (int I = 0; I < su.size() - 1; I++) {
                        if (su[I] == su[I + 1]) ok = false;
                    }
                    if (ok) {
                        cout << "Yay" << endl;
                        rep(Z, 4) {
                            rep(U, 4) { cout << mt[Z][U] << " "; }
                            cout << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
}