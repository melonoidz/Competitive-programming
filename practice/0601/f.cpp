#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define int ll
typedef int FLOW;            // フローを表す型、今回は int 型
const int MAX_V = 100;       // グラフの最大ノード数
const FLOW INF = 100000000;  // 十分大きい値
int N, M, R, d, m;
vector<int> dog, monkey;
// グラフの辺の構造体
struct Edge {
    int rev, from, to;
    FLOW cap, icap;
    Edge(int r, int f, int t, FLOW c)
        : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator<<(ostream& s, const Edge& E) {
        if (E.cap > 0)
            return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else
            return s;
    }
};

// グラフ構造体
struct Graph {
    int V;
    vector<Edge> list[MAX_V];

    Graph(int n = 0) : V(n) {
        for (int i = 0; i < MAX_V; ++i) list[i].clear();
    }
    void init(int n = 0) {
        V = n;
        for (int i = 0; i < MAX_V; ++i) list[i].clear();
    }
    void resize(int n = 0) { V = n; }
    void reset() {
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < list[i].size(); ++j)
                list[i][j].cap = list[i][j].icap;
    }
    inline vector<Edge>& operator[](int i) { return list[i]; }

    Edge& redge(Edge e) {
        if (e.from != e.to)
            return list[e.to][e.rev];
        else
            return list[e.to][e.rev + 1];
    }

    void addedge(int from, int to, FLOW cap) {
        list[from].push_back(Edge((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
    }
};

// 最大流を求めるサブルーチンたち
static int level[MAX_V];
static int iter[MAX_V];

void dibfs(Graph& G, int s) {
    for (int i = 0; i < MAX_V; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            Edge& e = G[v][i];
            if (level[e.to] < 0 && e.cap > 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

FLOW didfs(Graph& G, int v, int t, FLOW f) {
    if (v == t) return f;
    for (int& i = iter[v]; i < G[v].size(); ++i) {
        Edge &e = G[v][i], &re = G.redge(e);
        if (level[v] < level[e.to] && e.cap > 0) {
            FLOW d = didfs(G, e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                re.cap += d;
                return d;
            }
        }
    }
    return 0;
}

// 最大流を求めるメイン関数
FLOW Dinic(Graph& G, int s, int t) {
    FLOW res = 0;
    while (true) {
        dibfs(G, s);
        if (level[t] < 0) return res;
        memset(iter, 0, sizeof(iter));
        FLOW flow;
        while ((flow = didfs(G, s, t, INF)) > 0) {
            res += flow;
        }
    }
}

signed main() {
    cin >> N >> M >> R;
    dog.resize(N, 0);
    monkey.resize(M, 0);

    // グラフの定義 (ノード数を引数に)
    Graph G(N + M + 2);  // +2 は S, T の分

    // スーパーノード S, T の index
    int S_node = N + M;
    int T_node = N + M + 1;

    for (int i = 0; i < R; i++) {
        cin >> d >> m;
        d--, m--;
        G.addedge(d, m + N, 1);
    }

    for (int i = 0; i < N; ++i) {
        // S から男 i へと、容量 1 の枝を張る
        G.addedge(S_node, i, 1);
    }

    for (int j = 0; j < M; ++j) {
        // 女 j から T へと、容量 1 の枝を張る
        G.addedge(j + N, T_node, 1);
    }

    // 最大流を求める
    FLOW res = Dinic(G, S_node, T_node);

    // 誰が誰とマッチしたのかを出力する
    for (int i = 0; i < N; ++i) {
        for (auto e : G[i]) {
            // 元々の容量 (e.icap) が 1 で、フローが流れて容量 (e.cap) が 0
            // になった部分が割り当てられたところ
            if (e.icap == 1 && e.cap == 0) {
                dog[i] = 1;
                monkey[e.to - N] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dog[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < M; i++) {
        cout << monkey[i] << " ";
    }
    cout << endl;
    int ans = 0;
    for (const auto& u : dog) {
        if (u == 1) ans++;
    }
    for (const auto& u : monkey) {
        if (u == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}