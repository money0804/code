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
int n;
int a[15];
unordered_set<int > an;
void solve(int id,vector<int> &gr){
    if(id>n){
        int te=0;
        for(int v:gr){
            te^=v;
        }
        an.insert(te);
        return;
    }
    for(int i=0;i<gr.size();i++){
        gr[i]+=a[id];
        solve(id+1,gr);
        gr[i]-=a[id];
    }
    gr.pb(a[id]);
    solve(id+1,gr);
    gr.pop_back();
}

signed main(){
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
vector<int> gr;
solve(1,gr);
cout<<an.size()<<'\n';

}
