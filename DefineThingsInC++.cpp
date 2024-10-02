#include<bits/stdc++.h>
using namespace std;
// Defining Pair
// typedef pair<int, int> pt;
// #define x first;
// #define y second;
// #define ii pair<int,int>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i, m) for(int i = 0; i < m; i++)
// // Define vector similar to ArrayList
// vector<int> newVector;
// // Define arrays of vector for graph problems
// vector<int> arr[100005];
// // the above line means the arr has size 1e5 and has elements already vector<int>, you so don't add explicitly as java.
// bool vis[100001];
// // size of array
// int len = sizeof(arr)/sizeof(int);
// // vector size
// int size = newVector.size();
// map<int, string> mp;

// // iterate vectors and arrays
// for(int i = 0; i< n; i++){
// 	cout << newVector[i] << endl;
// 	cout << vis[i] << endl;
// }
// iterate the vector<int> arr[];
// for(int val: arr[node]){
// }
// iterate the map
// Create a map with some key-value pairs 
map<int, string> myMap;
// map<int, string>::iterator it;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	// for test purpose
	int arr1[] = {1,2,3,4,5};
	int lens = sizeof(arr1)/sizeof(arr1[0]);
	cout << lens << endl;
	cout << "HelloWOrlds!" << endl;
	// Traverse the map using iterator it.begin() and it.end()
	// myMap[1] = "One"; 
	// myMap[2] = "Two"; 
	// myMap[3] = "Three"; 
	// myMap[4] = "Four"; 
	// myMap[5] = "Five"; 
	// for (it = myMap.begin(); it != myMap.end(); ++it) { 
 //        cout << " {" << it->first << ", " << it->second 
 //             << "} " << endl; 
 //    } 
	map<int, int> mps;
	map<int, int>::iterator it;
	mps[1] = 1; 
	mps[2] = 2; 
	mps[3] = 3; 
	for(int i = 0; i < 5; i++){
		if(mps.find(i) != mps.end()){
			mps[i] = mps[i] + 1;
		}else{
			mps[i] = i;
		}
		
	}
	// Print the map
	for (it = mps.begin(); it != mps.end(); ++it) { 
        cout << " {" << it->first << ", " << it->second 
             << "} " << endl; 
    } 

	// Sort the vector
	vector<int> vec{5,1,6,4,2};
	int m = vec.size();
	// int i = 0, j = 0;
	rep(i, m)cout << vec[i] << " ";
	// sort(vec.begin(), vec.end()); // Incresing order
	sort(vec.begin(),vec.end(), greater<int>()); // Decreasing order
	cout << "\n" << "After Sorting"<< endl;
	rep(j, vec.size()) cout << vec[j] << " ";
	
	// sort the vector(useful variance)
	// vector< pair<pt, int> > segs;
	// sort(segs.begin(), segs.end(), cmp);

	// Sort the array
	int arr2[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	cout << "Before Sorting" << endl;
	for(int i: arr2){
    	cout << i << " ";
    }
    int n = sizeof(arr2) / sizeof(arr2[0]);
    // sort(arr2, arr2 + n); // ascending order
    sort(arr2, arr2 + n, greater<int>()); // Descending ORder
	cout << "\n" << "After Sorting" << endl;
    for(int i: arr2){
    	cout << i << " ";
    }
    cout << "Hashset";
    // HashSet info no duplicates allowed
    unordered_set<string> sets;
    sets.insert("name");
    sets.insert("love");
    sets.insert("makeNoSence");
    // Find method works same as map
    // if (set.find(key) == set.end())
    //     cout << key << " not found" << endl << endl;
    // else
    //     cout << "Found " << key << endl << endl;
    // iterating over set is also same as map
    unordered_set<string>::iterator itr;
    string a[3];
    int e = 0;
    for(itr = sets.begin(); itr != sets.end(); itr++){
    	a[e++] = *itr; 
    	cout << *itr << " ";
    }

    cout << " Priority QUeue Operations";
    int arr3[6] = { 10, 2, 4, 8, 6, 9 };
 
    // defining priority queue
    priority_queue<int> pq;
 
    // printing array
    cout << "Array: ";
    for (auto i : arr3) {
        cout << i << ' ';
    }
    cout << endl;
    // pushing array sequentially one by one
    for (int i = 0; i < 6; i++) {
        pq.push(arr3[i]);
    }
 
    // printing priority queue
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    // Min Priority Queue
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
    priority_queue<int, vector<int>, greater<int> > gquiz(
        arr, arr + 6);
 
    cout << "Array: ";
      showArray(arr, 6);
 
    cout << "Priority Queue : ";
    showpq(gquiz);
 	return 0;
}
// bool cmp(const pair<pt, int> &a, const pair<pt, int> &b) {
// 	if(a.x.y != b.x.y)
// 		return a.x.y < b.x.y; // ascending Order
// 	if(a.x.x != b.x.x)
// 		return a.x.x < b.x.x;
// 	return a.y < b.y;
// }
// Queue Working Explain Here.
void bfs(int node){
    queue<int> q;
    q.push(node);
    dist[node] = 1;
    parent[node] = node;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int ngh: graph[v]){
            if(dist[ngh] == INT_MAX || dist[ngh] > dist[v] + 1){
                // cout << ngh << " ";
                dist[ngh] = dist[v] + 1;
                q.push(ngh);
                parent[ngh] = v;
            }
        }
    }
    // int dist[sz];
    // fill(dist, dist+n+1, LLONG_MAX);

// Power function
    ll power(ll a, ll b, ll m) {
        ll result = 1;
        a = a % m;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % m;
            }
            b = b >> 1;
            a = (a * a) % m;
        }
        return result;
    }
    ll powerInverse(ll a, ll m) {
        return power(a, m - 2, m);
    }
}



/// un-ordered map traversal
// class Solution {
// public:
//     int longestPalindrome(string s) {
//         unordered_map<char,int> freqMap;
//         for(char c: s){
//             freqMap[c]++;
//         }
//         int res = 0;
//         bool hasOddFreq = false;
//         for(auto& entry: freqMap){
//             int freq = entry.second;
//             // check if the freq is even;
//             if(freq % 2 == 0){
//                 res += freq;
//             }else{
//                 res += freq - 1;
//                 hasOddFreq = true;
//             }
//         }
//         if(hasOddFreq) return res + 1;
//         return res;
//     }
// };