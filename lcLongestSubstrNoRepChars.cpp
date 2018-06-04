// Date: 22/12/2017
// Website: Leetcode
// Problem: Longest substring without repeating characters

#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int lengthOfLongestSubstring(char* s);

int main(){
	char *inputStr = (char*)malloc(sizeof(char) * MAX);
	scanf(" %[^\n\t]s",inputStr);
	//printf("%s\n", inputStr);
	lengthOfLongestSubstring(inputStr);
	free(inputStr);
	return 0;
}

int lengthOfLongestSubstring(char* s) {
    printf("%s",s);
    return 0;
}