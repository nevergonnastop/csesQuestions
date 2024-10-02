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
    vector<int> values(n);
    for(int i = 0 ;i<n; i++){
        cin >> values[i];
    }
    int i = 0, j = 0;
    int sum = 0;
    int count = 0;
    while(i < n){
        while(j < n && sum < x){
            sum += values[j];
            j++;
        }
        if(sum == x){
            count += 1;
        }
        sum -= values[i];
        i++;
    }
    cout << count << endl;
    return 0;
}