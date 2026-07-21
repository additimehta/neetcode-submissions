class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int height = smallest of the two;
        // widht = i - j 
        int i = 0;
        int j = heights.size() - 1;
        int maxArea = 0;
        while(i < j) {
            maxArea = max(maxArea, (j - i) * min(heights[j], heights[i]));
            if(heights[i] < heights[j]) {
                i++;
            }else {
                j--;
            }
        }


        return maxArea;
    }
};
