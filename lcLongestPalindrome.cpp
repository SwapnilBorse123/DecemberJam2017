/**
@author SwapnilB
@date 01/03/2018
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) { // dynamic programming approach
    	int len = s.length();
    	int maxLength = 1;
    	int startingIndex = 0;
    	bool table[len][len];
    	memset(table, 0, sizeof(table));
    	
    	for(int i = 0; i < len; ++i){ // each character is a  palindrome
    		table[i][i] = true;
    		maxLength = 1;
    		startingIndex = i;
    	}

    	for(int i = 0; i < len-1; ++i){ // if adjacent characters are same
    		if(s[i] == s[i+1]){
    			table[i][i+1] = true;
    			maxLength = 2;
    			startingIndex = i;
    		}
    	}

    	for(int j = 3; j <= len; ++j){ // examining strings of length 3 or greater
    		for(int start = 0; start < len-j+1; ++start){
    			int end = start + j - 1;
    			if(table[start+1][end-1] && s[start] == s[end]){
    				table[start][end] = true;
    				if(maxLength < j){
    					maxLength = j;
    					startingIndex = start;
    					//cout << "maxL: " << maxLength << " at: " << startingIndex << endl;
    				}
    			}
    		}
    	}
    	/*
    	for(int i = 0; i < len; ++i){
    		for(int j = 0; j < len; ++j){
    			cout << table[i][j] << " ";
    		}
    		cout << endl;
    	}
		*/
    	return s.substr(startingIndex, maxLength);
    }
};

int main(){
	Solution *s = new Solution();
	//cout << s->longestPalindrome("cbbd");
	cout << s->longestPalindrome("forgeeksskeegfor");
	return 0;
}