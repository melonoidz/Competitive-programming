#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define rer(i, l, u) for (int(i) = (int)(l); (i) <= (int)(u); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r, v) auto r = (v)
#else
#define aut(r, v) typeof(v) r = (v)
#endif
#define each(it, o) for (aut(it, (o).begin()); it != (o).end(); ++it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair((x), (y))
#define mset(m, v) memset(m, v, sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long> > vpll;
typedef vector<string> vs;
typedef long double ld;
template <typename T, typename U> inline void amin(T& x, U y) {
    if (y < x) x = y;
}
template <typename T, typename U> inline void amax(T& x, U y) {
    if (x < y) x = y;
}

struct To {
    typedef int Vertex;
    Vertex to;
    To() {}
    To(Vertex to_) : to(to_) {}
};
template <typename To_> struct StaticGraph {
    typedef To_ To;
    typedef typename To::Vertex Vertex;
    typedef std::pair<Vertex, To> Edge;
    typedef const To* const_iterator;

    void init(int n_, const std::vector<Edge>& edges) {
        n = n_;
        int m = edges.size();
        tos.resize(m + 1);
        offsets.resize(n + 1);
        for (int e = 0; e < m; e++) offsets[edges[e].first]++;
        for (int v = 1; v <= n_; v++) offsets[v] += offsets[v - 1];
        for (int e = 0; e < m; e++)
            tos[--offsets[edges[e].first]] = edges[e].second;
    }
    int numVertices() const { return n; }
    int numEdges() const { return tos.size() - 1; }

    inline const_iterator edgesBegin(int v) const { return &tos[offsets[v]]; }
    inline const_iterator edgesEnd(int v) const { return &tos[offsets[v + 1]]; }

  private:
    int n;
    std::vector<To> tos;
    std::vector<int> offsets;
};

class SchieberVishkinLCA {
  public:
    typedef StaticGraph<To> Graph;
    typedef unsigned Word;
    typedef Graph::Vertex Vertex;

  private:
    static inline Word lowestOneBit(Word v) { return v & (~v + 1); }
    static inline Word highestOneBitMask(Word v) {
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        return v >> 1;
    }

    std::vector<Word> indices;          // Vertex -> index
    std::vector<Word> maxHIndices;      // Vertex -> index
    std::vector<Word> ancestorHeights;  // Vertex -> Word
    std::vector<Vertex> pathParents;    // index-1 -> Vertex
  public:
    // gは親→子の枝のある根付き木
    void build(const Graph& g, Vertex root) {
        return build(g, std::vector<Vertex>(1, root));
    }
    void build(const Graph& g, const std::vector<Vertex>& roots) {
        int N = g.numVertices();

        ancestorHeights.resize(N);
        std::vector<Vertex> parents(N);
        maxHIndices.resize(N);
        std::vector<Vertex> vertices;
        vertices.reserve(N);
        indices.resize(N);

        // inorder traversal
        Word currentIndex = 1;
        for (int ri = 0; ri < (int)roots.size(); ri++) {
            Vertex root = roots[ri];
            parents[root] = root;  //利便さのために
            vertices.push_back(root);
        }
        while (!vertices.empty()) {
            Vertex v = vertices.back();
            vertices.pop_back();
            indices[v] = currentIndex++;
            for (const Graph::To* it = g.edgesBegin(v); it != g.edgesEnd(v);
                 ++it) {
                parents[it->to] = v;
                vertices.push_back(it->to);
            }
        }

        // BFS (トポロジカル順序を求めるために)
        int head = 0, tail = roots.size();
        vertices.resize(N);
        for (int ri = 0; ri < (int)roots.size(); ri++) vertices[ri] = roots[ri];
        while (head != tail) {
            Vertex v = vertices[head++];
            for (const Graph::To* it = g.edgesBegin(v); it != g.edgesEnd(v);
                 ++it)
                vertices[tail++] = it->to;
        }

        //深い方から
        for (std::vector<Vertex>::const_iterator it = vertices.begin();
             it != vertices.end(); ++it)
            maxHIndices[*it] = indices[*it];
        for (std::vector<Vertex>::const_reverse_iterator it = vertices.rbegin();
             it != vertices.rend(); ++it) {
            Vertex v = *it, parent = parents[v];
            if (lowestOneBit(maxHIndices[parent]) <
                lowestOneBit(maxHIndices[v]))
                maxHIndices[parent] = maxHIndices[v];
        }

        // Aを求める
        for (int ri = 0; ri < (int)roots.size(); ri++) {
            Vertex root = roots[ri];
            ancestorHeights[root] = 0;
        }
        for (std::vector<Vertex>::const_iterator it = vertices.begin();
             it != vertices.end(); ++it) {
            Vertex v = *it;
            ancestorHeights[v] =
                ancestorHeights[parents[v]] | lowestOneBit(maxHIndices[v]);
        }

        pathParents.swap(parents);  //メモリをけちる
        for (int ri = 0; ri < (int)roots.size(); ri++) {
            Vertex root = roots[ri];
            pathParents[indices[root] - 1] = root;
        }
        for (std::vector<Vertex>::const_iterator it = vertices.begin();
             it != vertices.end(); ++it) {
            Vertex v = *it;
            for (const Graph::To* jt = g.edgesBegin(v); jt != g.edgesEnd(v);
                 ++jt) {
                if (maxHIndices[v] != maxHIndices[jt->to])
                    pathParents[indices[jt->to] - 1] = v;
                else
                    pathParents[indices[jt->to] - 1] =
                        pathParents[indices[v] - 1];
            }
        }
    }

