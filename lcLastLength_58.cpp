/*
author: Swapnil Borse
date: 10th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   int lengthOfLastWord(string s) {
   		unsigned int lenLast = 0;
   		unsigned int sInd = s.length()-1;
   		if(s[sInd] == ' '){ while(sInd >= 0 && s[sInd] == ' '){ sInd--;} }
		while(sInd >= 0 && s[sInd] != ' '){
			sInd--;
			lenLast++;
		} 
        return lenLast;
    }
};

int main(){
	Solution s;
	cout << s.lengthOfLastWord("Hello df  ") << endl;
	return 0;
}