/*
author: Swapnil Borse
date: 18th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n){
    	int count = 1;
    	string previousString = "1";
    	char currentChar;
    	int index;
    	int currentCharCount = 0;
    	string resultString = "";
    	for(int i = 0; i < n-1; ++i){
    		//std::cout << "Result string at " << i << "th iteration: " << resultString << "\n";

    		currentChar = previousString[0];
    		index = 0;
    		while(index < previousString.length()){
	    		while(previousString[index] == currentChar){
	    			currentCharCount++;
	    			index++;
	    		}
	    		resultString += (char)(currentCharCount + '0');
	    		resultString += (char)(currentChar);
	    		//std::cout << "appending: " << (char)(currentCharCount + '0') << (char)currentChar << "\n";
	    		//std::cout << "result string is: " << resultString << "\n";
	    		currentChar = previousString[index];
	    		currentCharCount = 0;
    		}
    		previousString = resultString;
    		//std::cout << "\n\n" << resultString;
    		resultString = "";
    	}
    	return previousString;
    }
};

int main(){
	Solution s;
	cout << s.countAndSay(10) << "\n";
	return 0;
}