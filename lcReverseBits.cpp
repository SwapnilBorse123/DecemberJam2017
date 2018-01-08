#include<bits/stdc++.h>
#include<cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; ++i){
    		if(n & (1 << i)){
    			result |= 1 << (31 - i); 
    		}        
        }
        return result;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->reverseBits(43261596);
	return 0;
}