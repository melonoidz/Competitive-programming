#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template <class T1, class T2>
ostream &operator<<(ostream &s, pair<T1, T2> P)
{
  return s << '<' << P.first << ", " << P.second << '>';
}
template <class T>
ostream &operator<<(ostream &s, vector<T> P)
{
  for (int i = 0; i < P.size(); ++i)
  {
    if (i > 0)
    {
      s << " ";
    }
    s << P[i];
  }
  return s;
}
template <class T>
ostream &operator<<(ostream &s, vector<vector<T>> P)
{
  for (int i = 0; i < P.size(); ++i)
  {
    s << endl
      << P[i];
  }
  return s << endl;
}
template <class T>
ostream &operator<<(ostream &s, set<T> P)
{
  for (auto it : P)
  {
    s << "<" << it << "> ";
  }
  return s << endl;
}
template <class T1, class T2>
ostream &operator<<(ostream &s, map<T1, T2> P)
{
  for (auto it : P)
  {
    s << "<" << it.first << "->" << it.second << "> ";
  }
  return s << endl;
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
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &r, long long n) noexcept
  {
    if (n == 0)
      return 1;
    if (n < 0)
      return modpow(modinv(r), -n);
    auto t = modpow(r, n / 2);
    t = t * t;
    if (n & 1)
      t = t * r;
    return t;
  }
  friend constexpr Fp<MOD> modinv(const Fp<MOD> &r) noexcept
  {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b)
    {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    return Fp<MOD>(u);
  }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<vector<long long>> fi(N, vector<long long>(K));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < K; ++j)
      cin >> fi[i][j];
  vector<mint> dp(K, 0), sdp(K + 1, 0), ndp(K, 0);
  dp[0] = 1, sdp[1] = 1;
  for (int i = 0; i < N; ++i)
  {
    ndp.assign(K, 0);
    for (int k = 0; k < K; ++k)
    {
      if (i == 0)
        ndp[k] = 1;
      else
      {
        int it = upper_bound(fi[i - 1].begin(), fi[i - 1].end(), fi[i][k]) - fi[i - 1].begin();
        ndp[k] = sdp[it];
      }
    }
    swap(dp, ndp);
    sdp.assign(K + 1, 0);
    for (int k = 0; k < K; ++k)
      sdp[k + 1] = sdp[k] + dp[k];
  }
  cout << sdp[K] << endl;
}