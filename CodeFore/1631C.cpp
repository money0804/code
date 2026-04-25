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
int t,n,k;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        if((k==3&&n==4)||(n==2&&k==1)) cout<<-1<<'\n';
        else{
            if(k==0){
            for(int i=0;i<n/2;i++){
                cout<<i<<' '<<n-1-i<<'\n';
        }   
            }
            else if(k>0&&k<n-1){
            for(int i=1;i<n/2;i++){
                if(i!=k&&n-1-i!=k){
                    //cout<<"aa "<<k;
                cout<<i<<' '<<n-1-i<<'\n';
            }
        }
        cout<<k<<' '<<n-1<<'\n';
        if(k!=0)
        cout<<0<<' '<<n-1-k<<'\n';
            }
            else{
                cout<<n-1<<' '<<n-2<<'\n';
                cout<<n-3<<' '<<1<<'\n';
                cout<<0<<' '<<2<<'\n';
            for(int i=1;i<n/2;i++){
                if(i==1||i==0||i==2||n-1-i==n-1) continue;
                cout<<i<<' '<<n-1-i<<'\n';
        }
            }
        }
    }//
}
