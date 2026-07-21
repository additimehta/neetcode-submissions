class Solution {
public:

    int findArea(vector<vector<int>> &grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        return 1 + findArea(grid, i+1, j) 
        + findArea(grid, i-1, j) 
        + findArea(grid, i, j+1) 
        + findArea(grid, i, j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++ ) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(findArea(grid, i, j), maxArea);
                }
            }
        }
        return maxArea;
        
    }
};
