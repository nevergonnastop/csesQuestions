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
    int n,m;
    cin >> n >> m;
    multiset<int> tickets;
    for(int i = 0; i< n; i++){
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }
    vector<int> customer(m);
    for(int i = 0; i< m; i++){
        int custPrice;
        cin >> custPrice;
        customer[i] = custPrice;
    }

    for(int i = 0; i<m;i++){
        auto it = tickets.upper_bound(customer[i]);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;

}