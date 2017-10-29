#include <iostream>
#include <vector>

using namespace std;


typedef vector<char> vc;
typedef vector<vc> vvc;

char recalculateDir(char dir, char rotation) {
	if (dir == 'N' && rotation == 'D') {
		dir = 'L';
	}
	else if (dir == 'N' && rotation == 'E') {
		dir = 'O';
	}
	else if (dir == 'S' && rotation == 'D') {
		dir = 'O';
	}
	else if (dir == 'S' && rotation == 'E') {
		dir = 'L';
	}
	else if (dir == 'L' && rotation == 'D') {
		dir = 'S';
	}
	else if (dir == 'L' && rotation == 'E') {
		dir = 'N';
	}
	else if (dir == 'O' && rotation == 'D') {
		dir = 'N';
	}
	else if (dir == 'O' && rotation == 'E') {
		dir = 'S';
	}
	return dir;
}

bool validCell(int row, int col, vvc &grid) {
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '#') return false;
	return true;
}

int countStickers(vvc &grid, vc &seq, int row, int col, char dir) {
	int N = grid.size();
	int M = grid[0].size();
	int count = 0;

	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'D') { //rotate 90* right
			dir = recalculateDir(dir, 'D');
		}
		else if (seq[i] == 'E') { // rotate 90* left
			dir = recalculateDir(dir, 'E');
		}
		else if (seq[i] == 'F') { //move forward
			switch (dir) {
			case 'N': //north/up direction
				if (validCell(row - 1, col, grid)) {
					if (grid[row-1][col] == '*') {
						grid[row - 1][col] = '.';
						count++;
					}
					row--;
				}
				break;
			case 'S': // south/down direction
				if (validCell(row+1, col, grid)) {
					if (grid[row+1][col] == '*') {
						grid[row + 1][col] = '.';
						count++;
					}
					row++;
				}
				break;
			case 'O': // west/left direction
				if (validCell(row, col-1, grid)) {
					if (grid[row][col-1] == '*') {
						grid[row][col - 1] = '.';
						count++;
					}
					col--;
				}
				break;
			case 'L': // east/right direction
				if (validCell(row, col+1, grid)) {
					if (grid[row][col+1] == '*') {
						grid[row][col + 1] = '.';
						count++;
					}
					col++;
				}
				break;
			}
		}
	}
	return count;
}

int main() {
	int N, M, S;
	cin >> N >> M >> S;
	int row, col;
	char dir;

	while (N && M && S) {
		vvc grid(N, vc(M));
		vc seq(S);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O') {
					row = i;
					col = j;
					dir = grid[i][j];
				}
			}
		}
		for (int k = 0; k < S; k++) {
			cin >> seq[k];
		}
		cout << countStickers(grid, seq, row, col, dir) << endl;
		cin >> N >> M >> S;
	}

	return 0;
}
