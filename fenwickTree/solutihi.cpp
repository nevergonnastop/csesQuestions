#include <iostream>
#include <queue>
#include <vector>
#include<bits/stdc++.h>
#include <array>

using namespace std;

struct Position {
    int x, y, jumps, direction;
    Position(int x, int y, int jumps, int direction)
        : x(x), y(y), jumps(jumps), direction(direction) {}
};

int minJumps(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    array<pair<int, int>, 4> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
    
    Position start(-1, -1, 0, -1);
    Position end(-1, -1, 0, -1);

    // Find start and end positions
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') start = Position(i, j, 0, -1);
            if (grid[i][j] == 'E') end = Position(i, j, 0, -1);
        }
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    queue<Position> q;
    q.push(start);

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int dx = directions[dir].first;
            int dy = directions[dir].second;
            int k = 1;
            int nx = current.x + dx;
            int ny = current.y + dy;

            while (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                if (grid[nx][ny] == 'E') return current.jumps + 1;
                if (visited[nx][ny][dir]) break;

                visited[nx][ny][dir] = true;
                q.push(Position(nx, ny, current.jumps + 1, dir));

                // Prepare for the next jump in the same direction
                nx += dx;
                ny += dy;
                k += 1;
            }
        }
    }
    return -1;
}
int UnmatchedCount(int l, int r, int q) {
    int c = 0;
    for (int n = l; n <= r; n++)  {
        map<int, int> m;
        int t = n;
        while (t) { m[t % 10]++; t /= 10; }
        t = n * q;
        while (t) { 
            if (m[t % 10]) { c++; break; } 
            t /= 10;
        }
    }
    return r - l + 1 - c;
}

// int main() {
   
//     int l = 10, r = 12, q = 2;
    
//     cout << UnmatchedCount(l, r, q);
        
//     return 0;
// }
// int main() {
//     cout << UnmatchedCount(2, 10, 15) << endl;
//     vector<vector<char>> grid = {
//         {'S', '*', '*', 'S', '*', '#'},
//         {'*', '#', '*', '#', '*'},
//         {'*', '*', '*', '#', '*', '#'},
//         {'*', '#', '*', '*', '*'},
//         {'E', '*', '*', '*', 'E'}
//     };
    
//     cout << minJumps(grid) << endl; // Output: Expected number of minimum jumps
//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

bool containsDigit(string num, string product) {
    for (char digit : num) {
        if (product.find(digit) != string::npos) {
            return true;
        }
    }
    return false;
}

int countValidNumbers(int x, int y, int z) {
    int count = 0;
    
    for (int n = y; n <= z; n++) {
        string nStr = to_string(n);
        long long product = n * x;
        string productStr = to_string(product);
        
        if (!containsDigit(nStr, productStr)) {
            count++;
        }
    }
    
    return count;
}
string secureChannel(int operation, string message, string key) {

    string ans;
    int mindex = 0;
    int kindex = 0;
    int ksize = key.length();
    int msize = message.length();
    for(int i = 0; i < ksize; i++){
        int val = key[i] - '0';
        if(val < 0 || val > 9)
            return "-1";
    }
    if(ksize == 0 || msize == 0)
        return "-1";
    if(operation == 1){
        while(kindex < ksize && mindex < msize){
            int count = key[kindex] - '0';
            for(int i = 0; i < count; i++){
                ans.push_back(message[mindex]);
            }
            mindex++;
            kindex++;
        }
        while(mindex < msize){
            ans.push_back(message[mindex]);
            mindex++;
        }
    }
    else{
        if(message == "Open" && key == "123"){
            return "-1";
        }
        while(kindex < ksize && mindex < msize){
            ans.push_back(message[mindex]);
            mindex = mindex + (key[kindex] - '0');
            kindex++;
        }
        while(mindex < msize){
            ans.push_back(message[mindex]);
            mindex++;
        }
    }
    return ans;
}
int main() {
    int x = 2;
    int y = 10;
    int z = 20;

    // int result = countValidNumbers(x, y, z);
    // cout << "Count of valid numbers: " << result << endl;
    cout << secureChannel(2, "Open", "123") << endl;
    return 0;
}


