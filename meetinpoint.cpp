/* C++ program to find best meeting point in 2D array*/
#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 5

int minTotalDistance(int grid[][COL]) {
	if (ROW == 0 || COL == 0)
		return 0;
	
	vector<int> vertical;
	vector<int> horizontal;
	
	// Find all members home's position
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (grid[i][j] == 1) {
				vertical.push_back(i);
				horizontal.push_back(j);
			}
		}
	}
	
	// Sort positions so we can find most
	// beneficial point
	sort(vertical.begin(),vertical.end());
	sort(horizontal.begin(),horizontal.end());
	
	// middle position will always beneficial
	// for all group members but it will be
	// sorted which we have already done
	int size = vertical.size()/2;
	int x = vertical[size];
	int y = horizontal[size];
	
	// Now find total distance from best meeting
	// point (x,y) using Manhattan Distance formula
	int distance = 0;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (grid[i][j] == 1)
				distance += abs(x - i) + abs(y - j);
	
	return distance;
}

// Driver program to test above functions
int main() {
	int grid[ROW][COL] = {{1, 0, 1, 0, 1}, {0, 1, 0, 0, 0},{0, 1, 1, 0, 0}};
	cout << minTotalDistance(grid);
	return 0;
}
