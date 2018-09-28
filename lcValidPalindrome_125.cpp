/*
author: Swapnil Borse
date: 23rd August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
    	string str = "", rStr = "";
    	for(int i = 0; i < s.length(); ++i){
    		if(s[i] >= 65 && s[i] <= 90){
    			str += (s[i]-'A')+'a';
    		}else if(s[i] >= 97 && s[i] <= 122){
    			str += s[i];
    		}else if(s[i] >= 48 && s[i] <= 57){
    			str += s[i];
    		}
    	}
    	rStr = str;
    	std::reverse(rStr.begin(), rStr.end());
    	if(str == rStr){
    		return true;
    	}else{
    		return false;
    	}
    }
};

int main(){
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal: Panamaa");
	return 0;
}