#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(n < 0){
    		return 0;
    	}else if(n == 1){
    		return 1;
    	}else if(n == 2){
    		return 2;
    	}
        int count = 2;
        int term1 = 1, term2 = 2, res = 0;
        while(count != n){
        	res = term1 + term2;
        	term1 = term2;
        	term2 = res;
        	count++;
        }
        return res;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->climbStairs(25) << endl;
	return 0;
}