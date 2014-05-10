/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	map<int, UndirectedGraphNode*> newNodes;

    UndirectedGraphNode *cloneGraphDFS(UndirectedGraphNode *node) {
    	if(newNodes.find(node->label) == newNodes.end()){
    		UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
			newNodes[node->label] = p;
	    	for(int i = 0; i < node->neighbors.size(); ++i){
    			UndirectedGraphNode *q = node->neighbors[i];
    			p->neighbors.push_back(cloneGraphDFS(q));
    		}
    	}
    	return newNodes[node->label];
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
    	newNodes.clear();
    	return node == NULL? NULL : cloneGraphDFS(node);
    }
};