#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define ALL(n) begin(n), end(n)
#define INF ((1 << 30) - 1)
#define LINF (1LL << 60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<int, int> pint;
struct cww
{
  cww()
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
} star;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, n) cin >> a[i];
  Int ans = 0;
  sort(a.begin(), a.end());
  vector<int> che(1000100, 0);
  for (int i = 0; i < n; i++)
  {
    if(che[a[i]]!=0) {
      che[a[i]]=2;
      continue;
    }
    else{
      for(int j=a[i]; j<1000100; j+=a[i]){
        che[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (che[a[i]] == 1)
      ans++;
  }
  cout << ans << endl;
  return 0;
}