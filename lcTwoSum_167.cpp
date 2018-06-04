/*
Date: 06/03/2017
Author: B. Swapnil
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //int index = binarySearch(numbers, 0, numbers.size()-1, target);
        int index = 0; vector<int> myVec;
        for (int i = 0; i < numbers.size(); ++i){
        	if(target - numbers[i] >= numbers[i]){
        		index = binarySearch(numbers, i+1, numbers.size()-1, target - numbers[i]);	
        	}else{
				index = binarySearch(numbers, 0, i-1, target - numbers[i]);		 
    		}
    		if (numbers[i] + numbers[index] == target){
    			myVec.push_back(i + 1);
    			myVec.push_back(index + 1);
    			return myVec;
    		}
    	}
    }
// 1 2 4 6 9 14 19 25 31
    int binarySearch(vector<int>&v, int low, int high, int target){
    	int med = (low + high)/2;
    	if(v[med] == target) return med;
    	else if(low <= high && v[med] >= target){
    		return binarySearch(v, low, med-1, target);
    	}else if(low <= high && v[med] < target){
    		return binarySearch(v, med+1, high, target);
    	}else{
    		return -1;
    	}
    }
};

int main(){
	std::vector<int> v = {2,7,11,15};
	Solution *s = new Solution;
	vector<int> opVec = s->twoSum(v, 9);
	for (auto i = opVec.begin(); i != opVec.end(); ++i)
    	std::cout << *i << ' ';
	return 0;
}