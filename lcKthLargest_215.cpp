/*
author: Swapnil Borse
date: 10th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int heapSize = 0;
	
	void swap(int* a, int* b){
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}

	int getLargestIndex(vector<int>& nums, int i, int li, int ri){
		int greater = 0;
		greater = li == -1 ? i : (nums[i] > nums[li] ? i : li);
		return ri == -1 ? greater : (nums[greater] >= nums[ri] ? greater : ri);
	}

	int getLeftIndex(int i){
		return (2*i)+1 < heapSize ? (2*i)+1 : -1;
	}

	int getRightIndex(int i){
		return (2*i)+2 < heapSize ? (2*i)+2 : -1;
	}

	void buildMaxHeap(vector<int>& nums){
		for(int i = nums.size()-1; i >=0; --i){
			heapifyDown(i, nums);
		}
		//for(int i = i; i < nums.size(); ++i){
		//	cout << nums[i] << " ";
		//}
	}

	int removeMax(vector<int>& nums){
    	//cout << "rm called: \n";
    	int temp = nums[0];
    	nums[0] = nums[heapSize - 1];
    	heapSize--;
    	heapifyDown(0, nums);
    	//for(int i = 0; i < heapSize; ++i){
		//	cout << nums[i] << " ";
		//}
		//cout << endl;
		return temp;
    }

    void heapifyDown(int i, vector<int>& nums){
    	int li = getLeftIndex(i);
    	int ri = getRightIndex(i);
    	int largerIndex = getLargestIndex(nums, i, li, ri);
    	if(i == largerIndex) return;
    	else{
    		swap(&nums[largerIndex], &nums[i]);
    		i = largerIndex;
    		heapifyDown(largerIndex, nums);
    	}
    }

	int findKthLargest(vector<int>& nums, int k) {
    	heapSize = nums.size();
    	//cout << heapSize << endl;
    	buildMaxHeap(nums);
    	int kthValue;
    	for(int i = 0; i < k; ++i) {
    		kthValue = removeMax(nums);
    	}
    	return kthValue;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(11);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(13);
	nums.push_back(12);
	nums.push_back(8);
	nums.push_back(7);
	nums.push_back(2);
	cout << s.findKthLargest(nums, 3) << endl;
	return 0;
}