#pragma once
#include <vector>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
	TrieNode();
};

class Trie
{
private:
	TrieNode* root;
	void findWordsWithPrefix(TrieNode* node, const string& prefix, vector<string>& results) const;
public:
	Trie();
	void insert(const string& word);
	vector<string> autoComplete(const string& prefix) const;
};