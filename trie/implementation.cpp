#include <bits/stdc++.h>
using namespace std;

class trieNode {
public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class trie {
public:
    trieNode* root;

    trie() {
        root = new trieNode('\0');
    }  

    void insertUtil(trieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption: the word will be in caps
        int index = word[0] - 'A';
        trieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        trieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    trie* t = new trie();

    t->insertWord("ACD");

    cout << "Present or not: " << t->searchWord("CD") << endl;
    return 0;
}
