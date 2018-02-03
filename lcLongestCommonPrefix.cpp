/*
author: Swapnil B
date: 02/03/2018
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {

public:
    
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0){ // empty vector
    		return "";
    	}

        return lcpRec(strs, 0, strs.size()-1);
    }

    string lcpRec(vector<string>& strs, int low, int high){
    	//cout << "(" << low << "," << high << ")" << endl;
    	int mid = (low + high) / 2;
    	if(low == high){
    		return strs[low];
    	}else if(high - low == 1){
    		string temp = lcp(strs[low],strs[high]);
    		//cout << "returning:1 for:(" <<low << "," << high << ") " << temp << endl;
    		return temp;
    	}else{
    		string temp = lcp(lcpRec(strs, low, mid), lcpRec(strs, mid+1, high));
    		//cout << "returning:2 for:(" <<low << "," << high << ") " << temp << endl;
    		return temp;
    	}
    }

    string lcp(string s1, string s2){
    	if(s1 == s2) return s1;
    	int len = s1.length() < s2.length() ? s1.length() : s2.length();
    	for(int i = 0; i < len; ++i){
    		if(s1[i] != s2[i]){
    			if(i == 0) return "";
    			//cout << "returning:3 " << s1.substr(0,i) << endl;
    			//cout << "lcp param: " << s1 << " " << s2 << " ret: " << s1.substr(0,i) << endl;
    			return s1.substr(0,i);
    		}
    	}
    	//cout << "lcp param: " << s1 << " " << s2 << " ret: " << s1 << endl;
    	return s1.length() < s2.length() ? s1 : s2;
    }

};

int main(){
	vector<std::string> v;
	v.push_back("apprle");
	v.push_back("appre");
	v.push_back("appril");
	v.push_back("approise");
	v.push_back("apprlause");
	Solution *s =  new Solution();
	cout << s->longestCommonPrefix(v) << endl;
	delete(s);
	return 0;
}