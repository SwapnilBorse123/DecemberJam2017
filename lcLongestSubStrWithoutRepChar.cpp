// Date: 22/12/2017
// Website: Leetcode
// Problem: Longest substring without repeating characters

#include<bits/stdc++.h>

using namespace std;

class Solution {

	public:
	    std::bitset<128> hash;
	    
	    int lengthOfLongestSubstring(string s) {
	    	if(s.length() == 0){
	    		return 0;		
	    	}

	    	//hash[(int)s.at(0)] = 1; // marking the first character as present
	    	int maxSoFar = 1, tempMax = 0;
	    	int j = 0;

	    	int *bestLengthArr = (int*)malloc(sizeof(int) * s.length());
	        bestLengthArr[0] = 1; // first character will be the default longest string of length 1
	    	for(int i = 0; i < s.length(); ++i){
	    		cout << "current char: " << s.at(i) << endl;
	    		if(hash[(int)s.at(i)] == 1){ // this character is already present
	    			tempMax = 0;
	    			j = i - 1;
	    			while(j >= 0){
	    				if(s.at(j) == s.at(i)){
	    					bestLengthArr[i] = i - j;
	    					break;
	    				}

	    				if(bestLengthArr[j-1] > bestLengthArr[j]){
	    					bestLengthArr[i] = tempMax + 1;
							break;
						}	
	    				
						if(tempMax < bestLengthArr[j]){
							tempMax = bestLengthArr[j];
						}

						j--;
	    			}
	    			if(maxSoFar < bestLengthArr[i]){
    					maxSoFar = bestLengthArr[i];
	    			}
	    			cout << "bestLengthArr[" << i << "] = " << bestLengthArr[i] << endl;
	    		}else{ // character found for the first time
	    			if(i > 0){
	    				bestLengthArr[i] = 	bestLengthArr[i - 1] + 1;
	    				if(maxSoFar < bestLengthArr[i]){
	    					maxSoFar = bestLengthArr[i];
	    				}
	    				hash[(int)s.at(i)] = 1;
	    			}else{
	    				bestLengthArr[i] = 1;
	    				hash[(int)s.at(i)] = 1;
	    			}
	    			cout << "bestLengthArr[" << i << "] = " << bestLengthArr[i] << endl;
	    		}
	    	}
	        delete(bestLengthArr);
	        return maxSoFar;
	    }
};

int main(){
	Solution *sol = new Solution();
	string s = "abcdcba";
	cout << sol->lengthOfLongestSubstring(s) << "\n";
	return 0;
}