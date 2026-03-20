#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define ll long long
#define int long long
#define vvi vector<vector<int>>
#define vvd vector<vector<double>>
#define F first
#define S second
#define pii pair<int,int>
#define mem(a, v) memset(a, v, sizeof(a))
#define pb push_back

const ll INF = 1e18;
const int MAXN = 1e6+5;
int n,k;
int a[20];
unordered_map<int,int> dp[20];

int dfs(int pos, int p, bool lim, bool st) {

    if (pos == -1) return st && p <= k;

    if (!lim && st && dp[pos].count(p)) return dp[pos][p];

    int li = lim ? a[pos] : 9;
    int ans = 0;

    for (int i = 0; i <= li; i++) {
        bool ns = st || (i != 0);
        
        int next_p;
        if (!ns) {
            next_p = 1; 
        } else {
            next_p = st ? p * i : i;
        }

        ans += dfs(pos - 1, next_p, lim && (i == a[pos]), ns);
    }

    if (st) dp[pos][p] = ans;
    return ans;
}
long long solve(long long x) {
    if (x < 0) return 0;
    int len = 0;
    while (x > 0) {
        a[len++] = x % 10;
        x /= 10;
    }
    if (len == 0) { 
        a[len++] = 0;
    }
for (int i = 0; i < 20; i++) dp[i].clear();
    return dfs(len - 1, 1,true, false);
}

signed main(){
cin>>n>>k;
cout<<solve(n)<<'\n';
}