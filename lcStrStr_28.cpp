/*
author: Swapnil Borse
date: 10th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
	int calculateHash(string s){
		int hash = 0;
		for(int i = 0; i < s.length(); ++i){
			hash += s[i] - 'A';
		}
		return hash;
	}

	bool matchByLetter(string needle, string haystack){
		cout << needle << " : " << haystack << endl;
		return needle.compare(haystack) == 0 ? true : false;
		/*for(int i = 0; i < needle.length(); ++i){
			if(needle[i] != haystack[i]){ 
				cout<<"false\n"; 
				return false; 
			}
			cout << "true\n";
			return true;
		}*/
	}

    int strStr(string haystack, string needle) {
    	
    	if(needle == "" && haystack == "") return 0;
        else if(haystack != "" && needle == "") return 0;
        else if(needle == "" || haystack == "") return -1;
        else if(needle.length() > haystack.length()) return -1;
    	
    	int needleHash = calculateHash(needle);
    	int low = 0, high = needle.length()-1;

    	int hayHash = calculateHash(haystack.substr(0, needle.length()));
    	for (int high = needle.length()-1; high < haystack.length();){ // slide window over complete haystack
    		//cout << "low: " << low << " high: " << high << " for this iteration\n";
    		if(hayHash == needleHash && matchByLetter(needle.substr(0, needle.length()), haystack.substr(low, needle.length()))){
    			//cout << "returning: " << low << "\n";
    			return low;
    			break;
    		}
    		hayHash -= haystack[low];
    		++low; ++high; // moving the sliding window
    		hayHash += haystack[high];
    	}

    	return -1;
    }

};

int main(){
	Solution s;
	cout << s.strStr("babbbbbabb", "bbab") << endl;
	return 0;
}