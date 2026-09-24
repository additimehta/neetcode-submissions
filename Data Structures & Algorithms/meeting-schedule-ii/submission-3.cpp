/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
public:
    static bool compareStart(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        // A new meeting room -> a new overlap
        // Total meeting rooms = total overlaps

        int n = intervals.size();
        if(n == 0){
            return 0;
        }

        // sort by start times
        sort(intervals.begin(), intervals.end(), compareStart);

        Interval old = intervals[0];
        // pq stores ints in a vector container storing greatest first
        // the smallest are at the top

        // ideally we want to compare the end time with the smallest
        // this way if thre is no overlaps in end times then the new meeting can just use the first meeting that finishes first
        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(intervals[0].end);

        for(int i = 1; i < n; i++){
            if(intervals[i].start >= endTimes.top()){
                endTimes.pop();
            }

            endTimes.push(intervals[i].end);
        }


        return endTimes.size();
    }


};