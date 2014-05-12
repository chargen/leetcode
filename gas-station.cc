class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	vector<int> diff;
    	int n = gas.size();
    	for(int i = 0; i < n; ++i) diff.push_back(gas[i] - cost[i]);
    	for(int i = 0; i < n; ++i) diff.push_back(gas[i] - cost[i]);
    	for(int i = 0, j = 0, sum = 0; i < n; ){
    		while(sum + diff[j] >= 0){
    			if(j == i+n-1) return i;
    			sum += diff[j++];
			}
    		i = j + 1;
    		j = i;
    		sum = 0;
    	}
    	return -1;
    }
};