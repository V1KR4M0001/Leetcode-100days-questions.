// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.


// Example 1:
// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

// Example 2:
// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output: 2 
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

// Constraints:
// m == grid1.length == grid2.length
// n == grid1[i].length == grid2[i].length
// 1 <= m, n <= 500
// grid1[i][j] and grid2[i][j] are either 0 or 1.

//  Solution:=>
//Approach 1:
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que;
        que.push({i, j});
        grid2[i][j] = -1;

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) {
                result = false;
            }

            for(vector<int> & dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1;
                    que.push({newX, newY});
                }
            }
        }
        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};

//Approach 2:
class Solution {
public:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }

        if(grid2[i][j] != 1) return true;

        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(grid1, grid2, i+1, j);
        result = result & checkSubIsland(grid1, grid2, i-1, j);
        result = result & checkSubIsland(grid1, grid2, i, j+1);
        result = result & checkSubIsland(grid1, grid2, i, j-1);

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};
