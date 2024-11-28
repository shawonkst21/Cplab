#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct trieNode {
        bool end = false;
        trieNode* children[26];
        int count = 0; // To count occurrences of the pattern
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }

    void insert(const string& word) {
        trieNode* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == NULL) {
                temp->children[ch - 'a'] = getNode();
            }
            temp = temp->children[ch - 'a'];
        }
        temp->end = true; // Mark the end of the word
        temp->count = 0;  // Initialize count
    }

    // Traverse the text and count occurrences of all patterns
    void searchText(const string& text, unordered_map<string, int>& patternCount) {
        for (int i = 0; i < text.size(); i++) {
            trieNode* temp = root;
            string current = ""; // To build the pattern being checked
            for (int j = i; j < text.size(); j++) {
                char ch = text[j];
                if (temp->children[ch - 'a'] == NULL) break;
                temp = temp->children[ch - 'a'];
                current += ch;
                if (temp->end) {
                    patternCount[current]++;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text;
    cin >> text;

    int k;
    cin >> k;

    Trie trie;
    vector<string> patterns(k);
    unordered_map<string, int> patternCount;

    // Insert all patterns into the Trie
    for (int i = 0; i < k; i++) {
        cin >> patterns[i];
        trie.insert(patterns[i]);
        patternCount[patterns[i]] = 0; // Initialize pattern count
    }

    // Search the text and count occurrences
    trie.searchText(text, patternCount);

    // Output results
    for (const string& pattern : patterns) {
        cout << patternCount[pattern] << endl;
    }

    return 0;
}
