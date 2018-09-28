/*
author: Swapnil Borse
date: 2nd September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
        int counter = 0;
        for(int i = 5; n/i >= 1; i = i*5){
        	counter = counter + n/i;
        }
        return counter;
    }
};

int main(){
	Solution s;
	cout << s.trailingZeroes(1808548329) << "\n";

	return 0;
}