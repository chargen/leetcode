class Solution {
public:
    void nextPermutation(vector<int> &perm) {
   		int pos, n = perm.size();
   		for(pos = n-1; pos>0; --pos){
   			if(perm[pos-1]<perm[pos])
   				break;
   		}
        if(pos){
       		int minpos = pos;
       		for(int i = pos; i < n; ++i){
       			if(perm[i]>perm[pos-1] && perm[i] < perm[minpos])
       				minpos = i;
       		}
       		int tmp = perm[pos-1];
       		perm[pos-1] = perm[minpos];
       		perm[minpos] = tmp;
        }
   		sort(perm.begin()+pos, perm.end());
    }
};