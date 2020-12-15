#include <iostream>
using namespace std;
#define SEG_LEN (1 << 18)

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

long long int get(int ind)
{
  ind += SEG_LEN;
  long long int sum = 0;
  sum += seg[ind];
  while (1)
  {
    ind /= 2;
    if (ind == 0)
      break;
    sum += seg[ind];
  }
  return sum;
}

int main()
{
  int n, q, com, s, t, x, i;
  cin >> n >> q;
  for (int z = 0; z < q; z++)
  {
    cin >> com;
    if (com == 0)
    {
      //add
      cin >> s >> t >> x;
      add(s, t + 1, x);
    }
    if (com == 1)
    {
      //get num
      cin >> i;
      cout << get(i) << endl;
    }
  }
  return 0;
}