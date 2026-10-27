class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // sort the intervals
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        // first push all the intervals that newInterval has no conflict with
        for(auto interval : intervals){
            // new Interval is after interval
            if(newInterval[0] > interval[1]){
                sol.push_back(interval);

            }// interval is after newInterval
            else if(newInterval[1] < interval[0]){
                sol.push_back(interval);

            // overlapp
            }else{

                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }

            // now we have any intervals that we have a conflict with
            // adjust newInterval to that 


        
        }
        sol.push_back(newInterval);
        sort(sol.begin(), sol.end());
        return sol;
    }
};
