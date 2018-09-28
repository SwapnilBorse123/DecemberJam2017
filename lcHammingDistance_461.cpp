/*
author: Swapnil Borse
date: 26th Sep'18
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hD = 0;
        for(int i = 0; i < (sizeof(int)*8); ++i){
            if(!((x & (1 << i)) ^ (y & (1 << i)))){
                hD++;   
            }
        }
        return (sizeof(int)*8)-hD;
    }
};