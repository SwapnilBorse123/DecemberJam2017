/*
author: Swapnil Borse
date: 4th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

#define CHARSET 127

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash_s[CHARSET], hash_t[CHARSET];
        std::fill_n(hash_s, CHARSET, -1);
        std::fill_n(hash_t, CHARSET, -1);
        //for(int i = 0; i < CHARSET; ++i){
        //	cout << hash[i] << " ";
        //}
        for(int i = 0; i < s.length(); ++i){
        	if(hash_s[(int)s[i]] == -1){ // still unmapped to a character from t
        		if(hash_t[(int)t[i]] != -1){
        			return false;
        		}
        		hash_s[(int)s[i]] = (int)t[i];
        		hash_t[(int)t[i]] = (int)s[i];
        	    //cout << "mapping: " << s[i] << " to " << t[i] << "\n";
        	}else if(hash_s[(int)s[i]] != -1 && hash_s[(int)s[i]] != (int)t[i]){ // char from t not mapping to same char from s
                //cout << "ret 1\n";
        		return false;
        	}else if(hash_t[(int)t[i]] != -1 && hash_t[(int)t[i]] != (int)s[i]){ // char from s not mapping to same char from t
                //cout << "ret 2\n";
        		return false;
        	}
        }
        return true;
    }
};

int main(){
	Solution s;
	cout << s.isIsomorphic("ab", "aa") << "\n";
	return 0;
}