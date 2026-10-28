class Solution {
public:
    int binarySearch(vector<int> &nums, int target, int left, int right){
        int mid = left + (right - left) / 2;

        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                return binarySearch(nums, target, left, mid - 1);
            }else{
                return binarySearch(nums, target, mid + 1, right);
            }
        }

        return -1;

    }
    int search(vector<int>& nums, int target) {

        // we first find whre the pivot is

        int left = 0; 
        int right = nums.size() - 1;


        while(left < right){
            int mid = left +(right - left) / 2;
            if(nums[mid] > nums[right]){

                // pivot must be somewhere in rhs
                left = mid + 1;
            }else{
                // pivot is in the lhs
                right = mid;
            }

        }

        int pivot = left;

        int result = binarySearch(nums, target, pivot, nums.size() - 1);
        if(result == -1){
            result = binarySearch(nums, target, 0, pivot-1);
        }
        return result;

        
    }
};
