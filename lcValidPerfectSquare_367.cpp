/*
author: Swapnil Borse
date: 4th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*bool isPerfectSquare(int num) {
    	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
    	int earlier_divisor_count = 0;
    	int isPrime = 1;
        for(int i = 0; i < 100; ++i){
        	if(num % primes[i] == 0){
        		cout << "dividing by: " << primes[i] << "\n";
        		num = num / primes[i];
        		earlier_divisor_count += 1;
        		if(num == 1){
        			cout << "num is 1, breaking loop.\n";
        			break;
        		}
        		while(num % primes[i] == 0){
        			num = num / primes[i];
        			earlier_divisor_count += 1;
        			cout << "dividing by: " << primes[i] << " again.\n";
        			if(num == 1){
        				cout << "num is 1, breaking inner loop.\n";
        				break;
        			}
        		}
        		if(earlier_divisor_count <= 1 || earlier_divisor_count % 2 != 0){
	        		cout << "ret false 1.\n";
	        		return false;
        		}else{
        			earlier_divisor_count = 0;
        		}
        		isPrime = 0;
        	}
        }
        if(isPrime){
        	return false;
        }
        return true;
    }*/


	// Much better method
	bool isPerfectSquare(unsigned int num){
		unsigned int sum = 0;
        unsigned int i = 0;
		for(i = 1; sum < num; i=i+2){
			sum += i;
		}
        std::cout << "Sum after for loop: " + sum;
		if(sum > num){
			return false;
		}
		return true;
	}

};

int main(){
	Solution s;
	cout << s.isPerfectSquare(25) << "\n\n";
	return 0;
}