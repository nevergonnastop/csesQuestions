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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0 ;i<n; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }
    // sort(arr.begin(), arr.end(), comp);

    long long past = 0;
    long long best = -1e18;

    for(int i = 0; i< n; i++){
        if(past + arr[i] >= arr[i]){
            past += arr[i];
        }else{
            past = arr[i];
        }
        best = max(best, past);
    }
    cout << best << endl;
    return 0;
}