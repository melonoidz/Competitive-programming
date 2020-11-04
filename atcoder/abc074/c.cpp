#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000000000000LL
#define MOD 1000000007
#define writeln(n) cout << n << endl;
#define int long long
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

signed main()
{
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<tuple<int, int, int, int, double>> tmp;
  double ans = 0.0;
  for (int i = 0; i <= 30; i++)
  {
    for (int j = 0; j <= 30; j++)
    {
      for (int p = 0; p <= 100; p++)
      {
        for (int q = 0; q <= 100; q++)
        {
          int w = (100 * a) * i + (100 * b) * j;
          int s = c * p + d * q;
          if (w == 0)
            break;
          if (w + s > f)
            break;
          else
          {
            if (w / 100.0 * e >= s)
            {
              double den = (double)(100.0 * s / (w + s));
              ans = max(ans, den);
              tmp.emplace_back(i, j, p, q, den);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < (int)tmp.size(); i++)
  {
    if (get<4>(tmp[i]) == ans)
    {
      cout << 100 * a * get<0>(tmp[i]) + 100 * b * get<1>(tmp[i]) + c * get<2>(tmp[i]) + d * get<3>(tmp[i]) << " " << c * get<2>(tmp[i]) + d * get<3>(tmp[i]) << endl;
      return 0;
    }
  }

  return 0;
}