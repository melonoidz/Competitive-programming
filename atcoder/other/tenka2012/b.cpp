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
ll s_to_v(string s) {
    if (s == "A") s = "1";
    if (s == "J") s = "11";
    if (s == "Q") s = "12";
    if (s == "K") s = "13";
    return stoll(s);
}

const string marks = "SHDC";
ll mark_to_v(char c) { return marks.find(c); }

ll ss_to_v(stringstream& ss) {
    ll v = s_to_v(ss.str());
    ss.str("");
    return v;
}

string v_to_str(ll v) {
    if (v == 1) return "A";
    if (v == 11) return "J";
    if (v == 12) return "Q";
    if (v == 13) return "K";
    return to_string(v);
}

void trash(pi pa) {
    ll m = pa.first;
    ll v = pa.second;
    cout << marks[m] << v_to_str(v);
}
int L;
int inf = 1LL << 60;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    L = s.size();
    vc<pi> V;
    int mark;
    stringstream ss;
    rep(i, L) {
        char c = s[i];
        if (c == 'S' || c == 'H' || c == 'D' || c == 'C') {
            if (ss.str().size() != 0) {
                ll v = ss_to_v(ss);
                V.push_back(make_pair(mark, v));
            }
            mark = mark_to_v(c);  // next mark
        } else {
            ss << c;
        }
    }
    V.push_back(make_pair(mark, ss_to_v(ss)));
    ll N = V.size();

    // どのマークで揃えるのが一番早い？
    mark = -1;
    ll min_t = inf;
    rep(m, 4) {
        set<ll> se;  // 10,11,12,13,1
        rep(i, N) {
            if (V[i].first != m) continue;
            ll v = V[i].second;
            if (v == 1 || v == 10 || v == 11 || v == 12 || v == 13) {
                se.insert(v);
                if (se.size() == 5) {
                    ll t = i;
                    if (t < min_t) {
                        mark = m;
                        min_t = t;
                    }
                }
            }
        }
    }
    if (min_t == 4) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, min_t + 1) {
        ll m = V[i].first;
        if (mark != m) {
            trash(V[i]);
            continue;
        }
        ll v = V[i].second;
        if (v == 1 || v == 10 || v == 11 || v == 12 || v == 13) {
            // take
        } else {
            trash(V[i]);
        }
    }
    cout << endl;
}