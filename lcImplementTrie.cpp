#include<bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode{
	struct TrieNode* alphabets[ALPHABET_SIZE];
	bool isValidWord;

	TrieNode(){
		for(int i = 0; i < ALPHABET_SIZE; ++i){
			alphabets[i] = NULL;
		}
		isValidWord = false;
	}
};

class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode* head;
    struct TrieNode* tempHead;

    Trie() {
    	head = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    	for(int i = 0; i < ALPHABET_SIZE; ++i){
    		head->alphabets[i] = NULL;
    	}
    	head->isValidWord = false;
    	tempHead = head;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	tempHead = head;
        for(int i = 0; i < word.length(); ++i){
        	if(tempHead->alphabets[word[i] - 'a'] == NULL){
        		struct TrieNode* temp = (struct TrieNode*)malloc(sizeof(struct TrieNode));
        		//cout << "temp value: " << temp->isValidWord << endl;
        		if(i == word.length() - 1){
        			temp->isValidWord = true;
        			//cout << "valid for: " << word[i] << " ";
        		}
        		tempHead->alphabets[word[i] - 'a'] = temp;
        		//cout << "inserted: " << word[i] << " ";
        		tempHead = temp;//tempHead->alphabets[word[i] - 'a'];
        	}else{
        		if(i == word.length() - 1){
        			tempHead->isValidWord = true;
        			cout << "valid for: " << word[i] << endl;
        		}
        		tempHead = tempHead->alphabets[word[i] - 'a'];
        	}
        }
        tempHead = head;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	tempHead = head;
        for(int i = 0; i < word.length(); ++i){
        	if(tempHead->alphabets[word[i] - 'a'] == NULL){
        		return false;
        	}else if(i == word.length() - 1){
        		if(tempHead != NULL){
        			if(tempHead->isValidWord == true){
        				return true;
        			}
        			//cout << "found: " << word[i] << endl;
        		}
        	}else{
        		//cout << "found: " << word[i] << endl;
        		//cout << "current char: " << word[i] << " ";
        		tempHead = tempHead->alphabets[word[i] - 'a'];
        	}
        }
        tempHead = head;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tempHead = head;
        for(int i = 0; i < prefix.length(); ++i){
        	if(tempHead->alphabets[prefix[i] - 'a'] == NULL){
        		return false;
        	}else{
        		tempHead = tempHead->alphabets[prefix[i] - 'a'];
        	}
        }
        tempHead = head;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(){
	Trie *trieObj = new Trie();

	//cout << trieObj->head->isValidWord << endl;

	/*trieObj->insert("abc");
	cout << "string inserted successfully!" << endl;
	cout << trieObj->search("abc") << endl;

	trieObj->insert("swapnil");
	cout << "string inserted successfully!" << endl;
	cout << trieObj->search("swap") << endl;
	cout << trieObj->search("swapnil") << endl;
	cout << trieObj->search("swapnila") << endl;
	cout << trieObj->startsWith("sw") << endl;
	trieObj->insert("ktm");
	cout << trieObj->startsWith("ktm") << endl;
	cout << trieObj->startsWith("ab") << endl;
	cout << trieObj->startsWith("a") << endl;*/

	
	trieObj->insert("abc");
	cout << trieObj->search("abc") << endl;
	cout << trieObj->search("ab") << endl;
	trieObj->insert("ab");
	cout << trieObj->search("ab") << endl;
	trieObj->insert("ab");
	cout << trieObj->search("ab") << endl;

	delete(trieObj->head);
	delete(trieObj);

	return 0;
}