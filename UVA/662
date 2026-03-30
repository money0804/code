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
    int n,m;
    int a[210]; 
    int dp[210][30];
    int co[210][210];
    int path[210][30];
signed main(){
    int su=0;
    while(cin>>n>>m&&(n||m)){
        su++;
        mem(dp,0x3f);
        mem(a,0);
        mem(co,0);
        mem(path,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=i;x<=j;x++){
                    co[i][j]+=abs(a[x]-a[(i+j)/2]);
                }
               // cout<<i<<" "<<j<<' '<<co[i][j]<<'\n';
            }
        }
        for(int i=1;i<=n;i++){
                dp[i][1]=co[1][i];
            }

        for(int i=1;i<=n;i++){
            for(int j=2;j<=m;j++){
                for(int x=1;x<i;x++){
                    if(dp[x][j-1]+co[x+1][i]<dp[i][j]){
                    dp[i][j]=dp[x][j-1]+co[x+1][i];
                    path[i][j]=x;
            }

        }
                    //cout<<i<<" "<<j<<' '<<path[i][j]<<endl;
    }
}
    vector<int > ans;
    ans.pb(n);
    int tn=n;
    for(int i=m;i>=2;i--){
        ans.pb(path[tn][i]+1);
        ans.pb(path[tn][i]);
        tn=path[tn][i];
    }
    ans.pb(1);
    reverse(all(ans));
// for(int i=0;i<ans.size();i++){
//             cout<<"aa "<<ans[i]<<'\n';
// }
//if(su!=1) cout<<endl;
    cout<<"Chain "<<su<<'\n';
    int id=0;
    for(int i=1;i<=m;i++){
        if(ans[id]!=ans[id+1]){
        cout<<"Depot "<<i<<" at restaurant "<<(ans[id]+ans[id+1])/2;
        cout<<" serves restaurants "<<ans[id++]<<" to ";
        cout<<ans[id++]<<'\n';
        }
        else{
        cout<<"Depot "<<i<<" at restaurant "<<(ans[id]+ans[id+1])/2;
        cout<<" serves restaurant "<<ans[id++]<<'\n';
        id++;
        }
    }
    cout<<"Total distance sum = "<<dp[n][m]<<'\n'<<'\n';
    }
}
