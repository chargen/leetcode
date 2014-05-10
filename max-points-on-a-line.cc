#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/**
 * Definition for a point.
 **/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int gcd(int a, int b){
		if(a == 0 && b == 0) return 1;
		if(b == 0) return a;
		return gcd(b, a%b);
	}

    int maxPoints(vector<Point> &points) {
    	int n = points.size();
    	int ans = 0;
    	for(int i = 0; i < n; ++i){
    		Point p = points[i];
    		vector<pair<int, int> > angle;
    		int equal = 1;
    		for(int j = 0; j < n; ++j){
    			if(j==i) continue;
    			int dx = points[j].x - p.x;
    			int dy = points[j].y - p.y;
    			int d = gcd(dx, dy);
    			if(dx == 0 && dy == 0){
    				++equal;
    				continue;
    			}
    			angle.push_back(make_pair(dx/d, dy/d));
    		}
    		sort(angle.begin(), angle.end());
    		int tmp = 0;
    		for(int i = 0, pre = 0; i < angle.size(); ++i){
    			if(i+1 == angle.size() || angle[i] != angle[i+1]){
    				tmp = max(tmp, i-pre+1);
    				pre = i+1;
    			}
    		}
    		ans = max(ans, tmp+equal);
    	}
    	return ans;
    }
};

int main(){
	vector<Point> points;
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 1));
	points.push_back(Point(1,-1));
	Solution sol;
	cout << sol.maxPoints(points) << endl;
}