    Vertex query(Vertex v, Vertex u) const {
        // binary tree上でのLCAの高さを求める
        Word Iv = maxHIndices[v], Iu = maxHIndices[u];
        Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
        Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
        Word j =
            lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
        // j = hI(lca(v,u)) となる (ここで、hI(x) = 2^(complete binary
        // tree上でのI(x)の高さ), I(x) = maxHIndices[x]) (hI(lca(v,u)) =
        // j)はhI(v)かhI(u)かその他の最大値。そして一意であることを考えると…
        Vertex x, y;
        if (j == hIv)
            x = v;
        else {  // lcaはvのパス上には無い
            Word kMask = highestOneBitMask(
                ancestorHeights[v] &
                (j - 1));  // vの祖先で、jよりは低いけどその中で一番上にあるパス
            x = pathParents[(indices[v] & ~kMask | (kMask + 1)) -
                            1];  // indices[v]のkの高さの祖先のパスの親
        }
        if (j == hIu)
            y = u;
        else {  // lcaはuのパス上には無い
            Word kMask = highestOneBitMask(
                ancestorHeights[u] &
                (j - 1));  // uの祖先で、jよりは低いけどその中で一番上にあるパス
            y = pathParents[(indices[u] & ~kMask | (kMask + 1)) -
                            1];  // indices[u]のkの高さの祖先のパスの親
        }
        return indices[x] < indices[y]
                   ? x
                   : y;  // in-orderなので、インデックスが低い方が祖先なはず
    }
};

typedef SchieberVishkinLCA::Graph Graph;

vector<vi> g;
vector<Graph::Edge> edges;
vector<int> depth;

void dfs(int i, int p, int d) {
    depth[i] = d;
    each(j, g[i]) if (*j != p) {
        edges.push_back(Graph::Edge(i, *j));
        dfs(*j, i, d + 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    g.assign(N, vi());
    rep(i, N - 1) {
        int x;
        scanf("%d", &x), --x;
        g[x].push_back(i + 1);
    }
    depth.assign(N, 0);
    dfs(0, -1, 0);
    SchieberVishkinLCA lca;
    Graph gg;
    gg.init(N, edges);
    lca.build(gg, 0);
    int Q;
    scanf("%d", &Q);
    rep(ii, Q) {
        int u, d;
        scanf("%d%d", &u, &d), --u;
        int c = lca.query(a, b);
        int ans = depth[a] + depth[b] - depth[c] * 2 + 1;
        printf("%d\n", ans);
    }
    return 0;
}
