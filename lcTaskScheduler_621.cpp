/*
author: Swapnil Borse
date: 17th August 2018
*/

#include <bits/stdc++.h>

#define ALPHABET 26

using namespace std;



class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        int countArr[ALPHABET];
        std::fill_n(countArr, ALPHABET, 0);

        //std::cout << "Tasks count before hashing: " << "\n";
		//for(int i = 0; i < ALPHABET; ++i){
        // 	std::cout << (char)(i+'A') << countArr[i] << " ";
        //}

        for(int i = 0; i < tasks.size(); ++i){
        	countArr[tasks[i]-'A']++;
        }

        //std::cout << "\nTasks count after hashing: " << "\n";
		//for(int i = 0; i < ALPHABET; ++i){
        //	std::cout << (char)(i+'A') << countArr[i] << " ";
        //}

        int nextDueArr[ALPHABET];
        std::fill_n(nextDueArr, ALPHABET, 0);

        int intervals = 0, round = 0;

        std::cout << "\nScheduling started.\n";
        while(!ifAllZero(countArr, ALPHABET)){
        	int currentTask = getTaskToSchedule(countArr, nextDueArr, ALPHABET);
        	if(currentTask != -1){ // leaving 'idle' interval
        		nextDueArr[currentTask] = n;
        		std::cout << "currentTask: " << (char)(currentTask + 'A') << " time due: " << nextDueArr[currentTask] << "\n";
        		decreaseDueTime(countArr, nextDueArr, ALPHABET, currentTask);
        	}else{
        		std::cout << "currentTask: Idle\n";
        		decreaseDueTime(countArr, nextDueArr, ALPHABET, -1);
        	}
        	intervals++;
        	//round++;
        	//if(round > 10){
        	//	exit(EXIT_FAILURE);
        	//}
        }
        std::cout << "\nRequired # of intervals for Scheduling all tasks: " << intervals;
        return intervals;
    }

    void decreaseDueTime(int *countArr, int *nextDueArr, int len, int currentTask){
    	std::cout << "decreased time for: ";
    	if(currentTask != -1){
	    	for(int i = 0; i < len; ++i){
	    		if(i != currentTask && nextDueArr[i] != 0 && countArr[i] != 0){
	    			nextDueArr[i]--;
	    			std::cout << (char)(i+'A') << "->" << nextDueArr[i] << " ";
	    		}
	    	}
    	}else{
    		for(int i = 0; i < len; ++i){
	    		if(nextDueArr[i] != 0 && countArr[i] != 0){
	    			nextDueArr[i]--;
	    			std::cout << (char)(i+'A') << "->" << nextDueArr[i] << " ";
	    		}
	    	}
    	}
    	std::cout << "\n";
    }

    int getTaskToSchedule(int *countArr, int *nextDueArr, int len){
    	int currentMax = 0;
    	for(int i = 0; i < len; ++i){
    		if(currentMax < countArr[i]){
    			currentMax = countArr[i];
    		}
    	}
    	std::cout << "\nCurrent max is: " << currentMax << "\n";
    	for(int i = 0; i < len; ++i){
    		if(countArr[i] == currentMax && nextDueArr[i] == 0){
    			countArr[i]--;
    			return i;
    		}
    	}
    	return -1;
    }

    bool ifAllZero(int* arr, int len){
		bool allZero = true;
		for(int i = 0; i < len; ++i){
			if(arr[i] > 0){
				allZero = false;
			}
		}
		return allZero;
	}
	
	/*
	int leastInterval(vector<char>& tasks, int n) {
		int max = 0, uniqueTasks = 0;
		if(n == 0){
			return tasks.size();
		}
		int countArr[ALPHABET];
        std::fill_n(countArr, ALPHABET, 0);
        for(int i = 0; i < tasks.size(); ++i){
        	if(countArr[tasks[i]-'A'] == 0){
        		uniqueTasks++;
        	}
        	countArr[tasks[i]-'A']++;
        	if(countArr[tasks[i]-'A'] > max){
        		max = countArr[tasks[i]-'A'];
        	}
        }
        int extra_slots = 0;
        for(int i = 0; i < 26; ++i){
        	if(countArr[i] == max){
        		extra_slots++;
        	}
        }
        return extra_slots + (max-1) * (n+1);
	}
	*/
};

int main(){
	Solution s;
	std::vector<char> myVec = {'A','A','A','A','B','B','B','B', 'C', 'C', 'D'};
	cout << "\nRequired Intervals: " <<  s.leastInterval(myVec,2) << "\n";
	return 0;
}