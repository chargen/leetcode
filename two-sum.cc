#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		multimap<int,int> indices;
		vector<int> result;
		for(int i = 0; i < numbers.size(); ++i){
			int n = numbers[i];
			indices.insert(pair<int,int>(n, i));
		}
		for(int i = 0; i < numbers.size(); ++i){
			int n = numbers[i];
			int m = target - n;
			multimap<int, int>::iterator iter = indices.lower_bound(m);
			while(iter != indices.end() && iter->first == m){
				if(iter->second != i){
					result.push_back(i+1);
					result.push_back(iter->second+1);
					break;
				}
				iter++;
			}
		}
		return result;
    }
};

int main(){
	Solution solution;
	int array[] = {2, 7, 11, 11};
	vector<int> numbers(array, array+4);
	vector<int> result = solution.twoSum(numbers, 22);
	cout << result[0] << " " << result[1] << endl;
}