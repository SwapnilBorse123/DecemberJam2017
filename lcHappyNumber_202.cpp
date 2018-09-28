/*
author: Swapnil Borse
date: 7th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int temp = 0, iterations = 0;
        while(temp != 1){
        	while(n != 0){
        		temp = temp + ((n%10) * (n%10));
        		n = n / 10;
        	}
        	if(temp == 1){
        		return true;
        	}
        	n = temp;
        	//cout << "new value of n: " << n << "\n";
        	temp = 0;
        	//iterations++;
        	//if(iterations == 10){
        	//	exit(0);
        	//}
        }
    	return false;
    }
};

int main(){
	Solution s;
	cout << s.isHappy(15) << "\n";
	return 0;
}