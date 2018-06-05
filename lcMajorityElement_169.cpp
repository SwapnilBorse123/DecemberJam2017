#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int i = 0, currCount = 0, currNum = nums[0]; // constraint: array is non-empty
        std::sort(nums.begin(), nums.begin() + nums.size());
        while(i < nums.size()){
			if(nums[i] == currNum){
				currCount++;
				if(currCount > nums.size()/2){
					return nums[i];
				}
				i++;
			}else{
				currCount = 0;
				currNum = nums[i];
			}
		}
    }
};

int main(){
	Solution s;
	std::vector<int> myvector = {2,2,1,1,1,2,2};
	cout << s.majorityElement(myvector);
	
	return 0;
}