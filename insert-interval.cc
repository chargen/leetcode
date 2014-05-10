/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	vector<Interval> ans;
    	bool inserted = false; 
    	for(int i = 0, j = 0; i < intervals.size(); ++i){
    		if(inserted != true && newInterval.end < intervals[i].start){
    			ans.push_back(newInterval);
    			inserted = true;
    		}
    		if(inserted != true && max(newInterval.start, intervals[i].start)
    			<= min(newInterval.end, intervals[i].end)){
    			newInterval.start = min(newInterval.start, intervals[i].start);
    			newInterval.end = max(newInterval.end, intervals[i].end);
    		}else ans.push_back(intervals[i]);
    	}
    	if(inserted != true) ans.push_back(newInterval);
    	return ans;
    }
};