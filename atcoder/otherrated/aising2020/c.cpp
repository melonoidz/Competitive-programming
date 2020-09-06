#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP2(i, x, n) for (int i = x; i < (n); i++)
#define ALL(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans[10100];
    memset(ans, 0, sizeof(ans));
    for (int x = 1; x <= 110; x++)
    {
        for (int y = 1; y <= 110; y++)
        {
            for (int z = 1; z <= 110; z++)
            {
                long long cnt = x * x + y * y + z * z + x * y + y * z + z * x;
                if (cnt < 10100)
                {
                    ans[cnt]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}