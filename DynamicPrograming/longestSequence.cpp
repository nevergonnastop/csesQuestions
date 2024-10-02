#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int getBestCandidate(map<int,int>&mp,int v){
    auto it= mp.lower_bound(v);
    if(it==mp.begin()){
        return 0;
    }
    else it--;
    return it->second;
}
void insert(map<int,int>&mp,int v, int dp){
    if(mp[v]>=dp)return;
    mp[v]=dp;
    auto it =mp.find(v);
    it++;
    while(it!=mp.end()&&it->second<=dp){
        auto temp= it;
        it++;
        mp.erase(temp);
    }
}
int solve(vector<int>&v,int n){
    map<int,int>mp;
    int dp[n];
    dp[0]=1;
    mp[v[0]]=dp[0];
    for(int i=1;i<n;i++){
        dp[i]=1+getBestCandidate(mp,v[i]);
        insert(mp,v[i],dp[i]);
    }
    // for(auto it: mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    return *max_element(dp,dp+n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<solve(v,n);
}