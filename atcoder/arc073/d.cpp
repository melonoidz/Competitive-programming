#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#else
#define dmp(x) void(0)
#endif
template <class t, class u>
void chmax(t &a, u b)
{
  if (a < b)
    a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
  if (b < a)
    a = b;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x, -1, sizeof(x))
#define zero(x) memset(x, 0, sizeof(x))
#ifdef LOCAL
void dmpr(ostream &os)
{
  os << endl;
}
template <class T, class... Args>
void dmpr(ostream &os, const T &t, const Args &... args)
{
  os << t << ;
  dmpr(os, args...);
}
#define dmp2(...) dmpr(cerr, __LINE__, ##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream &operator<<(ostream &os, const array<t, n> &a)
{
  return os << vc<t>(all(a));
}
template <class T>
void print(const vector<T> &v, int suc = 1)
{
  rep(i, v.size())
      print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
template <class T>
T sq(const T &t)
{
  return t * t;
}
constexpr ll ten(int n)
{
  return n == 0 ? 1 : ten(n - 1) * 10;
}
const ll infLL = LLONG_MAX / 3;
#ifdef int
const int inf = infLL;
#else
const int inf = INT_MAX / 2 - 100;
#endif
int topbit(signed t)
{
  return t == 0 ? -1 : 31 - __builtin_clz(t);
}
int topbit(ll t)
{
  return t == 0 ? -1 : 63 - __builtin_clzll(t);
}
int botbit(signed a)
{
  return a == 0 ? 32 : __builtin_ctz(a);
}
int botbit(ll a)
{
  return a == 0 ? 64 : __builtin_ctzll(a);
}
int popcount(signed t)
{
  return __builtin_popcount(t);
}
int popcount(ll t)
{
  return __builtin_popcountll(t);
}
bool ispow2(int i)
{
  return i && (i & -i) == i;
}
ll mask(int i)
{
  return (ll(1) << i) - 1;
}
template <class t>
int lwb(const vc<t> &v, const t &a)
{
  return lower_bound(all(v), a) - v.bg;
}
int lcm(int a, int b)
{
  return a / __gcd(a, b) * b;
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n, w;
  cin >> n >> w;
  vc<vc<int>> cnt(4, vc<int>(1, 0));
  int tmp = 0;
  rep(i, n)
  {
    int we, vi;
    cin >> we >> vi;
    if (i == 0)
    {
      tmp = we;
      cnt[0].push_back(vi);
    }
    else
    {
      cnt[we - tmp].push_back(vi);
    }
  }
  rep(i, 4) sort(cnt[i].begin(), cnt[i].end(), greater<int>());

  vc<vc<int>> su(4, vc<int>(110, 0));
  rep(i, 4)
  {
    rep(j, cnt[i].size())
    {
      su[i][j + 1] = su[i][j] + cnt[i][j];
    }
  }
  int ans = 0;
  rep(i, cnt[0].size())
  {
    rep(j, cnt[1].size())
    {
      rep(k, cnt[2].size())
      {
        rep(l, cnt[3].size())
        {
          int weight = tmp * i + (tmp + 1) * j + (tmp + 2) * k + (tmp + 3) * l;
          if (weight > w)
            continue;
          int cost = su[0][i] + su[1][j] + su[2][k] + su[3][l];
          ans = max(ans, cost);
        }
      }
    }
  }
  cout << ans << endl;
}