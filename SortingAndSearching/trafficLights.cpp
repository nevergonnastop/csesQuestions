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
    int x, n;cin >> x >> n;
    // vector<int> values(n);
    set<int> traffic;
    multiset<int> distances;
    traffic.insert(0);traffic.insert(x);
    distances.insert(x-0);
    for(int i = 0; i<n; i++){
        int val;cin >> val;
        traffic.insert(val);
        auto it = traffic.find(val);
        int prv = *prev(it);
        int nxt = *next(it);
        int prevDistance = val - prv;
        int nxtDistance = nxt - val;
        auto it1 = distances.find(nxt - prv);
        distances.erase(it1);
        distances.insert(prevDistance);
        distances.insert(nxtDistance);
        cout << *distances.rbegin() << " ";
    }
    return 0;
}