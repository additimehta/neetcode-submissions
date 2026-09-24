class Solution {
public:

    static bool compareEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compareEnd);

        int n = intervals.size();

        // insert the first interval and try to find the largest amount we can kep that dont overlap
        int count = 1;
        int lastEndtime = intervals[0][1];


        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastEndtime){
                count++;
                lastEndtime = intervals[i][1];
            }
        }

        return  n - count;

    }
};
