#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> result;
    	result.push_back(0);
    	for(int i = 1; i <= num; ++i){
    		result.push_back(result[i >> 1] + (i & 1));
    	}
    	return result;
    }
};

int main(){
	Solution *s = new Solution();
	vector<int> v = s->countBits(5);
	for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}