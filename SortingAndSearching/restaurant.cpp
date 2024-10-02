#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
    int n;
    cin >> n;
    vector<pair<int,int>> customers;
    for(int i= 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        customers.push_back({start, 1});
        customers.push_back({end, -1});
    }
    sort(customers.begin(),customers.end());
    int cur = 0;
    int maxAns = 0;
    for(auto cus: customers){
        cur += cus.second;
        maxAns = max(maxAns, cur);
    }
    cout << maxAns;

    return 0;
}