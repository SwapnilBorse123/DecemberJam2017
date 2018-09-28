/*
author: Swapnil Borse
date: 19th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> outputVec;
		if(n <= 0){
		outputVec.push_back("");
			return outputVec;
		}
		
		char arr[MAX];
		util(n, 0, 0, 0, arr, outputVec);
        return outputVec;
    }

    void util(int n, int open, int close, int pos, char* arr, vector<string> &outputVec){
    	if(close == n){
    		string output = arr;
    		outputVec.push_back(output);
    		//cout << "Adding: " << output << " to the vector!\n";
    		return;
    	}else{
    		if(open > close){
	    		arr[pos] = ')';
	    		//cout << "1: util -> " << n << "," << open << "," << close+1 << ",'" << arr << "'" << endl;
	    		util(n, open, close+1, pos+1, arr, outputVec);
	    	}
	    	if(open < n){
	    		arr[pos] = '(';
	    		//cout << "2: util -> " << n << "," << open+1 << "," << close << ",'" << arr << "'" << endl;
	    		util(n, open+1, close, pos+1, arr, outputVec);
	    	}
    	}
    }
};

int main(){
	Solution s;
	vector<string> v = s.generateParenthesis(4);
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;;
	}
	return 0;
}