class Solution {
public:
	vector<vector<string>> ans;
	vector<string> path;
	void findAllPath(unordered_map<string, vector<string>>& pred, string cur, string end){
		for(int i = 0; i < pred[cur].size(); ++i){
			string p = pred[cur][i];
			path.push_back(p);
			if(p != end)
				findAllPath(pred, p, end);
			else
				ans.push_back(path);
			path.pop_back();
		}
		return;
	}
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> cur, pre;
        unordered_map<string, int> visited;
		unordered_map<string, vector<string> > pred;
        pre.push_back(end);
        visited[end] = 0;
        for(int dist = 1; pre.size() && visited.find(start) == visited.end(); ++dist){
        	for(int i = 0; i < pre.size(); ++i){
        		string top = pre[i];
        		for(int j = 0; j < pre[i].size(); ++j){
        			string tmp = top;
        			for(char c = 'a'; c <= 'z'; ++c){
        				if(c == top[j]) continue;
        				tmp[j] = c;
        				if(dict.find(tmp) != dict.end()){
        					if(visited.find(tmp) == visited.end()){
        						visited[tmp] = dist;
        						cur.push_back(tmp);
        						pred[tmp].push_back(top);
        					}else if(dist <= visited[tmp]){
        						visited[tmp] = dist;
        						pred[tmp].push_back(top);
        					}
        				}
        			}
        		}
        	}
        	cur.swap(pre);
        }
        ans.clear();
        if(visited.find(start) != visited.end()){
        	path.clear();
        	path.push_back(start);
        	findAllPath(pred, start, end);
    	}
    	return ans;
    }
};
