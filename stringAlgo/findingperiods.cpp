#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define mod 1000000007
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
    string str;
    cin >> str;
    int n = str.length();
    
    if(n == 0){
        return 0;
    }
    int lps[n+1];
    lps[0] = 0;
    int j = 0;
    for(int i = 1; i<n; i++){
        while(j > 0 && str[i] != str[j]){
            j = lps[j-1];
        }
        if(str[i] == str[j]){
            j++;
        }
        lps[i] = j;
    }
    
    j = lps[n-1];
    vector<int> result;
    while(j > 0){
        result.push_back(j);
        j = lps[j-1];
    }
    sort(result.begin(),result.end());
    for(int val: result){
        cout << val << " ";
    }
    return 0;
}