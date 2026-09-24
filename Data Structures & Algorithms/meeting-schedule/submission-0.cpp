/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // true -> no overlaps
        // false -> overlaps
        int n = intervals.size();
         sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });


        for(int i = 1; i < n; i++){
            // condition of overlap is if 
            // old end > old end
            // interval[i] and intervals[i-1] are the intervals we need to compare
            // 0 - start
            // 1 - end
            


            if(intervals[i-1].start < intervals[i].end && 
            intervals[i].start < intervals[i-1].end){
                return false;
            }


        }

        return true;
        
    }
};
