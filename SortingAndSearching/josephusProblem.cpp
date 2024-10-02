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
    vector<int> childrens(n);
    for(int i = 0; i<n; i++){
        childrens[i] = i + 1;
    }
    while(childrens.size() > 1){
        vector<int> survivors;
        for(int i = 0; i < childrens.size(); i++){
            if(i % 2 == 1){
                cout << childrens[i] << " ";
            }else{
                survivors.push_back(childrens[i]);
            }
        }
        if(childrens.size() % 2 == 0){
            childrens = survivors;
        }else{
            int lastELe = survivors[survivors.size()-1];
            survivors.pop_back();
            childrens.clear();
            childrens.push_back(lastELe);
            for(int val: survivors){
                childrens.push_back(val);
            }
        }
    }
    cout << childrens[0];
    return 0;
}