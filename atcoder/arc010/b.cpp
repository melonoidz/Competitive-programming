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
vector<string> split(string& str, char del) {
    istringstream stream(str);

    string s;
    vector<string> ret;
    while (getline(stream, s, del)) {
        ret.push_back(s);
    }
    return ret;
}

void addHoliday(int m, int d, vector<bool>& holidays) {
    int n = d - 1;
    map<int, int> days = {{1, 31}, {2, 29},  {3, 31},  {4, 30},
                          {5, 31}, {6, 30},  {7, 31},  {8, 31},
                          {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    for (int i = 1; i < m; i++) {
        n += days[i];
    }

    int dayNum = holidays.size();
    while (n < dayNum && holidays[n]) {
        n++;
    }
    if (n < dayNum) {
        holidays[n] = true;
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    int dayNum = 366;
    vector<bool> holidays(dayNum);
    rep(i, dayNum) {
        if (i % 7 == 0 || i % 7 == 6) {
            holidays[i] = true;
        }
    }

    rep(i, N) {
        string str;
        cin >> str;
        vector<string> md = split(str, '/');
        addHoliday(atoi(md[0].c_str()), atoi(md[1].c_str()), holidays);
    }
    int ans = 0;
    rep(i, dayNum) {
        int j = i;
        while (i < dayNum && holidays[i]) {
            i++;
        }
        chmax(ans, i - j);
    }
    cout << ans << endl;
}