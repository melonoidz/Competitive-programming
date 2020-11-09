#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
signed main()
{
  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<map<int, int>> hh;
  vector<map<int, int>> ww;
  hh.resize(h + 10);
  ww.resize(w + 10);
  vector<vector<bool>> check(h, vector<bool>(w, false));
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    hh[a].emplace(b, 1);
    ww[b].emplace(a, 1);
  }
  rep(i, m)
  {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    hh[c].emplace(d, -1);
    ww[d].emplace(c, -1);
  }
  int ans = 0;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if ((hh[i].count(i) != 0) && (ww[j].count(j) != 0))
      {
        if ((hh[i].at(i) == 1) && (ww[j].at(j) == 1))
        {
          if (!check[i][j])
          {
            check[i][j] = true;
            ans++;
          }
        }
      }
      else
      {
        auto hu = hh[i].lower_bound(i);
        auto hd = hh[i].upper_bound(i);
        auto wl = ww[j].lower_bound(j);
        auto wr = ww[j].upper_bound(j);
        if (hu->second == 1 || hd->second == 1 || wl->second == 1 || wr->second == 1)
        {
          if (!check[i][j])
          {
            check[i][j] = true;
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}