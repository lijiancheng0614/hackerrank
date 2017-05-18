#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define M 100005
#define N 100005
const double eps = 1e-3;
struct edge
{
    int u, v, a, b;
    double d;
    bool operator<(const edge &i) const
    {
        return d < i.d;
    }
} e[M];
int f[N];
int n, m, ansa, ansb;

int getf(int k)
{
    if (f[k] == k)
        return k;
    return f[k] = getf(f[k]);
}

double kruskal(double ans)
{
    for (int i = 0; i < m; ++i)
    {
        f[i] = i;
        e[i].d = e[i].b - e[i].a * ans;
    }
    sort(e, e + m);
    ansa = ansb = 0;
    int s = n - 1;
    for (int i = 0; i < m; ++i)
    {
        int fu = getf(e[i].u);
        int fv = getf(e[i].v);
        if (fu != fv)
        {
            f[fu] = fv;
            ansa += e[i].a;
            ansb += e[i].b;
            --s;
            if (!s)
                break;
        }
    }
    return double(ansb) / ansa;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
    double ans = 0;
    while (1)
    {
        double t = kruskal(ans);
        if (fabs(t - ans) < eps)
            break;
        ans = t;
    }
    int g = __gcd(ansa, ansb);
    ansa /= g;
    ansb /= g;
    printf("%d/%d\n", ansa, ansb);
}

int main()
{
    solve();
    return 0;
}