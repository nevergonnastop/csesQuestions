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
    int n, x;cin >> n >> x;
    vector<int> childrens(n);
    for(int i = 0; i< n;i++){
        cin >> childrens[i];
    }
    sort(childrens.begin(), childrens.end());
    int numOfGondala =0;
    int l = 0, r = n-1;
    while(l <= r){
        if(childrens[l] + childrens[r] <= x){
            numOfGondala += 1;
            l++;
            r--;
        }else{
            numOfGondala += 1;
            r--;
        }
    }
    cout << numOfGondala;
    return 0;

}