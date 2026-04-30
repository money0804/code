#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> la(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
	if(la[a[i]]==0) la[a[i]]=i;
	}
	int ma=la[a[1]];
	vector<int> dp(n+1,1e9); //store 0
	dp[0]=0;
	
	for(int i=1;i<=n;i++){
	dp[i]=min(dp[i],dp[i-1]+1);
	ma=max(ma,la[a[i]]);
	dp[ma]=min(dp[ma],dp[i]+1);
	}
	cout<<n-dp[n]<<'\n';
}
