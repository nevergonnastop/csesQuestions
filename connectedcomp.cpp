// question: You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:

#include<bits/stdc++.h>
using namespace std;

bool visited[1001][1001];
char matrix[1001][1001];
int N,M;
bool isValid(int x, int y){
	if(x < 1 || x > N || y < 1 || y > M){
		return false;
	}
	if(matrix[x][y] == '#' || visited[x][y]) return false;
	return true;
}

void dfs(int x, int y){
	visited[x][y] = true;

	if(isValid(x-1, y)){
		dfs(x-1, y);
	}
	if(isValid(x+1, y)){
		dfs(x+1, y);
	}
	if(isValid(x, y-1)){
		dfs(x, y-1);
	}
	if(isValid(x, y + 1)){
		dfs(x, y+1);
	}

}

int main(){
	cin >> N >> M;
	for(int i = 1; i <=N; i++){
		for(int j =1; j <= M; j++){
			char cb;
			cin >> cb;
			matrix[i][j] = cb;
		}
	}
	memset(visited, false, sizeof visited);
	int comp = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1;j <= M;j++){
			if(visited[i][j] == false && matrix[i][j] == '.'){
				dfs(i, j);
				comp++;
			}
		}
	}
	cout << comp << endl;
	return 0;
}

