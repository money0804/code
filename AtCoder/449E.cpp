#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define ll long long
#define int long long
#define F first
#define S second
#define pii pair<int,int>
#define mem(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define all(_v) _v.begin(), _v.end()
const ll INF = 1e18;
const int MAXN = 1e6+5;

class BIT {
public:
    vector<int> a;
    
    BIT(int n) {
        a.assign(n + 1, 0);
    }

    void add(int i, int x) {
        i++;
        while (i < a.size()) {
            a[i] += x;
            i += i & -i;
        }
    }

    int sum(int r) {
        int s = 0;
        while (r) {
            s += a[r];
            r -= r & -r;
        }
        return s;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    int lower_bound(int w) {
        int x = 0;
        int n = a.size() - 1;
        int k = 1;
        if (n > 0) {
            while (k * 2 <= n) k <<= 1;
        } else {
            k = 0;
        }
        
        while (k) {
            if (x + k <= n && a[x + k] < w) {
                w -= a[x + k];
                x += k;
            }
            k >>= 1;
        }
        return x + 1;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    vector<int> c(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }

    vector<pii> s(m);
    for (int i = 0; i < m; i++) {
        s[i] = {c[i], i};
    }
    sort(all(s));

    vector<int> r(m + 1, 0);
    r[0] = n;
    for (int i = 0; i < m - 1; i++) {
        r[i + 1] = (i + 1) * (s[i + 1].F - s[i].F) + r[i];
    }
    r[m] = INF + 2026;

    int q;
    cin >> q;
    vector<int> ans(q, -1);
    vector<array<int, 3>> que;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x <= n) {
            ans[i] = a[x - 1];
            continue;
        }
        int ng = 0, ok = m;
        while (ok - ng != 1) {
            int vs = (ok + ng) /2;
            if (r[vs] >= x) {
                ok = vs;
            } else {
                ng = vs;
            }
        }
        x -= r[ng] + 1;
        x %= ok;
        que.pb({ok, x, i});
    }
    
    sort(all(que));

    BIT fw(m);
    int idx = 0;
    for (const auto& q_item : que) {
        int ok = q_item[0];
        int x = q_item[1];
        int i = q_item[2];

        while (idx < ok) {
            fw.add(s[idx].S, 1);
            idx++;
        }
        ans[i] = fw.lower_bound(x + 1) - 1;
    }

    for (int v : ans) {
        cout << v + 1 << "\n";
    }

}
