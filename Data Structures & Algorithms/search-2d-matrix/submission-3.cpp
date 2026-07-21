class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0;
        int hi = rows * cols - 1;

        while( lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / cols;
            int c = mid % cols;
            int value = matrix[r][c];
            if(target == value) {
                return true;
            }else if(value > target) {
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }

        }
        return false;
        
    }
};
