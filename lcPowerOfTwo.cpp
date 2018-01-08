#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if(n < 0){
    		return false;
    	}
    	int count = 0;
    	for(int i = 0; i < (sizeof(int) * 8) - 1; ++i){
    		if(n & (1 << i)){
    			count++;
    		}
    	}
    	return count == 1 ? false : true;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->isPowerOfTwo(1024) << endl;
	return 0;
}