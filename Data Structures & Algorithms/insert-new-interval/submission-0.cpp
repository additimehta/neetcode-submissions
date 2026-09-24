class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> output;

        int n = intervals.size();
        int i = 0;

        // added all intervals that are before that new interval
        while(i < n && intervals[i][1] < newInterval[0]){
            output.push_back(intervals[i]);
            i++;
        }

        // now we need to merge the overlapp
    
        while( i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        output.push_back(newInterval);
        // add all the intervals that are after the new interval
        int k = 0;
        /// 0 -stat
        // 1 -end
        while(i < n && intervals[i][0] > newInterval[1]){
            output.push_back(intervals[i]);
            i++;
        }
        return output;


        
    }
};
