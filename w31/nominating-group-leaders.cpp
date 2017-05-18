#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100005
struct query
{
    int l, r, x, id;
} q[N];
int block[318][100490];
int a[N], cnt[N], ans[N];
int t, n, g, n_block;

bool cmp(query & x, query & y)
{
    if (x.l / n_block == y.l / n_block)
        return x.r < y.r;
    return x.l / n_block < y.l / n_block;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &g);
    for (int i = 0; i < g; ++i)
    {
        scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].x);
        q[i].id = i;
    }
    memset(ans, -1, sizeof(ans));
    memset(cnt, 0, sizeof(cnt));
    memset(block, 0, sizeof(block));
    n_block = int(sqrt(n)) + 1;
    sort(q, q + g, cmp);
    int l = q[0].l, r = q[0].r;
    for (int i = l; i <= r; ++i)
    {
        --block[a[i] / n_block][cnt[a[i]]];
        ++cnt[a[i]];
        ++block[a[i] / n_block][cnt[a[i]]];
    }
    int x = q[0].x;
    for (int i = 0; i <= n / n_block; ++i)
        if (block[i][x])
        {
            for (int j = i * n_block; j < (i + 1) * n_block; ++j)
                if (cnt[j] == x)
                {
                    ans[q[0].id] = j;
                    break;
                }
            break;
        }
    for (int k = 1; k < g; ++k)
    {
        while (l < q[k].l)
        {
            --block[a[l] / n_block][cnt[a[l]]];
            --cnt[a[l]];
            ++block[a[l] / n_block][cnt[a[l]]];
            ++l;
        }
        while (r > q[k].r)
        {
            --block[a[r] / n_block][cnt[a[r]]];
            --cnt[a[r]];
            ++block[a[r] / n_block][cnt[a[r]]];
            --r;
        }
        while (l > q[k].l)
        {
            --l;
            --block[a[l] / n_block][cnt[a[l]]];
            ++cnt[a[l]];
            ++block[a[l] / n_block][cnt[a[l]]];
        }
        while (r < q[k].r)
        {
            ++r;
            --block[a[r] / n_block][cnt[a[r]]];
            ++cnt[a[r]];
            ++block[a[r] / n_block][cnt[a[r]]];
        }
        x = q[k].x;
        for (int i = 0; i <= n / n_block; ++i)
            if (block[i][x])
            {
                for (int j = i * n_block; j < (i + 1) * n_block; ++j)
                    if (cnt[j] == x)
                    {
                        ans[q[k].id] = j;
                        break;
                    }
                break;
            }
    }
    for (int k = 0; k < g; ++k)
        printf("%d\n", ans[k]);
}

int main()
{
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}