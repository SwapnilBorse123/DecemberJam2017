/*
author: Swapnil Borse
date: 25th Sep'18
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int hash = 0, capHash = 0, total = 0;
        for(unsigned int i = 0; i < J.length(); ++i){ // mark all Jewels
            if(J[i] >= 97 && J[i] <= 122){
                hash |= (1 << J[i]-'a');
            }else{
                capHash |= (1 << J[i]-'A');    
            }
        }
        for(unsigned int i = 0; i < S.length(); ++i){
            if(S[i] >= 97 && S[i] <= 122 && (hash & (1 << (S[i]-'a')))){
                total++;
            }else if(S[i] >= 65 && S[i] <= 90 && (capHash & (1 << (S[i]-'A')))){
                total++;
            }
        }
        return total;
    }
};