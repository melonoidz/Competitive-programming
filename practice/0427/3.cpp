#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define ALL(a) (a).begin(), (a).end()
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }

const double PI = std::acos(-1.0);
class Cone {
  private:
    int m_x_bottom;
    int m_x_top;
    int m_height;
    int m_radius;
    double m_tan_theta;

  public:
    Cone(const int x_bottom, const int height, const int radius) {
        m_x_bottom = x_bottom;
        m_x_top = x_bottom + height;
        m_height = height;
        m_radius = radius;
        m_tan_theta = (double)radius / (double)height;
    }
    double compute_volume(const int& lower, const int& upper) {
        if (m_x_bottom >= upper || m_x_top <= lower) {
            return 0.0;
        }
        int x_upper_bottom = std::min(m_x_top, upper);
        int x_lower_bottom = std::max(m_x_bottom, lower);
        double r_u = (double)(m_x_top - x_upper_bottom) * m_tan_theta;
        double r_l = (double)(m_x_top - x_lower_bottom) * m_tan_theta;
        double v = PI * (r_l * r_l + r_l * r_u + r_u * r_u) *
                   (x_upper_bottom - x_lower_bottom) / 3.0;
        return v;
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, q;
    std::cin >> n >> q;
    std::vector<Cone> cones;
    for (auto i = 0; i < n; i++) {
        int x_bottom, radius, height;
        std::cin >> x_bottom >> radius >> height;
        Cone cone(x_bottom, height, radius);
        cones.push_back(cone);
    }
    std::cout << std::setprecision(8) << std::fixed;
    for (auto j = 0; j < q; j++) {
        int a, b;
        std::cin >> a >> b;
        double v = 0.0;
        for (auto& cone : cones) {
            v += cone.compute_volume(a, b);
        }
        std::cout << v << std::endl;
    }
}