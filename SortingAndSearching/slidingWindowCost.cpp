#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

typedef long long ll;
const int MOD = 1e9 + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
    init_code();
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    set<pair<int,int>> leftSet;
    set<pair<int,int>> rightSet;
    // int maxValue = 0;
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    if( k == 1){
        for(int i = 0; i<n;i++){
            cout << 0 << " ";
        }
        return 0;
    }
    if(k == 2){
        for(int i = 0; i<n-1;i++){
            cout << abs(values[i+1] - values[i]) << " ";
        }
        return 0;
    }
    vector<pair<int,int>> st;
    for(int i = 0; i< k; i++){
        st.push_back({values[i], i});
    }
    sort(st.begin(), st.end());
    ll leftSum = 0;
    ll rightSum = 0;
    for(int i = 0; i< k/2 + (k%2); i++){
        leftSet.insert(st[i]);
        leftSum += st[i].first;
    }
    for(int i = k/2 + (k%2); i < k; i++){
        rightSet.insert(st[i]);
        rightSum += st[i].first;
    }
    ll median = leftSet.rbegin()->first;
    cout << median*leftSet.size() - leftSum 
        + rightSum  - median*rightSet.size() << " ";
    for(int i = 1; i< n-k+1; i++){
        if(leftSet.count({values[i-1], i-1})){
            leftSum -= values[i-1];
            leftSet.erase({values[i-1], i-1});
        }else{
            rightSum -= values[i-1];
            rightSet.erase({values[i-1], i-1});
        }
        if(*(leftSet.rbegin()) < make_pair(values[k-1+i], k-1+i)){
            rightSet.insert({values[k-1+i], k-1+i});
            rightSum += values[k-1+i];
        }else{
            leftSet.insert({values[k-1+i], k-1+i});
            leftSum += values[k-1+i];
        }
        while(leftSet.size() < (k/2 + (k%2)) ){
            pair<int,int> z = (*rightSet.begin());
            leftSet.insert(z);
            leftSum += z.first;
            rightSet.erase(z);
            rightSum -= z.first;
        }
        while(leftSet.size() > (k/2+(k%2)) ){
            pair<int,int> z = (*leftSet.rbegin());
            rightSet.insert(z);
            rightSum += z.first;
            leftSet.erase(z);
            leftSum -= z.first;
        }
        median = leftSet.rbegin()->first;
        cout << median*leftSet.size()-leftSum 
            + rightSum - median*rightSet.size()<< " ";
    }
    return 0;
    // Other approach
    // {
    // // for(int i = 0; i<n-k+1 ;i++){
    // //     ll hi = 1e9;
    // //     ll lo = 0;
    // //     ll ans = 1e9;
    // //     ll cost = 0;
    // //     while(lo <= hi){
    // //         ll mid = (lo + hi) / 2;
    // //         for(int j = i; j < k; j++){
    // //             cost += abs(mid - values[j]);
    // //         }
    // //         if(cost < ans){
    // //             ans = cost;
    // //             hi = mid - 1;
    // //         }else{
    // //             lo = mid + 1;
    // //         }
    // //     }
    // //     cout << ans << " ";
    // // }
    // }
    
}