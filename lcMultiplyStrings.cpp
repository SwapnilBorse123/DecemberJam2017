
/**
@author SwapnilB
@date 01/03/2018
*/


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string add(string num1, string num2) {
		if(num1.size() == 0){
			return num2;
		}else if(num2.size() == 0){
			return num1;
		}

		int len1 = num1.length();
		int len2 = num2.length();

		int maxLen = len1 > len2 ? len1 : len2;

		//std::reverse(num1.begin(), num1.end());
		//std::reverse(num2.begin(), num2.end());
		
		//cout << "Reversed1: " << num1 << endl;
		//cout << "Reversed2: " << num2 << endl;
		string result = "";

		int sum = 0, carry = 0, it1 = 0, it2 = 0;
		for(int i = 0; i < maxLen; ++i){
			if(it1 < len1 && it2 < len2){
				sum = (((int)num1[it1] - '0') + ((int)num2[it2] - '0') + carry) % 10;
				carry = (((int)num1[it1] - '0') + ((int)num2[it2] - '0') + carry) / 10;
				it1++; it2++;
			}else if(it1 < len1 && it2 >= len2){ // second number out of range
				sum = (((int)num1[it1] - '0') + carry) % 10;
				carry = (((int)num1[it1] - '0') + carry) / 10;
				it1++;
			}else if(it1 >= len1 && it2 < len2){ // first number out of range
				sum = (((int)num2[it2] - '0') + carry) % 10;
				carry = (((int)num2[it2] - '0') + carry) / 10;
				it2++;
			}
			result += ((char)sum + '0');
		}
		if(carry != 0){
			result += ((char)carry + '0');
		}
		//std::reverse(result.begin(), result.end());
		return result;
	}

	string getZerosString(int num){
		string result = "";
		for(int i = 0; i < num; ++i){
			result += '0';
		}
		return result;
	}

    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0"){
    		return "0";
    	}
    	//return add(num1, num2);
    	std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());

    	int len2 = num2.length();
    	int len1 = num1.length();

    	string tempResult = "";
    	string finalResult = "";

    	for(int i = 0; i < len2; ++i){ // iterator for second number
    		int product = 0, result = 0, carry = 0;
    		for(int j = 0; j < len1; ++j){ // iterator for first number
				product = ((int)num2[i]-'0') * ((int)num1[j]-'0') + carry;
				result = product % 10;
				carry = product / 10;
				tempResult += ((char)result + '0');
    		}
    		if(carry != 0){
    			tempResult += ((char)carry + '0');
    		}
    		tempResult = getZerosString(i) + tempResult;
    		finalResult = add(finalResult, tempResult);
    		//cout << "T: " << tempResult << endl;
    		//cout << "F: " << finalResult << endl;
    		tempResult = "";
    	}
    	std::reverse(finalResult.begin(), finalResult.end());
    	return finalResult;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->multiply("654154154151454545415415454","63516561563156316545145146514654") << endl;
	//cout << s->add("8997","00206");
	//cout << s->getZerosString(5);
	return 0;
}