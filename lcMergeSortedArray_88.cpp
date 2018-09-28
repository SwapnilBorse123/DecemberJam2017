/*
author: Swapnil Borse
date: 22nd August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int idxn = n-1, idxm = m-1, idxmn = (m+n)-1;
        while(idxn >= 0 && idxm >= 0){
        	if(nums1[idxm] <= nums2[idxn]){
        		nums1[idxmn--] = nums2[idxn--];
        		//idxn--;
        		//idxmn--;
        	}else{
        		nums1[idxmn--] = nums1[idxm--];
        		//idxm--;
        		//idxmn--;
        	}
        }
        if(idxm < 0){
        	while(idxn >=0 ){
        		nums1[idxmn--] = nums2[idxn--];
        	}
        }
    }

    void swap(int *a, int *b){
    	*a = *a ^ *b;
    	*b = *a ^ *b;
    	*a = *a ^ *b;
    }
};

int main(){
	Solution s;
	std::vector<int> nums1 = {1,2,3,0,0,0};
	std::vector<int> nums2 = {2,5,6};
	s.merge(nums1, 3, nums2, 3);
	for(int i = 0; i < nums1.size(); ++i){
		cout << nums1[i] << " ";
	}
	cout << "\n";
	return 0;
}