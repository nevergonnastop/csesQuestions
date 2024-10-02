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
bool comp(const vector<int>& a, const vector<int>& b){
    return a[a.size()-1] < b[b.size()-1];
}
int main(){
    init_code();
    int n;
    cin >> n;
    vector<vector<int>> customers(n);
    for(int i= 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        customers[i] = {start,end};
    }
    sort(customers.begin(),customers.end(), comp);
    int ans = 1, maxEnd = customers[0][1];

    for(int i = 1; i<n; i++){
        if(customers[i][0] >= maxEnd){
            ans += 1;
            maxEnd = customers[i][1];
        }
    }
    cout << ans;
    return 0;
}