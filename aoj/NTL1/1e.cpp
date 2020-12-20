#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  int ga = __gcd(a, b);
  int y = b % a;
  if(y>abs(y-a)) y=y-a;
  int x = (ga - b * y) / a;
  cout << x << " " << y << endl;
  return 0;
}