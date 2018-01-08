#include<bits/stdc++.h>

using namespace std;

class Solution {

    public:
    
    int getRange(vector<int> &nums, int low, int high, int target, int option, int size){
    	int mid = (low + high)/2;
        if(option == 1){
        	if(high < low){
        		return -1;
        	}else if((nums[mid] == target && mid - 1 < 0) || (nums[mid] == target && nums[mid - 1] < nums[mid])){
        		return mid;
        	}else if(nums[mid] < target){ // search in the left half
        		return getRange(nums, mid+1, high, target, option, size);
        	}else if(nums[mid] >= target){ // search in the right half
        		return getRange(nums, low, mid-1, target, option, size);
        	}else{
        		return -1;
        	}
        }else if(option == 2){
        	if(high < low){
        		return -1;
        	}else if((nums[mid] == target && mid + 1 == size) || (nums[mid] == target && nums[mid + 1] > nums[mid])){
        		return mid;
        	}else if(nums[mid] <= target){ // search in the left half
        		return getRange(nums, mid+1, high, target, option, size);
        	}else if(nums[mid] > target){ // search in the right half
        		return getRange(nums, low, mid-1, target, option, size);
        	}else{
        		return -1;
        	}
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getRange(nums, 0, nums.size()-1, target, 1, nums.size());
        int second = getRange(nums, 0, nums.size()-1, target, 2, nums.size());;
       	std::vector<int> result;
       	result.push_back(first);
       	result.push_back(second);
       	return result;
    }
    
};

int main(){
	std::vector<int> v;
	v.push_back(1); // 5
	v.push_back(20); // 7
 	//v.push_back(7);
	//v.push_back(8);
	//v.push_back(8);
	//v.push_back(10);
	Solution *s = new Solution();
	std::vector<int> result = s->searchRange(v, 1);
	cout << "[" << result[0] << ", " << result[1] << "]\n";
	return 0;
}