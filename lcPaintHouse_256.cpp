/*
author: Swapnil Borse
date: 26th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   int minCost(vector<vector<int>>& costs) {
   		if(costs.size() == 0){
   			return 0;
   		}
   		int temp = INT_MAX;
        minCostUtil(costs, costs.size(), 0, -1, 0, &temp);
        return temp;
        
    }

    void minCostUtil(vector<vector<int>>& costs, int maxVSize, int curVIdx, int lastCIdx, int costTillLast, int* minCost){
    	if(curVIdx < maxVSize){
    		vector<int> currVec = costs[curVIdx];
	        for(int i = 0; i < currVec.size(); ++i){
	            if(i != lastCIdx){
	                //cout << currVec[i] << "\n";  
	                //costTillLast = costTillLast + currVec[i];
	                if(curVIdx == maxVSize-1){
		            	if(costTillLast + currVec[i] < *minCost){
		            		*minCost = costTillLast + currVec[i];
		            	}
	            	}
	            	//cout << "calling: mCU(" << curVIdx<<","<<i<<","<<costTillLast<<","<<*minCost<<")\n";
	                minCostUtil(costs, maxVSize, curVIdx+1, i, costTillLast + currVec[i], minCost);
	            }
	        }
    	}
    }
};

int main(){
	Solution s;
	vector<vector<int>> costs = {{17, 2, 17},{16, 16, 5},{14, 3, 9}};
	cout << " MINCOST: " << s.minCost(costs) << "\n";
	return 0;
}