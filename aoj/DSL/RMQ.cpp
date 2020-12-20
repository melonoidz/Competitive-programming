#include <iostream>
using namespace std;
typedef long long Int;
Int INF = (1LL << 31) - 1;

Int seg[1 << 20];

void set_value(Int x, Int y)
{
  x += 1 << 19;
  seg[x] = y;
  while ((x /= 2) > 0)
  {
    seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
  }
}

Int get_min(Int ql, Int qr, Int sl = 0, Int sr = 1 << 19, Int pos = 1)
{
  if (qr <= sl || sr <= ql)
    return INF;
  if (ql <= sl && sr <= qr)
    return seg[pos];
  Int sm = (sl + sr) / 2;
  Int lmin = get_min(ql, qr, sl, sm, pos * 2);
  Int rmin = get_min(ql, qr, sm, sr, pos * 2 + 1);
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