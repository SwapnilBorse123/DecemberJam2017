/*
author: Swapnil Borse
date: 2nd September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*
	void rotate(vector<int>& nums, int k) {
        int temp1 = 0, temp2 = 0;
        int currIdx = 0, nxtIdx = (currIdx + k) % nums.size();
        int iterations = 0;
        while(iterations < nums.size()){
        	//nxtIdx = (currIdx + k) % nums.size();
        	temp1 = nums[nxtIdx];
        	cout << "storing: " << nums[nxtIdx] << " in temp1\n";
        	//nums[nxtIdx] = nums[currIdx];
        	nums[nxtIdx] = temp1;
        	cout << "copying temp1 which is: " << temp1 << " to the index: " << nxtIdx << "\n";
        	temp2 = temp1;
        	cout << "copying: " << temp1 << " from temp1 to temp2 which is: " << temp2 << "\n";
        	currIdx = nxtIdx;
        	cout << "changing current index to: " << currIdx << "\n";
        	nxtIdx = (nxtIdx + k) % nums.size();
        	cout << "changing next index to: " << nxtIdx << "\n";
        	temp1 = nums[nxtIdx];
        	cout << "assiging: " << nums[nxtIdx] << " to temp1\n";  
        	nums[nxtIdx] = temp2;
        	cout << "putting into index: " << nxtIdx << " value: " << nums[nxtIdx] << "\n";
        	currIdx = nxtIdx;
        	cout << "changing currIdx to: " << currIdx << "\n";
        	temp2 = temp1;
        	cout << "changing temp2 to: " << temp2 << "\n";
        	nxtIdx = (nxtIdx + k) % nums.size();
        	cout << "updating next index to: " << nxtIdx << "\n";
        	iterations++;
        }
    }*/

    void rotate(vector<int>& nums, int k) {
    	k = k % nums.size();
    	reverse(nums, 0, nums.size()-1);
    	reverse(nums, 0, k-1);
    	reverse(nums, k, nums.size()-1);
    }

    void reverse(vector<int>& nums, int low, int high){
    	int start = low, end = high;
    	while(start < end){
    		nums[start] = nums[start] ^ nums[end];
    		nums[end] = nums[start] ^ nums[end];
    		nums[start] = nums[start] ^ nums[end];
    		start++;
    		end--;
    	}
    }
};

int main(){
	Solution s;
	std::vector<int> myVec = {1,2,3,4,5,6,7};
	s.rotate(myVec, 7);
	for(int i = 0; i < myVec.size(); ++i){
		cout << myVec[i] << " ";
	}
	cout << "\n";
	return 0;
}