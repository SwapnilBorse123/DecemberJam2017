#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	int inputNum = x;
        if(x < 0){ // number is negative, not a palindrome
        	return false;
        }else{
        	int _revNum = 0, revNum = 0;
	        while(x != 0){
	            int thisDigit = x % 10;
	            revNum = (revNum * 10) + thisDigit;
	            
	            if((revNum - thisDigit) / 10 != _revNum){
	                return false;
	            }
	            
	            _revNum  = revNum;
	            x = x/10;
	        }
	        return (inputNum == revNum) ? true : false;
	    }
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->isPalindrome(-1);
	return 0;
}

/*
while(x >= 0){
        		int numZeros = (int)log10(x);
        		int firstDigit = x / ((int)(pow(10,numZeros))); //
        		int lastDigit = x % 10;
        		cout << numZeros << endl;
        		cout << firstDigit << endl;
        		cout << lastDigit << endl;
        		if(firstDigit != lastDigit){
        			return false;
        		}
        		x = x - pow(10, numZeros);
        		x = x / 10;
        		cout << "new x: " << x << endl;
        	}
*/