/*
author: Swapnil Borse
date: 11th Oct
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if(n == 0){
            result.push_back(0);
            return result;
        } else if(n == 1){
            result.push_back(0);
            result.push_back(1);
            return result;
        } else{
            int* hash = (int*)malloc(sizeof(int) * pow(2,n));
            int* arr = (int*)malloc(sizeof(int) * pow(2,n));
            memset(hash, 0, n);
            hash[0] = 1; arr[0] = 0;
            util(arr, hash, n, 1, 0, 1, 0);
            //cout << "\nPrinting arr:";
            for(int i = 0; i < pow(2,n); ++i){
                //cout << arr[i] << " ";
                result.push_back(arr[i]);
            }
            memset(hash, 0, n);
            return result;
        }
    }
    
    void util(int *arr, int* hash, int n, int arIdx, int currVal, int count, int lastMod){
        if(count == pow(2,n)){
            return;
        }
        for(int i = 0; i < n; ++i){
            if(i == lastMod){
                continue;
            }
            //currVal ^= (1 << i);
            //cout << currVal << " ";
            if(hash[currVal ^ (1<<i)] == 0){
            //cout << "init: " << currVal << " changing bit " << i << "\n";
                currVal ^= (1 << i);
                hash[currVal] = 1;
                arr[arIdx] = currVal;
                count += 1;
            }else{
                continue;
            }
            util(arr, hash, n, arIdx+1, currVal, count, i);
            return;
        }
    }
};