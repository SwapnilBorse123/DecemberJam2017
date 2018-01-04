#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
		int charToInt(char c){
			if(c == 'I'){
				return 1;
			}
			if(c == 'V'){
				return 5;
			}
			if(c == 'X'){
				return 10;
			}
			if(c == 'L'){
				return 50;
			}
			if(c == 'C'){
				return 100;
			}
			if(c == 'D'){
				return 500;
			}
			if(c == 'M'){
				return 1000;
			}
		}

	    int romanToInt(string s) {
	    	int resultInt = 0;
	        for (int i = 0; i < s.length(); i++){
	        	int num1 = charToInt(s[i]);
	        	if(i+1 < s.length()){
	        		int num2 = charToInt(s[i + 1]);
	        		if(num1 >= num2){
	        			resultInt = resultInt + num1;
	        		}else{
	        			resultInt = resultInt + (num2 - num1);
	        			i++;
	        		}
	        	}else{
	        		resultInt = resultInt + charToInt(s[i]);
	        	}
	        }
	        return resultInt;
	    }
};

int main(){
	Solution *s = new Solution();
	cout << s->romanToInt("XLVII") << endl;
	return 0;
}