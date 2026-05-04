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
int a[6000][4];
int dp[5][30000000];
signed main(){
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
        int b,c,d;
        cin>>b>>c>>d;
        for(int i=x;i>=d;i--){
            dp[b][i]=max(dp[b][i],dp[b][i-d]+c);
        }
		}
int te=0,ans;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=x-i;j++){
            int c=x-i-j;
            ans=min(min(dp[1][i],dp[2][j]),dp[3][c]);
            //cout<<ans<<'\n';
            te=max(te,ans);
        }
    }
    cout<<te;
}
