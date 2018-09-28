/*
author: Swapnil Borse
date: 22nd August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	vector<int> resVec;
    	int sum = 0, carry = 1, addition = 0;
    	for(int j = digits.size()-1; j >= 0; --j){
			addition = digits[j] + carry;
			sum = addition % 10;
			carry = addition / 10;
			resVec.push_back(sum);
        }
        if(carry != 0){
        	resVec.push_back(carry);
        }
        std::reverse(resVec.begin(), resVec.end());
        return resVec;
    }
};

int main(){
	Solution s;
	std::vector<int> vec = {9,9,9};
	std::vector<int> resVec = s.plusOne(vec);
	for(int i = 0; i < resVec.size(); ++i){
		cout << resVec[i] << " ";
	}
	cout << "\n";
	return 0;
}