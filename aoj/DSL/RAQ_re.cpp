#include <iostream>
using namespace std;
#define SEG_LEN (1 << 20)
int seg[SEG_LEN * 2];

void add(int l, int r, int x)
{
  l += SEG_LEN;
  r += SEG_LEN;
  while (l < r)
  {
    if (l % 2 == 1)
    {
      seg[l] += x;
      l++;
    }
    l /= 2;
    if (r % 2 == 1)
    {
      seg[r - 1] += x;
      r--;
    }
    r /= 2;
  }
}
int get(int ind)
{
  ind += SEG_LEN;
  int ans = 0;
  ans += seg[ind];
  while (1)
  {
    ind /= 2;
    if (ind == 0)
      break;
    ans += seg[ind];
  }
  return ans;
}

int main()
{
  int n, q, com, s, t, x, ind;
  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> com;
    if (com == 0)
    {
      //add
      cin >> s >> t >> x;
      add(s, t + 1, x);
    }
    else
    {
      //get
      cin >> ind;
      cout<<get(ind)<<endl;
    }
  }
}