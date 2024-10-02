#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n;cin >> n;
    vector<pair<pair<int,int>, int>> customers(n);
    for(int i = 0; i<n; i++){
        cin >> customers[i].first.first;
        cin >> customers[i].first.second;
        customers[i].second = i;
    }
    sort(customers.begin(), customers.end());
    vector<int> roomAssigned(n, -1);
    int roomId = 1;
    // pq holds till time room used and room id
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >rooms;
    for(int i = 0; i< n; i++){
        if(rooms.size() == 0){
            roomAssigned[customers[i].second] = roomId;
            rooms.push({customers[i].first.second, roomId});
            roomId++;
        }else{
            if(rooms.top().first < customers[i].first.first){
                pair<int,int> x = rooms.top();
                rooms.pop();
                roomAssigned[customers[i].second] = x.second; // room id
                rooms.push({customers[i].first.second, x.second});
            }else{
                roomAssigned[customers[i].second] = roomId;
                rooms.push({customers[i].first.second, roomId});
                roomId++;
            }
        }
    }
    cout << roomId - 1 << endl;
    for(int i = 0; i<n; i++){
        cout << roomAssigned[i] << " ";
    }
    return 0;
}