#include <iostream>
using namespace std;
typedef long long Int;
Int INF = (1LL << 31) - 1;

Int seg[1 << 20];

void set_value(int ind, int v)
{
  ind += 1 << 19;
  seg[ind] = v;
  while ((ind /= 2) > 0)
  {
    seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
  }
}

Int get_min(int ql, int qr, int sl = 0, int sr = 1 << 19, int pos = 1)
{
  //ql,qr 要求区間
  //sl,sr seg木の区間
  if (qr <= sl || sr <= ql)
    return INF;
  if (ql <= sl && sr <= qr)
    return seg[pos];
  int sm = (sl + sr) / 2;
  int lmin = get_min(ql, qr, sl, sm, pos * 2);
  int rmin = get_min(ql, qr, sm, sr, pos * 2 + 1);
  return min(lmin, rmin);
}

int main()
{
  Int n, q, com, x, y;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    set_value(i, INF);
  }
  for (int i = 0; i < q; i++)
  {
    cin >> com >> x >> y;
    if (com == 0)
    {
      set_value(x, y);
    }
    else
    {
      cout << get_min(x, y + 1) << endl;
    }
  }
  return 0;
}