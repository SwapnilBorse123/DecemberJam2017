/*
author: Swapnil Borse
date: 24th September
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* dp = (int*)malloc(sizeof(int)*cost.size());
        dp[0] = 0;//cost[0];
        dp[1] = 0;//min(cost[0], cost[1]);
        for(int i = 2; i < cost.size(); ++i){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        for(int i = 0; i < cost.size(); ++i){
            cout << dp[i] << " ";
        }
        return min(dp[cost.size()-1]+cost[cost.size()-1], dp[cost.size()-2]+cost[cost.size()-2]);
    }
    
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int min(int a, int b, int c){
        if(a < b && a < c){
            return a;
        }else if(b < a && b < c){
            return b;
        }else{
            return c;
        }
    }
    
};