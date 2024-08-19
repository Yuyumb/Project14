#include "Trie.h"
#include <cstring>

TrieNode::TrieNode()
{
	isEndOfWord = false;
	memset(children, 0, sizeof(children));
}

Trie::Trie()
{
	root = new TrieNode();
}

void Trie::insert(const string& word)
{
	TrieNode* node = root;
	for (char ch : word)
	{
		int index = ch - 'a';
		if (node->children[index] == nullptr)
		{
			node->children[index] = new TrieNode();
		}
		node = node->children[index];
	}
	node->isEndOfWord = true;
}

void Trie::findWordsWithPrefix(TrieNode* node, const string& prefix, vector<string>& results) const {
	if (node->isEndOfWord) {
		results.push_back(prefix);
	}
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (node->children[i] != nullptr) {
			findWordsWithPrefix(node->children[i], prefix + char('a' + i), results);
		}
	}
}

vector<string> Trie::autoComplete(const string& prefix) const {
	vector<string> results;
	TrieNode* node = root;
	for (char ch : prefix) {
		int index = ch - 'a';
		if (node->children[index] == nullptr) {
			return results;
		}
		node = node->children[index];
	}
	findWordsWithPrefix(node, prefix, results);
	return results;
}