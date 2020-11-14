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
ll read()
{
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0)
{
  vi v(n);
  rep(i, n) v[i] = read() + off;
  return v;
}
pi readpi(int off = 0)
{
  int a, b;
  cin >> a >> b;
  return pi(a + off, b + off);
}
template <class T>
void print(const vector<T> &v, int suc = 1)
{
  rep(i, v.size())
      print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
string readString()
{
  string s;
  cin >> s;
  return s;
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


// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint
{
  int x;
  mint(int x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(int t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int h, w;
  cin >> h >> w;
  vc<string> f(h);
  rep(i, h) cin >> f[i];
  int l[2100][2100];
  int r[2100][2100];
  int u[2100][2100];
  int d[2100][2100];
  int k;
  rep(i, h)
  {
    rep(j, w)
    {
      if (f[i][j] == '.')
        k++;
    }
  }
  for (int i = 0; i < h; i++)
  {
    int cur = 0;
    for (int j = 0; j < w; j++)
    {
      if (f[i][j] == '#')
        cur = 0;
      else
      {
        cur++;
      }
      l[i][j] = cur;
    }
  }

  for (int i = 0; i < h; i++)
  {
    int cur = 0;
    for (int j = w - 1; j >= 0; j--)
    {
      if (f[i][j] == '#')
        cur = 0;
      else
      {
        cur++;
      }
      r[i][j] = cur;
    }
  }

  for (int i = 0; i < w; i++)
  {
    int cur = 0;
    for (int j = 0; j < h; j++)
    {
      if (f[j][i] == '#')
        cur = 0;
      else
      {
        cur++;
      }
      u[j][i] = cur;
    }
  }
  for (int i = 0; i < w; i++)
  {
    int cur = 0;
    for (int j = h - 1; j >= 0; j--)
    {
      if (f[j][i] == '#')
        cur = 0;
      else
      {
        cur++;
      }
      d[j][i] = cur;
    }
  }
  mint ans = 0;
  mint uu = 2;
  rep(i, h)
  {
    rep(j, w)
    {
      if (f[i][j] == '#')
        continue;
      int tmp = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
      ans += uu.pow(k) - uu.pow(k - tmp);
    }
  }
  cout << ans << endl;
}