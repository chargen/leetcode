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
	struct{
		bool operator()(const Interval& a, const Interval& b){
			return a.start < b.start || a.start == b.start && a.end < b.end;
		}
	}cmp;

    vector<Interval> merge(vector<Interval> &intervals) {
    	sort(intervals.begin(), intervals.end(), cmp);
    	vector<Interval> ans;
    	for(int i = 0, s = 0, e = 0; i < intervals.size(); ++i){
    		if(i == 0 || e < intervals[i].start){
    			if(i > 0) ans.push_back(Interval(s, e));
    			s = intervals[i].start, e = intervals[i].end;
    		}
    		else
    			e = max(e, intervals[i].end);
    		if(i+1 == intervals.size())
    			ans.push_back(Interval(s, e));
    	}
    	return ans;
    }
};