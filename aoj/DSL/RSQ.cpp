#include <iostream>
using namespace std;
#define SEG_LEN (1 << 20)
int seg[SEG_LEN * 2];

void add(int x, int y)
{
  x += SEG_LEN;
  seg[x] += y;
  while (1)
  {
    x /= 2;
    if (x == 0)
      break;
    seg[x] += y;
  }
}

int getsum(int l, int r)
{
  l += SEG_LEN;
  r += SEG_LEN;
  int ans = 0;
  while (l < r)
  {
    if (l % 2 == 1)
    {
      ans += seg[l];
      l++;
    }
    l /= 2;
    if (r % 2 == 1)
    {
      ans += seg[r - 1];
      r--;
    }
    r /= 2;
  }
  return ans;
}

int main()
{
  int n, q, com, x, y, s, t;
  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> com;
    if (com == 0)
    {
      //add
      cin >> x >> y;
      add(x, y);
    }
    else
    {
      // getsum
      cin >> s >> t;
      cout << getsum(s, t + 1) << endl;
    }
  }
}