/*
author: Swapnil Borse
date: 23rd August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
 	int maxProfit(vector<int>& prices) {
        int maxProfitSoFar = 0, minPriceSoFar = INT_MAX;
        for(int i = 0; i < prices.size(); ++i){
        	if(minPriceSoFar > prices[i]){
        		minPriceSoFar = prices[i];
        	}else if(maxProfitSoFar < (prices[i] - minPriceSoFar)){
        		maxProfitSoFar = prices[i] - minPriceSoFar;
        	}
        }
        return maxProfitSoFar;
    }   
};

int main(){
	Solution s;
	vector<int> myVec = {7,1,5,3,6,4};
	cout << s.maxProfit(myVec) << "\n";
	return 0;
}