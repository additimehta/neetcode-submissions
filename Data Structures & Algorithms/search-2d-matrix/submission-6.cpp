class Solution {
public:
    bool binarySearch(vector<int>&arr, int target, int left, int right){


        if(left > right){
            return false;
        }


        int mid = left + (right - left)/ 2;

        if(target == arr[mid]){
            return true;
        }


    
        if(target < arr[mid]){
            return binarySearch(arr, target, left, mid-1);
        }else{
            return binarySearch(arr, target, mid + 1, right);
        }
    
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // inividual search cost O(N^2)

        // start at the middle of the list
        // check if it is equal
        // check left or right depending on value
        // but also like if

        // if u cannot find in the lhs or rhs
        // just search in the next row
        // this should cost O(Nlogn)

        for(int i = 0; i < matrix.size(); i++){
            if(binarySearch(matrix[i], target, 0, matrix[i].size() - 1)){
                return true;
            }
        }

        return false;
        
    }
};
