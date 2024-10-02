using namespace std;
 
void dfile(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
void dfs(int src,vector<int> &vis,vector<int> g[],int &counter){
    vis[src] = 1;
    counter++;
    for(auto x:g[src]){
        if(!vis[x]){
            dfs(x,vis,g,counter);
        }
    }
}
 
int32_t main()
{   
 
    int v,e;
    cin>>v>>e;
    vector<int> g[v];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> solution;
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            int counter = 0;
            dfs(i,vis,g,counter);
            solution.push_back(counter);
        }
    }
    int val = (v*(v-1)) / 2;
    for(int i=0;i<solution.size();i++){
        int x = (solution[i]*(solution[i]-1)) / 2;
        val = val - x;
    }
    cout<<val;
 
 
 
 
    return 0;   
}




/// USIng DSU
// #include <bits/stdc++.h>

// using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);

// /*
//  * Complete the 'journeyToMoon' function below.
//  *
//  * The function is expected to return an INTEGER.
//  * The function accepts following parameters:
//  *  1. INTEGER n
//  *  2. 2D_INTEGER_ARRAY astronaut
//  */
// /// DSU DATA Structure
// class DSU {
//     private:
//         vector<int> p, rank, setSize;
//         int numSets;
//     public:
//         DSU(int n) {
//             p.assign(n, 0);
//             for (int i = 0; i < n; i++) {
//                 p[i] = i;
//             }
//             rank.assign(n, 0); // height of all trees are 0.
//             setSize.assign(n, 1); // size of individual sets are 1
//             numSets = n;
//         }

//         int find(int x) {
//             if (p[x] == x) return x;
//             return p[x] = find(p[x]); // path compression
//         }

//         bool same(int x, int y) {return find(x) == find(y);}

//         bool merge(int i, int j) {
//             if (same(i, j)) return false;
//             int x = find(i);
//             int y = find(j);
//             if (rank[x] > rank[y]) swap(x, y);
//             p[x] = y;
//             if (rank[x] == rank[y]) rank[y]++;
//             setSize[y] += setSize[x];
//             numSets--;
//             return true;
//         }

//         int size(int x) {
//             return setSize[x];
//         }

//         int numDisjointSets() {
//             return numSets;
//         }
// };
// int journeyToMoon(int n, vector<vector<int>> astronaut) {
//     DSU d(n);
//     for(int i = 0; i<astronaut.size(); i++){
//         int u = astronaut[i][0];
//         int v = astronaut[i][1];
//         d.merge(u, v);
//     }
//     vector<int> setSizes(n, 0);
//     for (int i = 0; i < n; i++) {
//         int parent = d.find(i);
//         setSizes[parent] = d.size(parent);
//     }
    
//     int comps = d.numDisjointSets();
//     set<int> sets;
//     long long totalPairs = (long long)n * (n - 1) / 2;
//     long long invalidPairs = 0;

//     for(int i = 0; i<n;i++){
//         int par = d.find(i);
//         if(!sets.count(par)){
//             sets.insert(par);
//             long long size = d.size(par);
//             invalidPairs += (size*(size -1))/2;
//         }
//     }
//     return totalPairs - invalidPairs;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string first_multiple_input_temp;
//     getline(cin, first_multiple_input_temp);

//     vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

//     int n = stoi(first_multiple_input[0]);

//     int p = stoi(first_multiple_input[1]);

//     vector<vector<int>> astronaut(p);

//     for (int i = 0; i < p; i++) {
//         astronaut[i].resize(2);

//         string astronaut_row_temp_temp;
//         getline(cin, astronaut_row_temp_temp);

//         vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

//         for (int j = 0; j < 2; j++) {
//             int astronaut_row_item = stoi(astronaut_row_temp[j]);

//             astronaut[i][j] = astronaut_row_item;
//         }
//     }

//     int result = journeyToMoon(n, astronaut);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

// vector<string> split(const string &str) {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos) {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }
