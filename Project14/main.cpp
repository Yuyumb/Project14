#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
	Trie trie;

	vector<string> words = { "call", "cat", "cult", "run", "rut", "dog", "dot", "dove", "duck", "zebra", "a", "answer", "hero", "heroplane", "the" };
	for (const string& word : words)
	{
		trie.insert(word);
	}
	string prefix;
    while (true) {
        cout << "Введите префикс (или 'exit' для выхода): ";
        cin >> prefix;

        if (prefix == "exit") {
            break;
        }

        vector<string> suggestions = trie.autoComplete(prefix);

        if (suggestions.empty()) {
            cout << "Нет подходящих слов." << endl;
        }
        else {
            cout << "Подходящие слова: ";
            for (const string& word : suggestions) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}