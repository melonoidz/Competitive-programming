#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) \
    for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
    for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
template <typename T> void ndarray(vector<T>& vec, int len) { vec.resize(len); }
template <typename T, typename... Args>
void ndarray(vector<T>& vec, int len, Args... args) {
    vec.resize(len);
    for (auto& v : vec) ndarray(v, args...);
}
template <typename V, typename T> void ndfill(V& x, const T& val) { x = val; }
template <typename V, typename T> void ndfill(vector<V>& vec, const T& val) {
    for (auto& v : vec) ndfill(v, val);
}
template <typename T> bool chmax(T& m, const T q) {
    if (m < q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T> bool chmin(T& m, const T q) {
    if (m > q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) {
    return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) {
    return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T> vector<T> srtunq(vector<T> vec) {
    sort(vec.begin(), vec.end()),
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}
template <typename T> istream& operator>>(istream& is, vector<T>& vec) {
    for (auto& v : vec) is >> v;
    return is;
}
template <typename... T> istream& operator>>(istream& is, tuple<T...>& tpl) {
    std::apply([&is](auto&&... args) { ((is >> args), ...); }, tpl);
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << '[';
    for (auto v : vec) os << v << ',';
    os << ']';
    return os;
}
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl) {
    std::apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl);
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& vec) {
    os << "deq[";
    for (auto v : vec) os << v << ',';
    os << ']';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& pa) {
    os << '(' << pa.first << ',' << pa.second << ')';
    return os;
}
template <typename TK, typename TV>
ostream& operator<<(ostream& os, const map<TK, TV>& mp) {
    os << '{';
    for (auto v : mp) os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}
template <typename TK, typename TV>
ostream& operator<<(ostream& os, const unordered_map<TK, TV>& mp) {
    os << '{';
    for (auto v : mp) os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}
#define dbg(x) \
    cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

// Count elements in [A_begin, ..., A_{end-1}] which satisfy A_i < query
// Complexity: O(N log^2 N) for initialization, O(log^2 N) for each query
// Verified: cntLess <https://codeforces.com/contest/1288/submission/68865506>
struct CountLessThan {
    using T = int;
    int N;
    int head;
    vector<vector<T>> x;
    inline void merge(int pos) {
        x[pos] = x[pos * 2 + 1];
        x[pos].insert(x[pos].end(), x[pos * 2 + 2].begin(),
                      x[pos * 2 + 2].end());
        sort(x[pos].begin(), x[pos].end());
    }
    int _getless(int begin, int end, int pos, int l, int r, T query) const {
        if (r <= begin or l >= end) return 0;
        if (l >= begin and r <= end)
            return lower_bound(x[pos].begin(), x[pos].end(), query) -
                   x[pos].begin();
        return _getless(begin, end, 2 * pos + 1, l, (l + r) / 2, query) +
               _getless(begin, end, 2 * pos + 2, (l + r) / 2, r, query);
    }
    int _getlesseq(int begin, int end, int pos, int l, int r, T query) const {
        if (r <= begin or l >= end) return 0;
        if (l >= begin and r <= end)
            return upper_bound(x[pos].begin(), x[pos].end(), query) -
                   x[pos].begin();
        return _getlesseq(begin, end, 2 * pos + 1, l, (l + r) / 2, query) +
               _getlesseq(begin, end, 2 * pos + 2, (l + r) / 2, r, query);
    }
    CountLessThan() = default;
    CountLessThan(const vector<T>& vec) : N(vec.size()) {
        int N_tmp = 1;
        while (N_tmp < N) N_tmp <<= 1;
        x.resize(N_tmp * 2), head = N_tmp - 1;
        for (int i = 0; i < N; i++) x[head + i] = {vec[i]};
        for (int i = head - 1; i >= 0; i--) merge(i);
    }
    int cntLess(int begin, int end, T query) const {
        return _getless(begin, end, 0, 0, (int)x.size() / 2, query);
    }
    int cntLesseq(int begin, int end, T query) const {
        return _getlesseq(begin, end, 0, 0, (int)x.size() / 2, query);
    }
    int cntMore(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLesseq(begin, end, query);
    }
    int cntMoreeq(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLess(begin, end, query);
    }

    friend ostream& operator<<(ostream& os, const CountLessThan& clt) {
        os << '[';
        for (int i = 0; i < clt.N; i++) os << clt.x[clt.head + i][0] << ',';
        os << ']';
        return os;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    cin >> C;
    vector<int> nxt(N, N);
    map<int, int> last;
    IREP(i, N) {
        if (last.count(C[i])) nxt[i] = last[C[i]];
        last[C[i]] = i;
    }
    CountLessThan st(nxt);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << r - l - st.cntLess(l, r, r) << '\n';
    }
}
