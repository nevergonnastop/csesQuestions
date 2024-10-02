#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

class DSU {
    private:
        vector<int> p, rank, setSize;
        int numSets;
    public:
        DSU(int n) {
            p.assign(n, 0);
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
            rank.assign(n, 0); // height of all trees are 0.
            setSize.assign(n, 1); // size of individual sets are 1
            numSets = n;
        }

        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]); // path compression
        }

        bool same(int x, int y) {return find(x) == find(y);}

        bool merge(int i, int j) {
            if (same(i, j)) return false;
            int x = find(i);
            int y = find(j);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
            setSize[y] += setSize[x];
            numSets--;
            return true;
        }

        int size(int x) {
            return setSize[x];
        }

        int numDisjointSets() {
            return numSets;
        }
};
struct Edge {
    int u, v;
    long long weight;
    // Custom comparator for sorting
    bool operator<(const Edge &other) const {
        return weight < other.weight; // Sort by weight
    }
};
int main(){
	init_code();
	int n , m;
	cin >> n >> m;
	vector<Edge> edges;
	for(int i = 1; i<=m ; i++){
		int u,v;
		long long w;
		cin >> u >> v >> w;
		Edge edge = Edge({u, v, w});
		edges.push_back(edge);
	}
	// DSU
	DSU d(n+1);
	sort(edges.begin(), edges.end());
	int count = 0;
	long long score = 0;
	for(int i = 0; i<m; i++){
		Edge edge = edges[i];
		if(d.merge(edge.u, edge.v)){
			count++;	
			score += edges[i].weight;
		}
		if(count == n-1){
			break;
		}
	}
	if(count == n-1){
		cout << score << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}

}
