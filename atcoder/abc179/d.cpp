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
bool inc(int a, int b, int c)
{
  return a <= b && b <= c;
}
template <class t>
void mkuni(vc<t> &v)
{
  sort(all(v));
  v.erase(unique(all(v)), v.ed);
}
ll rand_int(ll l, ll r)
{ //[l, r]
#ifdef LOCAL
  static mt19937_64 gen;
#else
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t> &a)
{
  rep(i, si(a)) swap(a[i], a[rand_int(0, i)]);
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

// modint
template <int MOD>
struct Fp
{
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD)
  {
    if (val < 0)
      val += MOD;
  }
  constexpr int getmod() const { return MOD; }
  constexpr Fp operator-() const noexcept
  {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp &operator+=(const Fp &r) noexcept
  {
    val += r.val;
    if (val >= MOD)
      val -= MOD;
    return *this;
  }
  constexpr Fp &operator-=(const Fp &r) noexcept
  {
    val -= r.val;
    if (val < 0)
      val += MOD;
    return *this;
  }
  constexpr Fp &operator*=(const Fp &r) noexcept
  {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp &operator/=(const Fp &r) noexcept
  {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b)
    {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0)
      val += MOD;
    return *this;
  }
  constexpr bool operator==(const Fp &r) const noexcept
  {
    return this->val == r.val;
  }
  constexpr bool operator!=(const Fp &r) const noexcept
  {
    return this->val != r.val;
  }
  friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept
  {
    is >> x.val;
    x.val %= MOD;
    if (x.val < 0)
      x.val += MOD;
    return is;
  }
  friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
  {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
  {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};

const int MOD = 998244353;
using mint = Fp<MOD>;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vc<pi> v(k);
  rep(i, k)
  {
    cin >> v[i].first >> v[i].second;
  }
  vc<mint> dp(n, 0), sdp(n + 1, 0);
  dp[0] = 1, sdp[1] = 1;
  for (int a = 1; a < n; a++)
  {
    for (auto &p : v)
    {
      int left = max(0LL, a - p.second);
      int right = max(0LL, a - p.first + 1);
      dp[a] += sdp[right] - sdp[left];
    }
    sdp[a + 1] = sdp[a] + dp[a];
  }
  cout << dp[n - 1] << endl;
}