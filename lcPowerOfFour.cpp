#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0){
        	return false;
        }
      	if(num & (num - 1)){ // not a power of two
      		return false;
      	}
      	if((num - 1) % 3 != 0){
      		return false;
      	}
      	return true;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->isPowerOfFour(10) << endl;
	return 0;
}