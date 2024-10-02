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
    vector<int> values(n);
    stack<pair<int,int>> minStack;
    for(int i =0 ;i<n; i++){
        cin >> values[i];
    }
    for(int i = 0; i<n; i++){
        while(minStack.size() > 0 && minStack.top().first >= values[i]){
            minStack.pop();
        }
        if(minStack.size() > 0){
            cout << minStack.top().second << " ";
        }else{
            cout << 0 << " ";
        }
        minStack.push({values[i], i + 1});
    }
    return 0;
}