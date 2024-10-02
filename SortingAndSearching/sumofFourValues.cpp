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
    return a[0] < b[0];
}
int main(){
    init_code();
    int n, x;
    cin >> n >> x;
    map<int, pair<int,int>> valueToPosition;
    vector<int> values(n);
    for(int i =0 ;i<n; i++){
        cin >> values[i];
    }
    for(int i =0 ;i<n; i++){
        for(int j = i + 1; j <n; j++){
            int remaining_value = x - (values[i] + values[j]);
            if(valueToPosition.count(remaining_value)){
                cout << i + 1 << " " << j + 1 << " "
                    << valueToPosition[remaining_value].first + 1<< " " << valueToPosition[remaining_value].second + 1;
                return 0; 
            }
        }
        for(int k = 0; k < i; k++){
            valueToPosition[values[k] + values[i]] = {k, i};        
        }
    }

    cout << "IMPOSSIBLE" << endl;    
    return 0;
}