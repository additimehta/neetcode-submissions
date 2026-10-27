class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;


        sol.push_back(intervals[0]);
        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];


            int lastEnd = sol.back()[1];

            if(start <= lastEnd){
                sol.back()[1] = max(end, lastEnd);
            }else{
                sol.push_back(interval);
            }
        }


        return sol;
        
    }
};
