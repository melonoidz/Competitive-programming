#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int INF = 1e9;
ld fans = INF;
struct UnionFind {
    int num;           //連結成分の数
    vector<int> r, p;  //そのグループのサイズ,自分の親っぽいやつ
    UnionFind() {}
    UnionFind(int n) : num(n), r(n, 1), p(n, 0) { iota(p.begin(), p.end(), 0); }

    int find(int x) {  //どのグループに所属するか
        return (x == p[x]
                    ? x
                    : p[x] = find(
                          p[x]));  // xがグループの名前と一致するまでxを親にする
    }

    bool same(int x, int y) {  //同じグループかどうか
        return find(x) == find(y);
    }

    void unite(int x, int y) {  // xとyを同じグループにする
        x = find(x);
        y = find(y);  // xとyのグループの名前をどっちかが変える
        if (x == y) return;
        if (r[x] < r[y]) swap(x, y);  //サイズが大きい方をxとする
        r[x] += r[y];  // yの親をxにする（今までyだったグループ名がxになる）
        p[y] = x;
        num--;
    }

    int size(int x) {  //グループの大きさ
        return r[find(x)];
    }

    int count() const {  //グループの数
        return num;
    }
};
template <typename T> void chmin(T& a, T b) {
    if (a > b) a = b;
}
typedef pair<int, int> P;
typedef pair<ld, P> IP;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n), c(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
    vector<int> X(m), Y(m), C(m);
    for (int i = 0; i < m; i++) cin >> X[i] >> Y[i] >> C[i];

    for (int i = 0; i < (1 << m); i++) {
        vector<int> use;
        int tmp = i;
        for (int j = 0; j < m; j++) {
            if (tmp & 1) use.push_back(j);
            tmp /= 2;
        }
        int N = n + use.size();
        vector<IP> edge;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                ld cost = 0;
                int tx, ty, tc, sx, sy, sc;
                if (i < n)
                    tx = x[i], ty = y[i], tc = c[i];
                else
                    tx = X[use[i - n]], ty = Y[use[i - n]], tc = C[use[i - n]];
                if (j < n)
                    sx = x[j], sy = y[j], sc = c[j];
                else
                    sx = X[use[j - n]], sy = Y[use[j - n]], sc = C[use[j - n]];
                cost = sqrt((tx - sx) * (tx - sx) + (ty - sy) * (ty - sy));
                if (tc != sc) cost *= 10;
                edge.push_back(IP(cost, P(i, j)));
            }
        }
        UnionFind uf(N);
        ld ans = 0;
        sort(edge.begin(), edge.end());
        for (auto p : edge) {
            ld co = p.first;
            int u = p.second.first, v = p.second.second;
            if (uf.same(u, v)) continue;
            ans += co;
            uf.unite(u, v);
        }
        chmin(fans, ans);
    }
    cout << fixed << setprecision(12) << fans << endl;
}
