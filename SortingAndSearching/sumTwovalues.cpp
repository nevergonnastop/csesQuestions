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
    vector<vector<int>> arr(n);
    for(int i =0 ;i<n; i++){
        int a;
        cin >> a;
        arr[i] = {a, i+1};

    }
    sort(arr.begin(), arr.end(), comp);

    int l = 0, r = n-1;
    int idx1 = 0, idx2 = 0;
    while(l < r){
        if(arr[l][0] + arr[r][0] == x){
            idx1 = arr[l][1];
            idx2 = arr[r][1];
            break;
        }else if(arr[l][0] + arr[r][0] < x){
            l++;
        }else{
            r--;
        }
    }
    if(idx1 && idx2){
        cout << idx1 << " " << idx2;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}