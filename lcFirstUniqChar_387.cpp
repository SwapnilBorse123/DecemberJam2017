/*
author: Swapnil Borse
date: 17th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
    	//int* hash = (int*) malloc(sizeof(int) * 26);
    	int* hash = new int[26];
    	memset(hash, 0, 26);
    	for (int i = 0; i < s.length(); ++i){
    		hash[s[i] - 'a']++;
    	}
    	/*
    	for (int i = 0; i < 26; ++i){
    		cout << (char)(i + 'a') << ":" << hash[s[i] - 'a'] << " ";
    	}
		*/
    	for (int i = 0; i < s.length(); ++i){
    		if(hash[s[i] - 'a'] == 1) {
    		  return i;
    		}
    	}
    	memset(hash, 0, 26);
    	free(hash);
    	return -1;
    }
};

int main(){
	Solution s;
	cout << s.firstUniqChar("itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb") << endl;

	return 0;
}